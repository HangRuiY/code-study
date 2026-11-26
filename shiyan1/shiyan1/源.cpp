#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <stdio.h>
#include <map>
using namespace std;
const int MAX_INPUT_LENGTH = 100000;
bool shouldOutput = true;
// 判断字符是否为数字
bool IsCharacterDigit(char c)
{
    return isdigit(c);
}
// 判断字符是否为字母或下划线
bool IsCharacterLetter(char c)
{
    if (isalpha(c) || (c == '_'))
        return true;
    return false;
}
// 存储关键字和符号对应的类别
map<string, string> keywordCategory;
int inputLength = 0;
char input[MAX_INPUT_LENGTH];
int tokenCount = 0;
vector<string> tokenList;
vector<string> tokenValueList;
// 读取输入文件
void ReadInputFile()
{
    keywordCategory["const"] = "CONSTTK";
    keywordCategory["int"] = "INTTK";
    keywordCategory["char"] = "CHARTK";
    keywordCategory["void"] = "VOIDTK";
    keywordCategory["main"] = "MAINTK";
    keywordCategory["if"] = "IFTK";
    keywordCategory["else"] = "ELSETK";
    keywordCategory["do"] = "DOTK";
    keywordCategory["while"] = "WHILETK";
    keywordCategory["for"] = "FORTK";
    keywordCategory["continue"] = "CONTINUETK";
    keywordCategory["break"] = "BREAKTK";
    keywordCategory["getint"] = "GETINTTK";
    keywordCategory["printf"] = "PRINTFTK";
    keywordCategory["return"] = "RETURNTK";
    keywordCategory["+"] = "PLUS";
    keywordCategory["-"] = "MINU";
    keywordCategory["*"] = "MULT";
    keywordCategory["/"] = "DIV";
    keywordCategory["%"] = "MOD";
    keywordCategory["&&"] = "AND";
    keywordCategory["||"] = "OR";
    keywordCategory[","] = "COMMA";
    keywordCategory[";"] = "SEMICN";
    keywordCategory["("] = "LPARENT";
    keywordCategory[")"] = "RPARENT";
    keywordCategory["["] = "LBRACK";
    keywordCategory["]"] = "RBRACK";
    keywordCategory["{"] = "LBRACE";
    keywordCategory["}"] = "RBRACE";

    ifstream inputFile("testfile.txt", ios::in);
    if (!inputFile)
    {
        cout << "open testfile.txt error!" << endl;
        exit(1);
    }
    inputFile.unsetf(ios::skipws);
    while (inputFile.peek() != EOF)
    {
        char c = inputFile.get();
        input[inputLength++] = c;
    }
    inputFile.close();
}
// 词法分析
void PerformWordAnalysis()
{
    int position = 0;
    while (position < inputLength)
    {
        while (input[position] == ' ' || input[position] == '\n')
            position++;
        if (IsCharacterLetter(input[position]) || input[position] == '_') // 变量
        {
            string identifier = "";
            while (IsCharacterLetter(input[position]) || IsCharacterDigit(input[position]) || input[position] == '_')
            {
                identifier += input[position++];
            }
            if (keywordCategory[identifier] != "") // 已经存在
            {
                tokenList.push_back(keywordCategory[identifier]);
            }
            else
            {
                tokenList.push_back("IDENFR"); // 定义变量
            }
            tokenValueList.push_back(identifier);
            tokenCount++;
        }
        else if (IsCharacterDigit(input[position])) // 数字
        {
            string numberStr = "";
            int number = 0;
            while (IsCharacterDigit(input[position]))
            {
                number = number * 10 + (input[position] - '0');
                numberStr += input[position++];
            }
            tokenList.push_back("INTCON");
            tokenValueList.push_back(numberStr);
            tokenCount++;
        }
        else if (input[position] == '+' || input[position] == '-' || input[position] == '*' || input[position] == '/' || input[position] == '%' || input[position] == ';' || input[position] == ',' || input[position] == '(' || input[position] == ')' || input[position] == '[' || input[position] == ']' || input[position] == '{' || input[position] == '}')
        {
            // 处理注释
            if (input[position] == '/' && input[position + 1] == '/')
            {
                position = position + 2;
                while (input[position] != '\n')
                    position++;
                continue;
            }
            else if (input[position] == '/' && input[position + 1] == '*')
            {
                position = position + 2;
                while (input[position] != '*' || input[position + 1] != '/')
                    position++;
                position = position + 2;
                continue;
            }
            string symbol = "";
            symbol += input[position];
            position++;
            tokenList.push_back(keywordCategory[symbol]);
            tokenValueList.push_back(symbol);
            tokenCount++;
        }
        else if (input[position] == '&' || input[position] == '|')
        {
            string logicalOperator = "";
            logicalOperator += input[position];
            logicalOperator += input[position + 1];
            tokenList.push_back(keywordCategory[logicalOperator]);
            tokenValueList.push_back(logicalOperator);
            position += 2;
        }
        else if (input[position] == '=')
        {
            if (input[position + 1] == '=') // 双等号
            {
                tokenList.push_back("EQL");
                tokenValueList.push_back("==");
                tokenCount++;
                position += 2;
            }
            else
            {
                tokenList.push_back("ASSIGN");
                tokenValueList.push_back("=");
                tokenCount++;
                position++;
            }
        }
        else if (input[position] == 39) // 单引号
        {
            position++;
            string character = "";
            character += input[position];
            position++;
            if (input[position] == 39)
                position++;
            tokenList.push_back("CHARCON");
            tokenValueList.push_back(character);
            tokenCount++;
        }
        else if (input[position] == '"')
        {
            string stringLiteral;
            position++;
            while (input[position] != '"')
            {
                stringLiteral += input[position];
                position++;
            }
            position++;
            tokenList.push_back("STRCON");
            tokenValueList.push_back('"' + stringLiteral + '"');
            tokenCount++;
        }
        else if (input[position] == '<')
        {
            if (input[position + 1] == '=') // 小于等于号
            {
                tokenList.push_back("LEQ");
                tokenValueList.push_back("<=");
                tokenCount++;
                position += 2;
            }
            else
            {
                tokenList.push_back("LSS");
                tokenValueList.push_back("<");
                tokenCount++;
                position++;
            }
        }
        else if (input[position] == '>')
        {
            if (input[position + 1] == '=') // 大于等于号
            {
                tokenList.push_back("GEQ");
                tokenValueList.push_back(">=");
                tokenCount++;
                position += 2;
            }
            else
            {
                tokenList.push_back("GRE");
                tokenValueList.push_back(">");
                tokenCount++;
                position++;
            }
        }
        else if (input[position] == '!')
        {
            if (input[position + 1] == '=') // 不等于号
            {
                tokenList.push_back("NEQ");
                tokenValueList.push_back("!=");
                tokenCount++;
                position += 2;
            }
            else
            {
                tokenList.push_back("NOT");
                tokenValueList.push_back("!");
                tokenCount++;
                position++;
            }
        }
        else
            position++;
    }
    return;
}
int currentTokenIndex; // token[currentTokenIndex]==lookahead
map<string, int> voidFunctionMap;
ofstream outputFile;
// 匹配预期的token
void MatchExpectedToken(string expected);
// 匹配编译单元
void MatchCompilationUnit();
// 匹配声明
void MatchDeclaration();
// 匹配常量声明
void MatchConstantDeclaration();
// 匹配整数常量
void MatchIntegerConstant();
// 匹配数字
void MatchNumberValue();
// 匹配基本类型
void MatchBasicType();
// 匹配常量定义
void MatchConstantDefinition();
// 匹配常量初值
void MatchConstantInitialValue();
// 匹配变量声明
void MatchVariableDeclaration();
// 匹配变量定义
void MatchVariableDefinition();
// 匹配变量初值
void MatchVariableInitialValue();
// 匹配函数定义
void MatchFunctionDefinition();
// 匹配主函数定义
void MatchMainFunctionDefinition();
// 匹配函数类型
void MatchFunctionType();
// 匹配函数形参表
void MatchFunctionFormalParameters();
// 匹配函数形参
void MatchFunctionFormalParameter();
// 匹配语句块
void MatchBlockStatement();
// 匹配语句块项
void MatchBlockItemStatement();
// 匹配语句
void MatchStatement();
// 匹配表达式
void MatchExpression();
// 匹配条件表达式
void MatchConditionExpression();
// 匹配左值表达式
void MatchLeftValueExpression();
// 匹配基本表达式
void MatchPrimaryExpression();
// 匹配单目运算符
void MatchUnaryOperator();
// 匹配函数实参表
void MatchFunctionActualParameters();
// 匹配乘除模表达式
void MatchMultiplicationExpression();
// 匹配乘除模表达式后续部分
void MatchMultiplicationExpressionPartTwo();
// 匹配单目表达式
void MatchUnaryExpression();
// 匹配加减表达式
void MatchAdditionExpression();
// 匹配加减表达式后续部分
void MatchAdditionExpressionPartTwo();
// 匹配关系表达式
void MatchRelationalExpression();
// 匹配关系表达式后续部分
void MatchRelationalExpressionPartTwo();
// 匹配相等性表达式
void MatchEqualityExpression();
// 匹配相等性表达式后续部分
void MatchEqualityExpressionPartTwo();
// 匹配逻辑与表达式
void MatchLogicalAndExpression();
// 匹配逻辑与表达式后续部分
void MatchLogicalAndExpressionPartTwo();
// 匹配逻辑或表达式
void MatchLogicalOrExpression();
// 匹配逻辑或表达式后续部分
void MatchLogicalOrExpressionPartTwo();
// 匹配常量表达式
void MatchConstantExpression();
// 匹配打印语句
void MatchPrintStatement();
// 匹配获取整数语句
void MatchGetIntStatement();
// 匹配返回语句
void MatchReturnStatement();
// 语法分析
void PerformGrammarAnalysis()
{
    currentTokenIndex = 0;
    MatchCompilationUnit();
    outputFile.close();
    return;
}
// 匹配编译单元
void MatchCompilationUnit()
{
    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef // 1.是否存在Decl 2.是否存在FuncDef
    // 常量声明
    while ((tokenList[currentTokenIndex] == "INTTK" || tokenList[currentTokenIndex] == "CHARTK") && tokenList[currentTokenIndex + 2] != "LPARENT" || tokenList[currentTokenIndex] == "CONSTTK")
    {
        MatchDeclaration();
    }
    // 函数定义
    while ((tokenList[currentTokenIndex] == "INTTK" || tokenList[currentTokenIndex] == "CHARTK" || tokenList[currentTokenIndex] == "VOIDTK") && tokenList[currentTokenIndex + 1] == "IDENFR" && tokenList[currentTokenIndex + 2] == "LPARENT")
    {
        MatchFunctionDefinition();
    }
    // 主函数
    if (tokenList[currentTokenIndex] == "INTTK" && tokenList[currentTokenIndex + 1] == "MAINTK")
    {
        MatchMainFunctionDefinition();
    }
    if (shouldOutput)
        outputFile << "<CompUnit>\n";
}
// 匹配声明
void MatchDeclaration()
{
    // 声明Decl → ConstDecl | VarDecl // 覆盖两种声明
    if (tokenList[currentTokenIndex] == "CONSTTK")
    {
        MatchConstantDeclaration();
    }
    else
    {
        MatchVariableDeclaration();
    }
    // outputFile << "<Decl>\n";
}
// 匹配常量声明
void MatchConstantDeclaration()
{
    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // 1.花括号内重复0次 2.花括号内重复多次
    MatchExpectedToken("CONSTTK");
    MatchBasicType();
    MatchConstantDefinition();
    while (tokenList[currentTokenIndex] == "COMMA")
    {
        MatchExpectedToken("COMMA");
        MatchConstantDefinition();
    }
    MatchExpectedToken("SEMICN");
    if (shouldOutput)
        outputFile << "<ConstDecl>\n";
}
// 匹配整数常量
void MatchIntegerConstant()
{
    if (tokenValueList[currentTokenIndex][0] == '0' && tokenValueList[currentTokenIndex].length() > 1)
    {
        printf("error");
        exit(0);
    }
    else
        MatchExpectedToken("INTCON");
    // printf("<无符号整数>\n");
    if (shouldOutput)
        outputFile << "<Number>\n";
}
// 匹配数字
void MatchNumberValue()
{
    // 数值 Number → IntConst
    if (tokenList[currentTokenIndex] == "PLUS")
        MatchExpectedToken("PLUS");
    else if (tokenList[currentTokenIndex] == "MINU")
        MatchExpectedToken("MINU");
    MatchIntegerConstant();
    // printf("<整数>\n");
    // outputFile << "<整数>\n";
}
// 匹配基本类型
void MatchBasicType()
{
    // 基本类型 BType → 'int' // 存在即可
    if (tokenList[currentTokenIndex] == "INTTK")
        MatchExpectedToken("INTTK");
    else if (tokenList[currentTokenIndex] == "CHARTK")
        MatchExpectedToken("CHARTK");
}
// 匹配常量定义
void MatchConstantDefinition()
{
    // 常数定义 ConstDef → Ident { '[' ConstExp ']' } '=' ConstInitVal // 包含普通变量、⼀维数组、⼆维数组共三种情况
    MatchExpectedToken("IDENFR");
    while (tokenList[currentTokenIndex] == "LBRACK")
    {
        MatchExpectedToken("LBRACK");
        MatchConstantExpression();
        MatchExpectedToken("RBRACK");
    }
    MatchExpectedToken("ASSIGN");
    MatchConstantInitialValue();
    if (shouldOutput)
        outputFile << "<ConstDef>\n";
}
// 匹配常量初值
void MatchConstantInitialValue()
{
    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstInitVal { ',' ConstInitVal } ] '}' // 1.常表达式初值 2.⼀维数组初值 3.⼆维数组初值
    if (tokenList[currentTokenIndex] != "LBRACE")
    {
        MatchConstantExpression();
    }
    else
    {
        MatchExpectedToken("LBRACE");
        if (tokenList[currentTokenIndex] != "RBRACE")
        {
            MatchConstantInitialValue();
            while (tokenList[currentTokenIndex] == "COMMA")
            {
                MatchExpectedToken("COMMA");
                MatchConstantInitialValue();
            }
        }
        MatchExpectedToken("RBRACE");
    }
    if (shouldOutput)
        outputFile << "<ConstInitVal>\n";
}
// 匹配变量声明
void MatchVariableDeclaration()
{
    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // 1.花括号内重复0次 2.花括号内重复多次
    MatchBasicType();
    MatchVariableDefinition();
    while (tokenList[currentTokenIndex] == "COMMA")
    {
        MatchExpectedToken("COMMA");
        MatchVariableDefinition();
    }
    MatchExpectedToken("SEMICN");
    if (shouldOutput)
        outputFile << "<VarDecl>\n";
}
// 匹配变量定义
void MatchVariableDefinition()
{
    // 变量定义 VarDef → Ident { '[' ConstExp ']' }  | Ident { '[' ConstExp ']' } '=' InitVal
    MatchExpectedToken("IDENFR");
    while (tokenList[currentTokenIndex] == "LBRACK")
    {
        MatchExpectedToken("LBRACK");
        MatchConstantExpression();
        MatchExpectedToken("RBRACK");
    }
    if (tokenList[currentTokenIndex] == "ASSIGN")
    {
        MatchExpectedToken("ASSIGN");
        MatchVariableInitialValue();
    }
    if (shouldOutput)
        outputFile << "<VarDef>\n";
}
// 匹配变量初值
void MatchVariableInitialValue()
{
    // 变量初值 InitVal → Exp | '{' [ InitVal { ',' InitVal } ] '}'// 1.表达式初值 2.⼀维数组初值 3.⼆维数组初值
    if (tokenList[currentTokenIndex] != "LBRACE")
    {
        MatchExpression();
    }
    else
    {
        MatchExpectedToken("LBRACE");
        if (tokenList[currentTokenIndex] != "RBRACE")
        {
            MatchVariableInitialValue();
            while (tokenList[currentTokenIndex] == "COMMA")
            {
                MatchExpectedToken("COMMA");
                MatchVariableInitialValue();
            }
        }
        MatchExpectedToken("RBRACE");
    }
    if (shouldOutput)
        outputFile << "<InitVal>\n";
}
// 匹配函数定义
void MatchFunctionDefinition()
{
    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.⽆形参 2.有形参
    MatchFunctionType();
    MatchExpectedToken("IDENFR");
    MatchExpectedToken("LPARENT");
    if (tokenList[currentTokenIndex] != "RPARENT")
        MatchFunctionFormalParameters();
    MatchExpectedToken("RPARENT");
    MatchBlockStatement();
    if (shouldOutput)
        outputFile << "<FuncDef>\n";
}
// 匹配主函数定义
void MatchMainFunctionDefinition()
{
    // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // 存在main函数
    MatchExpectedToken("INTTK");
    MatchExpectedToken("MAINTK");
    MatchExpectedToken("LPARENT");
    MatchExpectedToken("RPARENT");
    MatchBlockStatement();
    // printf("<MainFuncDef>\n");
    if (shouldOutput)
        outputFile << "<MainFuncDef>\n";
}
// 匹配函数类型
void MatchFunctionType()
{
    // 函数类型 FuncType → 'void' | 'int' // 覆盖两种类型的函数
    if (tokenList[currentTokenIndex] == "INTTK")
        MatchExpectedToken("INTTK");
    else if (tokenList[currentTokenIndex] == "VOIDTK")
        MatchExpectedToken("VOIDTK");
    if (shouldOutput)
        outputFile << "<FuncType>\n";
}
// 匹配函数形参表
void MatchFunctionFormalParameters()
{
    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } // 1.花括号内重复0次 2.花括号内重复多次
    MatchFunctionFormalParameter();
    while (tokenList[currentTokenIndex] == "COMMA")
    {
        MatchExpectedToken("COMMA");
        MatchFunctionFormalParameter();
    }
    if (shouldOutput)
        outputFile << "<FuncFParams>\n";
}
// 匹配函数形参
void MatchFunctionFormalParameter()
{
    // 函数形参 FuncFParam → BType Ident ['[' ']' { '[' ConstExp ']' }] // 1.普通变量 2.⼀维数组变量 3.⼆维数组变量
    MatchBasicType();
    MatchExpectedToken("IDENFR");
    // 数组
    if (tokenList[currentTokenIndex] == "LBRACK")
    {
        MatchExpectedToken("LBRACK");
        MatchExpectedToken("RBRACK");
        while (tokenList[currentTokenIndex] == "LBRACK")
        {
            MatchExpectedToken("LBRACK");
            MatchConstantExpression();
            MatchExpectedToken("RBRACK");
        }
    }
    if (shouldOutput)
        outputFile << "<FuncFParam>\n";
}
// 匹配语句块
void MatchBlockStatement()
{
    // 语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
    MatchExpectedToken("LBRACE");
    while (tokenList[currentTokenIndex] != "RBRACE")
        MatchBlockItemStatement();
    MatchExpectedToken("RBRACE");
    // printf("<Block>\n");
    if (shouldOutput)
        outputFile << "<Block>\n";
}
// 匹配语句块项
void MatchBlockItemStatement()
{
    // 语句块项 BlockItem → Decl | Stmt // 覆盖两种语句块项
    if (tokenList[currentTokenIndex] == "INTTK" || tokenList[currentTokenIndex] == "CHARTK" || tokenList[currentTokenIndex] == "CONSTTK")
    {
        MatchDeclaration();
    }
    else
    {
        MatchStatement();
    }
    // outputFile << "<BlockItem>\n";
}
// 匹配语句
void MatchStatement()
{
    if (tokenList[currentTokenIndex] == "IDENFR")
    {
        if (((tokenList[currentTokenIndex + 1] == "LBRACK" && tokenList[currentTokenIndex + 4] == "LBRACK" && tokenList[currentTokenIndex + 7] == "ASSIGN")) || (tokenList[currentTokenIndex + 1] == "LBRACK" && tokenList[currentTokenIndex + 4] == "ASSIGN") || tokenList[currentTokenIndex + 1] == "ASSIGN")
        {
            MatchLeftValueExpression();
            MatchExpectedToken("ASSIGN");
            if (tokenList[currentTokenIndex] == "GETINTTK")
            {
                MatchGetIntStatement();
            }
            else
                MatchExpression();
        }
        else
        {
            MatchExpression();
        }
        MatchExpectedToken("SEMICN");
    }
    else if (tokenList[currentTokenIndex] == "LBRACE")
    {
        MatchBlockStatement();
    }
    else if (tokenList[currentTokenIndex] == "IFTK")
    {
        MatchExpectedToken("IFTK");
        MatchExpectedToken("LPARENT");
        MatchConditionExpression();
        MatchExpectedToken("RPARENT");
        MatchStatement();
        if (tokenList[currentTokenIndex] == "ELSETK")
        {
            MatchExpectedToken("ELSETK");
            MatchStatement();
        }
    }
    else if (tokenList[currentTokenIndex] == "WHILETK")
    {
        MatchExpectedToken("WHILETK");
        MatchExpectedToken("LPARENT");
        MatchConditionExpression();
        MatchExpectedToken("RPARENT");
        MatchStatement();
    }
    else if (tokenList[currentTokenIndex] == "BREAKTK" || tokenList[currentTokenIndex] == "CONTINUETK")
    {
        MatchExpectedToken(tokenList[currentTokenIndex]);
        MatchExpectedToken("SEMICN");
    }
    else if (tokenList[currentTokenIndex] == "RETURNTK")
    {
        MatchReturnStatement();
        MatchExpectedToken("SEMICN");
    }
    else if (tokenList[currentTokenIndex] == "PRINTFTK")
    {
        MatchPrintStatement();
        MatchExpectedToken("SEMICN");
    }
    else if (tokenList[currentTokenIndex] == "SEMICN")
        MatchExpectedToken("SEMICN");

    // printf("<Stmt>\n");
    if (shouldOutput)
        outputFile << "<Stmt>\n";
}
// 匹配表达式
void MatchExpression()
{
    // 表达式 Exp → AddExp
    MatchAdditionExpression();
    // printf("<Exp>\n");
    if (shouldOutput)
        outputFile << "<Exp>\n";
}
// 匹配条件表达式
void MatchConditionExpression()
{
    // 条件表达式 Cond → LOrExp
    MatchLogicalOrExpression();
    if (shouldOutput)
        outputFile << "<Cond>\n";
}
// 匹配左值表达式
void MatchLeftValueExpression()
{
    // 左值表达式 LVal → Ident {'[' Exp ']'}
    MatchExpectedToken("IDENFR");
    while (tokenList[currentTokenIndex] == "LBRACK")
    {
        MatchExpectedToken("LBRACK");
        MatchExpression();
        MatchExpectedToken("RBRACK");
    }
    if (shouldOutput)
        outputFile << "<LVal>\n";
}
// 匹配基本表达式
void MatchPrimaryExpression()
{
    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number
    if (tokenList[currentTokenIndex] == "LPARENT")
    {
        MatchExpectedToken("LPARENT");
        MatchExpression();
        MatchExpectedToken("RPARENT");
    }
    else if (tokenList[currentTokenIndex] == "IDENFR")
    {
        MatchLeftValueExpression();
    }
    else if (tokenList[currentTokenIndex] == "INTCON" || tokenList[currentTokenIndex] == "PLUS" || tokenList[currentTokenIndex] == "MINU")
        MatchNumberValue();
    if (shouldOutput)
        outputFile << "<PrimaryExp>\n";
}
// 匹配单目运算符
void MatchUnaryOperator()
{
    // 单⽬运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 // 三种均需覆盖
    if (tokenList[currentTokenIndex] == "PLUS" || tokenList[currentTokenIndex] == "MINU" || tokenList[currentTokenIndex] == "NOT")
    {
        MatchExpectedToken(tokenList[currentTokenIndex]);
    }
    if (shouldOutput)
        outputFile << "<UnaryOp>\n";
}
// 匹配函数实参表
void MatchFunctionActualParameters()
{
    // 函数实参表 FuncRParams → Exp { ',' Exp }
    MatchExpression();
    while (tokenList[currentTokenIndex] == "COMMA")
    {
        MatchExpectedToken("COMMA");
        MatchExpression();
    }
    if (shouldOutput)
        outputFile << "<FuncRParams>\n";
}
// 匹配乘除模表达式
void MatchMultiplicationExpression()
{
    // 乘除模表达式 MulExp → UnaryExp |  MulExp (*' | '/' | '%') UnaryExp
    MatchUnaryExpression();
    MatchMultiplicationExpressionPartTwo();
}
// 匹配乘除模表达式后续部分
void MatchMultiplicationExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<MulExp>\n";
    if (tokenList[currentTokenIndex] == "MULT" || tokenList[currentTokenIndex] == "DIV" || tokenList[currentTokenIndex] == "MOD")
    {
        if (tokenList[currentTokenIndex] == "MULT")
            MatchExpectedToken("MULT");
        else if (tokenList[currentTokenIndex] == "DIV")
            MatchExpectedToken("DIV");
        else if (tokenList[currentTokenIndex] == "MOD")
            MatchExpectedToken("MOD");
        MatchUnaryExpression();
        MatchMultiplicationExpressionPartTwo();
    }
}
// 匹配单目表达式
void MatchUnaryExpression()
{
    // 首位带符号
    if (tokenList[currentTokenIndex] == "PLUS" || tokenList[currentTokenIndex] == "MINU" || tokenList[currentTokenIndex] == "NOT")
    {
        MatchUnaryOperator();
        MatchUnaryExpression();
    }
    // 函数调用
    else if (tokenList[currentTokenIndex + 1] == "LPARENT")
    {
        MatchExpectedToken("IDENFR");
        MatchExpectedToken("LPARENT");
        if (tokenList[currentTokenIndex] != "RPARENT")
            MatchFunctionActualParameters();
        MatchExpectedToken("RPARENT");
    }
    else
    {
        MatchPrimaryExpression();
    }
    if (shouldOutput)
        outputFile << "<UnaryExp>\n";
}
// 匹配加减表达式
void MatchAdditionExpression()
{
    MatchMultiplicationExpression();
    MatchAdditionExpressionPartTwo();
}
// 匹配加减表达式后续部分
void MatchAdditionExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<AddExp>\n";
    if (tokenList[currentTokenIndex] == "PLUS" || tokenList[currentTokenIndex] == "MINU")
    {
        if (tokenList[currentTokenIndex] == "PLUS")
            MatchExpectedToken("PLUS");
        else if (tokenList[currentTokenIndex] == "MINU")
            MatchExpectedToken("MINU");
        MatchMultiplicationExpression();
        MatchAdditionExpressionPartTwo();
    }
}
// 匹配关系表达式
void MatchRelationalExpression()
{
    // 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    if (tokenList[currentTokenIndex] == "LSS")
        MatchExpectedToken("LSS");
    else if (tokenList[currentTokenIndex] == "LEQ")
        MatchExpectedToken("LEQ");
    else if (tokenList[currentTokenIndex] == "GRE")
        MatchExpectedToken("GRE");
    else if (tokenList[currentTokenIndex] == "GEQ")
        MatchExpectedToken("GEQ");
    MatchAdditionExpression();
    MatchRelationalExpressionPartTwo();
}
// 匹配关系表达式后续部分
void MatchRelationalExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<RelExp>\n";
    if (tokenList[currentTokenIndex] == "LSS" || tokenList[currentTokenIndex] == "LEQ" || tokenList[currentTokenIndex] == "GRE" || tokenList[currentTokenIndex] == "GEQ")
    {
        if (tokenList[currentTokenIndex] == "LSS")
            MatchExpectedToken("LSS");
        else if (tokenList[currentTokenIndex] == "LEQ")
            MatchExpectedToken("LEQ");
        else if (tokenList[currentTokenIndex] == "GRE")
            MatchExpectedToken("GRE");
        else if (tokenList[currentTokenIndex] == "GEQ")
            MatchExpectedToken("GEQ");
        MatchAdditionExpression();
        MatchRelationalExpressionPartTwo();
    }
}
// 匹配相等性表达式
void MatchEqualityExpression()
{
    // 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    if (tokenList[currentTokenIndex] == "EQL")
        MatchExpectedToken("EQL");
    else if (tokenList[currentTokenIndex] == "NEQ")
        MatchExpectedToken("NEQ");
    MatchRelationalExpression();
    MatchEqualityExpressionPartTwo();
}
// 匹配相等性表达式后续部分
void MatchEqualityExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<EqExp>\n";
    if (tokenList[currentTokenIndex] == "EQL" || tokenList[currentTokenIndex] == "NEQ")
    {
        if (tokenList[currentTokenIndex] == "EQL")
            MatchExpectedToken("EQL");
        else if (tokenList[currentTokenIndex] == "NEQ")
            MatchExpectedToken("NEQ");
        MatchRelationalExpression();
        MatchEqualityExpressionPartTwo();
    }
}
// 匹配逻辑与表达式
void MatchLogicalAndExpression()
{
    // 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    if (tokenList[currentTokenIndex] == "AND")
        MatchExpectedToken("AND");
    MatchEqualityExpression();
    MatchLogicalAndExpressionPartTwo();
}
// 匹配逻辑与表达式后续部分
void MatchLogicalAndExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<LAndExp>\n";
    if (tokenList[currentTokenIndex] == "AND")
    {
        if (tokenList[currentTokenIndex] == "AND")
            MatchExpectedToken("AND");
        MatchEqualityExpression();
        MatchLogicalAndExpressionPartTwo();
    }
}
// 匹配逻辑或表达式
void MatchLogicalOrExpression()
{
    // 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    if (tokenList[currentTokenIndex] == "OR")
        MatchExpectedToken("OR");
    MatchLogicalAndExpression();
    MatchLogicalOrExpressionPartTwo();
}
// 匹配逻辑或表达式后续部分
void MatchLogicalOrExpressionPartTwo()
{
    if (shouldOutput)
        outputFile << "<LOrExp>\n";
    if (tokenList[currentTokenIndex] == "OR")
    {
        if (tokenList[currentTokenIndex] == "OR")
            MatchExpectedToken("OR");
        MatchLogicalAndExpression();
        MatchLogicalOrExpressionPartTwo();
    }
}
// 匹配常量表达式
void MatchConstantExpression()
{
    MatchAdditionExpression();
    if (shouldOutput)
        outputFile << "<ConstExp>\n";
}
// 匹配打印语句
void MatchPrintStatement()
{
    //'printf''('FormatString{','Exp}')'';' // 1.有Exp 2.⽆Exp
    MatchExpectedToken("PRINTFTK");
    MatchExpectedToken("LPARENT");
    if (tokenList[currentTokenIndex] == "STRCON")
        MatchExpectedToken("STRCON");
    else
        MatchExpression();
    while (tokenList[currentTokenIndex] == "COMMA")
    {
        MatchExpectedToken("COMMA");
        MatchExpression();
    }
    MatchExpectedToken("RPARENT");
}
// 匹配获取整数语句
void MatchGetIntStatement()
{
    // LVal '=' 'getint''('')'';'
    MatchExpectedToken("GETINTTK");
    MatchExpectedToken("LPARENT");
    MatchExpectedToken("RPARENT");
}
// 匹配返回语句
void MatchReturnStatement()
{
    // 'return' [Exp] ';' // 1.有Exp 2.⽆Exp
    MatchExpectedToken("RETURNTK");
    // 有返回值
    if (tokenList[currentTokenIndex] != "SEMICN")
        MatchExpression();
}
// 匹配预期的token
void MatchExpectedToken(string expected)
{
    if (tokenList[currentTokenIndex] == expected)
    {
        // cout << tokenList[currentTokenIndex] << " " << tokenValueList[currentTokenIndex] << endl;
        outputFile << tokenList[currentTokenIndex] << " " << tokenValueList[currentTokenIndex] << endl;
        currentTokenIndex++;
    }
    else
    {
        cout << tokenList[currentTokenIndex] << " " << expected << endl;
        printf("shitbrofuckingerror_tm");
        exit(0);
    }
}
// 初始化
void Initialize()
{
    // 清空输出文件
    fstream file("output.txt", ios::out);
    outputFile.open("output.txt", ios::out);
}
// 打印词法分析结果
void PrintTokens()
{
    ofstream output("output.txt", ios::out);
    for (int i = 0; i < tokenCount; i++)
    {
        output << tokenList[i] << " " << tokenValueList[i] << endl;
    }
    output.close();
}
int main()
{
    Initialize();
    ReadInputFile();
    PerformWordAnalysis();
    PrintTokens();
    //PerformGrammarAnalysis();
    return 0;
}