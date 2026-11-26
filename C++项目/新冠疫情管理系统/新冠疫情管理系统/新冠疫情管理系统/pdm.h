#include <stdio.h> 
#include <string.h>
#include <assert.h>
#define max_name 20
#define max_num 10
#define max_id 20
#define max_tele 12
#define max_addr 30
#define max_word 30
typedef struct peop //结构体存放人员的基本信息
{
	char name[max_name];//姓名
	char num[max_num];//学号
	double tem;//体温
	char id[max_id];//身份证
	char tele[max_tele];//手机号码
	char addr[max_addr];//地址
	char addr2[max_addr];//地址
}people;

typedef struct sys //链表
{
	people data;
	struct sys* next;
}syslist;

typedef struct regandlog //密码结构体
{
	char user_name[max_name];
	char pass_word[max_word];
}rl;
//初始化
void Initsystem(syslist** p);
//登录系统
void systemmain(syslist** p);
//登录注册
void LoginAndRegister(syslist** p);
//面板函数
void Facebook(syslist** p);
//输入信息
void pushsystem(people* data);
//统计信息个数
void totalsystem(syslist** p);
//增加
void addsystem(syslist** p);
//删除
void delsystem(syslist** p);
//判断是否重名
int countif(syslist** p,char* name);
//体温查找
syslist* findsystem_tem(syslist* phead);
//查看有没有此人-姓名
syslist* findsystem_name(syslist* phead, char* name);
//查看有没有此人-学号
syslist* findsystem_num(syslist* phead, char* num);
//查看有没有此人-身份证号
syslist* findsystem_id(syslist* phead, char* id);
//查找某个人全部信息
void searchsystem(syslist** p);
//修改
void changesystem(syslist** p);
//排序
void sortsystem(syslist** p);
//打印
void printsystem(syslist** p);
//销毁
void destroysystem(syslist** p);
//文件操作
void File(syslist** p);
//读取文件
syslist* Read(syslist** p);