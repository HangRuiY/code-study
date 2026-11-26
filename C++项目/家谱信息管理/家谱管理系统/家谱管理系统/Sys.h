#include <iostream>
using namespace std;
#include <stdbool.h>
#include <stdio.h>
#include <string>
#include <assert.h>
typedef struct p
{
    int tag;
    char name[20];//姓名
    char c[10];//性别
    char birth[20];//生日
    char wed[100];//是否结婚
    char addr[20];//地址
    char health[10];//是否健在
}pe;
typedef struct peop
{
    char name[20];//姓名
    char c[10];//性别
    char birth[20];//生日
    char wed[100];//是否结婚
    char addr[20];//地址
    char health[10];//是否健在
    pe wife;
}people;
typedef struct tre
{
    people data;
    struct tre* left;
    struct tre* right;
    struct tre* parent;
    int f;
}tree;
typedef struct regandlog //密码结构体
{
    char user_name[20];
    char pass_word[20];
}rl;
//进入界面
void sysmain();
//登录注册
void LoginAndRegister();
//面板函数
void Facebook(tree** t);
//初始化
tree* InitTree();
tree* Creat();
//左孩子
void new_left(tree** p, people info);
//右孩子
void new_right(tree** p, people info);
//打印
void printsystem(tree** t);
//树状打印
void PrintTree1(tree* T, int h);
//层次打印
void PrintTree2(tree* T);
//整体打印
void PrintTree3(tree* T);
//修改
void changesystem(tree** t);
//名字查找
tree* searchname(tree* t,char* a);
//生日查找
tree* searchbir(tree* t, char* a);
//查找
void searchsystem(tree** t);
//增加
void addsystem(tree** t);
//删除
void delsystem(tree** t);
//统计
void totalsystem(tree** t);
//文件
void File(tree** t);