#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 定义文法结构：非终结符 -> 产生式右部列表
using Grammar = unordered_map<string, vector<string>>;

// 读取文法文件
Grammar readGrammar(const string& filename) {
    Grammar grammar;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return grammar;
    }

    string line;
    while (getline(file, line)) {
        // 跳过空行
        if (line.empty()) continue;

        // 分割非终结符和产生式右部
        size_t arrowPos = line.find("->");
        if (arrowPos == string::npos) continue;

        string left = line.substr(0, arrowPos);
        left.erase(remove_if(left.begin(), left.end(), ::isspace), left.end());

        string rightStr = line.substr(arrowPos + 2);
        vector<string> rightParts;
        stringstream ss(rightStr);
        string part;

        // 分割多个产生式
        while (getline(ss, part, '|')) {
            part.erase(remove_if(part.begin(), part.end(), ::isspace), part.end());
            if (!part.empty()) rightParts.push_back(part);
        }

        if (!rightParts.empty()) grammar[left] = rightParts;
    }

    return grammar;
}

// 检测左递归
bool hasLeftRecursion(const Grammar& grammar) {
    for (const auto& pair : grammar) {
        const string& nonTerminal = pair.first;
        const vector<string>& rules = pair.second;
        for (const string& rule : rules) {
            if (!rule.empty() && rule[0] == nonTerminal[0]) {
                return true;
            }
        }
    }
    return false;
}

// 计算FIRST集
unordered_set<char> computeFirst(const Grammar& grammar, const string& symbol) {
    unordered_set<char> firstSet;

    // 如果是终结符或空串
    if (grammar.find(symbol) == grammar.end()) {
        firstSet.insert(symbol[0]);
        return firstSet;
    }

    // 对于非终结符，处理其所有产生式
    for (const string& rule : grammar.at(symbol)) {
        if (rule == "~") {
            firstSet.insert('~');
            continue;
        }

        bool allEpsilon = true;
        for (char c : rule) {
            string charStr(1, c);
            unordered_set<char> charFirst = computeFirst(grammar, charStr);

            // 添加除了空串之外的所有符号
            for (char symbol : charFirst) {
                if (symbol != '~') firstSet.insert(symbol);
            }

            // 如果当前符号的FIRST集不包含空串，则停止处理后续符号
            if (charFirst.find('~') == charFirst.end()) {
                allEpsilon = false;
                break;
            }
        }

        // 如果所有符号的FIRST集都包含空串，则添加空串
        if (allEpsilon) firstSet.insert('~');
    }

    return firstSet;
}

// 计算FOLLOW集
unordered_set<char> computeFollow(const Grammar& grammar, const string& nonTerminal,
    const string& startSymbol,
    unordered_map<string, unordered_set<char>>& computedFollows) {
    // 如果已经计算过，直接返回
    if (computedFollows.find(nonTerminal) != computedFollows.end()) {
        return computedFollows[nonTerminal];
    }

    unordered_set<char> followSet;

    // 开始符号的FOLLOW集包含$
    if (nonTerminal == startSymbol) {
        followSet.insert('$');
    }

    // 遍历所有产生式，查找该非终结符的出现位置
    for (const auto& pair : grammar) {
        const string& left = pair.first;
        const vector<string>& rules = pair.second;

        for (const string& rule : rules) {
            size_t pos = 0;
            while ((pos = rule.find(nonTerminal, pos)) != string::npos) {
                // 如果不是产生式的最后一个符号
                if (pos + nonTerminal.length() < rule.length()) {
                    string nextSymbol = string(1, rule[pos + nonTerminal.length()]);
                    unordered_set<char> nextFirst = computeFirst(grammar, nextSymbol);

                    // 添加FIRST(nextSymbol)中除了空串之外的所有符号
                    for (char symbol : nextFirst) {
                        if (symbol != '~') followSet.insert(symbol);
                    }

                    // 如果FIRST(nextSymbol)包含空串，添加左部非终结符的FOLLOW集
                    if (nextFirst.find('~') != nextFirst.end()) {
                        if (left != nonTerminal) {
                            unordered_set<char> leftFollow = computeFollow(grammar, left, startSymbol, computedFollows);
                            followSet.insert(leftFollow.begin(), leftFollow.end());
                        }
                    }
                }
                // 如果是产生式的最后一个符号，添加左部非终结符的FOLLOW集
                else if (left != nonTerminal) {
                    unordered_set<char> leftFollow = computeFollow(grammar, left, startSymbol, computedFollows);
                    followSet.insert(leftFollow.begin(), leftFollow.end());
                }
                pos++;
            }
        }
    }

    // 缓存计算结果
    computedFollows[nonTerminal] = followSet;
    return followSet;
}

// 检查文法是否是LL(1)
string checkLL1Grammar(const Grammar& grammar) {
    // 条件1: 检查左递归
    if (hasLeftRecursion(grammar)) {
        return "mismatch condition 1";
    }

    // 获取开始符号
    if (grammar.empty()) return "mismatch condition 1";
    string startSymbol = grammar.begin()->first;

    // 条件2: 检查相同非终结符的产生式的FIRST集是否相交
    for (const auto& pair : grammar) {
        const string& nonTerminal = pair.first;
        const vector<string>& rules = pair.second;

        // 计算每个产生式的FIRST集
        vector<unordered_set<char>> firstSets;
        for (const string& rule : rules) {
            unordered_set<char> firstSet;
            bool allEpsilon = true;

            for (char c : rule) {
                string charStr(1, c);
                unordered_set<char> charFirst = computeFirst(grammar, charStr);
                firstSet.insert(charFirst.begin(), charFirst.end());
                firstSet.erase('~');

                if (charFirst.find('~') == charFirst.end()) {
                    allEpsilon = false;
                    break;
                }
            }

            if (allEpsilon) firstSet.insert('~');
            firstSets.push_back(firstSet);
        }

        // 检查所有FIRST集对是否相交
        for (size_t i = 0; i < firstSets.size(); ++i) {
            for (size_t j = i + 1; j < firstSets.size(); ++j) {
                for (char symbol : firstSets[i]) {
                    if (firstSets[j].find(symbol) != firstSets[j].end()) {
                        return "mismatch condition 2";
                    }
                }
            }
        }
    }

    // 条件3: 检查含有空串产生式的非终结符，其FIRST集与FOLLOW集是否相交
    unordered_map<string, unordered_set<char>> computedFollows;
    for (const auto& pair : grammar) {
        const string& nonTerminal = pair.first;
        const vector<string>& rules = pair.second;

        // 检查是否有产生式为空串
        bool hasEpsilon = false;
        for (const string& rule : rules) {
            if (rule == "~") {
                hasEpsilon = true;
                break;
            }
        }

        if (hasEpsilon) {
            // 计算FIRST集
            unordered_set<char> firstSet = computeFirst(grammar, nonTerminal);
            // 计算FOLLOW集
            unordered_set<char> followSet = computeFollow(grammar, nonTerminal, startSymbol, computedFollows);

            // 检查交集
            for (char symbol : firstSet) {
                if (symbol == '~') continue;
                if (followSet.find(symbol) != followSet.end()) {
                    return "mismatch condition 3";
                }
            }
        }
    }

    // 如果所有条件都满足
    return "The grammar is LL(1)";
}

int main() {
    // 读取文法
    Grammar grammar = readGrammar("testfile.txt");

    // 检查LL(1)条件
    string result = checkLL1Grammar(grammar);

    // 输出结果
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << result << endl;
        outFile.close();
    }
    else {
        cerr << "无法打开输出文件" << endl;
    }

    return 0;
}
