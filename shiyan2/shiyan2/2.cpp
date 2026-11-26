#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;

// 文法规则结构体
struct Production {
    char left;   // 左部非终结符
    string right; // 右部符号串
    Production(char l, string r) : left(l), right(r) {}
};

class LL1Parser {
private:
    vector<Production> productions; // 所有产生式
    set<char> nonTerminals;         // 非终结符集合
    set<char> terminals;            // 终结符集合
    map<char, set<char>> first;     // FIRST集
    map<char, set<char>> follow;    // FOLLOW集
    char startSymbol;               // 开始符号
    map<char, map<char, string>> parsingTable; // 预测分析表
    vector<char> nonTerminalList;   // 非终结符列表（顺序保持）

    // 判断是否为非终结符
    bool isNonTerminal(char c) {
        return isupper(c) || c == '\''; // 允许带撇号的大写字母
    }

    // 判断是否为终结符
    bool isTerminal(char c) {
        return !isNonTerminal(c) && c != '~' && c != '|' && c != ' ';
    }

    // 提取符号
    void extractSymbols() {
        for (const auto& prod : productions) {
            nonTerminals.insert(prod.left);

            for (char c : prod.right) {
                if (isNonTerminal(c)) {
                    nonTerminals.insert(c);
                }
                else if (c != '~' && c != '|') {
                    terminals.insert(c);
                }
            }
        }
    }

    // 计算字符串的FIRST集
    set<char> getStringFirst(const string& str) {
        set<char> res;
        bool canBeEpsilon = true;

        for (char c : str) {
            if (c == '~') {
                continue; // 跳过空串标记
            }

            if (isTerminal(c)) {
                res.insert(c);
                canBeEpsilon = false;
                break;
            }
            else if (isNonTerminal(c)) {
                // 加入FIRST(c)的非空部分
                for (char f : first[c]) {
                    if (f != '~') {
                        res.insert(f);
                    }
                }

                // 如果FIRST(c)不包含空，则停止
                if (first[c].find('~') == first[c].end()) {
                    canBeEpsilon = false;
                    break;
                }
            }
        }

        // 如果所有符号都能推出空，则加入空
        if (canBeEpsilon) {
            res.insert('~');
        }

        return res;
    }

    // 计算FIRST集
    void computeFirst() {
        // 初始化终结符的FIRST集
        for (char t : terminals) {
            first[t] = { t };
        }
        first['~'] = { '~' }; // 空串的FIRST集

        // 初始化非终结符的FIRST集
        for (char nt : nonTerminals) {
            first[nt] = set<char>();
        }

        bool changed = true;
        while (changed) {
            changed = false;

            for (const auto& prod : productions) {
                char left = prod.left;
                const string& right = prod.right;

                set<char> stFirst = getStringFirst(right);

                // 将stFirst中的所有元素加入FIRST(left)
                for (char c : stFirst) {
                    if (first[left].find(c) == first[left].end()) {
                        first[left].insert(c);
                        changed = true;
                    }
                }
            }
        }
    }

    // 计算FOLLOW集
    void computeFollow() {
        // 初始化
        for (char nt : nonTerminals) {
            follow[nt] = set<char>();
        }
        follow[startSymbol].insert('#'); // 开始符号的FOLLOW集加入#

        bool changed = true;
        while (changed) {
            changed = false;

            for (const auto& prod : productions) {
                char A = prod.left;
                const string& beta = prod.right;

                for (int i = 0; i < beta.size(); i++) {
                    char B = beta[i];
                    if (!isNonTerminal(B)) continue;

                    string gamma = (i + 1 < beta.size()) ? beta.substr(i + 1) : "";

                    // 计算gamma的FIRST集
                    set<char> firstGamma = getStringFirst(gamma);

                    // 规则1: 将FIRST(gamma)的非空部分加入FOLLOW(B)
                    for (char c : firstGamma) {
                        if (c != '~' && follow[B].find(c) == follow[B].end()) {
                            follow[B].insert(c);
                            changed = true;
                        }
                    }

                    // 规则2: 如果gamma能推出空或者gamma为空，则将FOLLOW(A)加入FOLLOW(B)
                    if (firstGamma.find('~') != firstGamma.end() || gamma.empty()) {
                        for (char c : follow[A]) {
                            if (follow[B].find(c) == follow[B].end()) {
                                follow[B].insert(c);
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }

    // 构造预测分析表
    void buildParsingTable() {
        // 初始化分析表为空
        for (char nt : nonTerminals) {
            for (char t : terminals) {
                parsingTable[nt][t] = "";
            }
            parsingTable[nt]['#'] = "";
        }

        // 遍历每个产生式
        for (const auto& prod : productions) {
            char A = prod.left;
            const string& alpha = prod.right;

            // 计算alpha的FIRST集
            set<char> firstAlpha = getStringFirst(alpha);

            // 对于FIRST(alpha)中的每个终结符a
            for (char a : firstAlpha) {
                if (a != '~' && a != '|') {
                    if (parsingTable[A][a] == "") {
                        parsingTable[A][a] = alpha;
                    }
                }
            }

            // 如果alpha能推出空
            if (firstAlpha.find('~') != firstAlpha.end()) {
                // 对于FOLLOW(A)中的每个终结符b（包括#）
                for (char b : follow[A]) {
                    if (b == '#') b = '#'; // 确保#被处理
                    if (parsingTable[A][b] == "") {
                        parsingTable[A][b] = alpha;
                    }
                }
            }
        }
    }

public:
    // 读取文法文件
    void readGrammar(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "无法打开文件: " << filename << endl;
            exit(1);
        }

        string line;
        bool firstLine = true;
        while (getline(inFile, line)) {
            // 移除空格
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

            size_t arrowPos = line.find("->");
            if (arrowPos == string::npos || arrowPos == 0) {
                continue; // 跳过无效行
            }

            char left = line[0];
            string rightPart = line.substr(arrowPos + 2);

            // 设置开始符号
            if (firstLine) {
                startSymbol = left;
                firstLine = false;
            }

            // 记录非终结符顺序
            if (find(nonTerminalList.begin(), nonTerminalList.end(), left) == nonTerminalList.end()) {
                nonTerminalList.push_back(left);
            }

            // 处理多个产生式，用|分隔
            size_t start = 0;
            size_t end = 0;
            while ((end = rightPart.find('|', start)) != string::npos) {
                string right = rightPart.substr(start, end - start);
                if (!right.empty()) {
                    productions.push_back(Production(left, right));
                }
                start = end + 1;
                if (end == string::npos) break;
            }
            string right = rightPart.substr(start);
            if (!right.empty()) {
                productions.push_back(Production(left, right));
            }
        }

        inFile.close();
        extractSymbols();
    }

    // 计算并输出结果
    void analyze() {
        ofstream outFile("output.txt");
        if (!outFile) {
            cerr << "无法创建输出文件" << endl;
            exit(1);
        }

        // 计算FIRST和FOLLOW集
        computeFirst();
        computeFollow();

        // 输出FIRST集
        outFile << "FIRST:" << endl;
        for (char nt : nonTerminalList) {
            outFile << nt << "\t";
            for (char c : first[nt]) {
                outFile << c << " ";
            }
            outFile << endl;
        }

        // 输出FOLLOW集
        outFile << "FOLLOW:" << endl;
        for (char nt : nonTerminalList) {
            outFile << nt << "\t";
            for (char c : follow[nt]) {
                if (c == '#') {
                    outFile << "# ";
                }
                else {
                    outFile << c << " ";
                }
            }
            outFile << endl;
        }

        // 构造预测分析表
        buildParsingTable();

        // 确定终结符顺序（包括#）
        vector<char> terminalOrder;

        // 固定顺序：+ * ( ) i
        vector<char> fixedOrder = { '+', '*', '(', ')', 'i' };
        set<char> fixedSet(fixedOrder.begin(), fixedOrder.end());

        // 添加其他终结符
        set<char> otherTerminals;
        for (char t : terminals) {
            if (fixedSet.find(t) == fixedSet.end()) {
                otherTerminals.insert(t);
            }
        }

        // 构建最终顺序：固定顺序 + 其他终结符（按ASCII排序）+ #
        for (char t : fixedOrder) {
            if (terminals.find(t) != terminals.end()) {
                terminalOrder.push_back(t);
            }
        }
        for (char t : otherTerminals) {
            terminalOrder.push_back(t);
        }
        terminalOrder.push_back('#');

        // 输出预测分析表
        outFile << "Analysis Table：" << endl;

        // 输出表头
        outFile << left << setw(8) << "";
        for (char t : terminalOrder) {
            if (t == '#') {
                outFile << left << setw(8) << "#";
            }
            else {
                outFile << left << setw(8) << string(1, t);
            }
        }
        outFile << endl;

        // 输出表内容
        for (char nt : nonTerminalList) {
            outFile << left << setw(8) << string(1, nt);
            for (char t : terminalOrder) {
                string prod = parsingTable[nt][t];
                // 将空串替换为~显示
                if (prod == "~") {
                    outFile << left << setw(8) << "~";
                }
                else {
                    outFile << left << setw(8) << prod;
                }
            }
            outFile << endl;
        }

        outFile.close();
    }
};

int main() {
    LL1Parser parser;
    parser.readGrammar("testfile.txt");
    parser.analyze();
    return 0;
}
