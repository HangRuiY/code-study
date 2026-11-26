#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

class PredictiveParser {
private:
    string input;           // 输入符号串
    string stack;           // 符号栈（栈顶在右侧）
    int step;               // 当前步骤
    int index;              // 输入指针
    ofstream outFile;       // 输出文件流

    // 预测分析表 [非终结符][终结符] -> 产生式
    map<char, map<char, string>> parsingTable;

    // 初始化预测分析表
    void initializeParsingTable() {
        // 初始化所有表项为空
        vector<char> nonTerms = { 'E', 'A', 'T', 'B', 'F' };
        vector<char> terms = { '+', '*', '(', ')', 'i', '#' };

        for (char nt : nonTerms) {
            for (char t : terms) {
                parsingTable[nt][t] = ""; // 默认无产生式
            }
        }

        // 填充预测分析表
        parsingTable['E']['('] = "TA";
        parsingTable['E']['i'] = "TA";

        parsingTable['A']['+'] = "+TA";
        parsingTable['A'][')'] = "~";
        parsingTable['A']['#'] = "~";

        parsingTable['T']['('] = "FB";
        parsingTable['T']['i'] = "FB";

        parsingTable['B']['+'] = "~";
        parsingTable['B']['*'] = "*FB";
        parsingTable['B'][')'] = "~";
        parsingTable['B']['#'] = "~";

        parsingTable['F']['('] = "(E)";
        parsingTable['F']['i'] = "i";
    }

    // 判断是否为终结符
    bool isTerminal(char c) {
        return (c == '+' || c == '*' || c == '(' || c == ')' || c == 'i' || c == '#');
    }

    // 输出当前步骤
    void outputStep() {
        char currentSym = (index < input.size()) ? input[index] : '#';
        string rule = "";

        // 获取栈顶符号
        char top = stack.back();

        // 如果是非终结符，查找预测分析表
        if (!isTerminal(top) && top != '#') {
            rule = parsingTable[top][currentSym];
            if (rule == "") {
                rule = "ERR!";
            }
            else if (rule != "~") {
                rule = string(1, top) + "->" + rule;
            }
            else {
                rule = string(1, top) + "->~";
            }
        }

        // 特殊处理接受状态
        if (stack == "" && index == input.size() - 1) {
            rule = "ACC!";
        }

        // 输出当前步骤
        outFile << left << setw(8) << step;
        outFile << left << setw(16) << stack;
        outFile << left << setw(8) << currentSym;
        outFile << rule << endl;
    }

public:
    PredictiveParser(const string& filename) : step(0), index(0) {
        // 读取输入文件
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "无法打开输入文件" << endl;
            exit(1);
        }
        getline(inFile, input);
        inFile.close();

        // 确保输入以#结尾
        if (input.back() != '#') {
            input += '#';
        }

        // 初始化栈
        stack = "#E";

        // 初始化预测分析表
        initializeParsingTable();

        // 打开输出文件
        outFile.open("output.txt");
        if (!outFile) {
            cerr << "无法创建输出文件" << endl;
            exit(1);
        }

        // 输出表头
        outFile << "step    stack           sym     rule" << endl;
    }

    // 执行语法分析
    void parse() {
        // 输出初始状态
        outputStep();

        while (stack != "") {
            step++;
            char top = stack.back();
            char currentSym = (index < input.size()) ? input[index] : '#';

            // 栈顶与输入符号匹配
            if (top == currentSym) {
                // 匹配成功，弹出栈顶并移动输入指针
                stack.pop_back();
                if (currentSym != '#') {
                    index++;
                }
            }
            // 栈顶是非终结符
            else if (!isTerminal(top)) {
                string production = parsingTable[top][currentSym];

                // 无产生式可用，报错
                if (production == "") {
                    outputStep();
                    outFile << "ERR!" << endl;
                    return;
                }

                // 弹出栈顶
                stack.pop_back();

                // 将产生式逆序压栈（空产生式除外）
                if (production != "~") {
                    for (int i = production.size() - 1; i >= 0; i--) {
                        stack.push_back(production[i]);
                    }
                }
            }
            // 不匹配且不是非终结符，报错
            else {
                outputStep();
                outFile << "ERR!" << endl;
                return;
            }

            // 输出当前步骤
            outputStep();

            // 检查是否接受
            if (stack == "" && index == input.size() - 1) {
                break;
            }
        }

        outFile.close();
    }
};

int main() {
    PredictiveParser parser("testfile.txt");
    parser.parse();
    return 0;
}
