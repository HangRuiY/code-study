#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
//类型的定义
#define max_name 20 //名字长度
#define max_sex 10
#define max_tele 12
#define max_addr 30
typedef struct peop
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
}people;

#define max 1000

typedef struct cont
{
	people data[max];//存放添加进来的信息
	int sz;//记录当前有效信息的个数
}contact;//把struct cont 重命名为 contact 是一个结构体类型

//初始化通讯录
void Initcontact(contact* p);//函数声明

//增加联系人
void addcontact(contact* p);

//删除联系人
void delcontact(contact* p);

//查找联系人
void searchcontact(contact* p);

//修改联系人
void gaicontact(contact* p);

//排序联系人
void sortcontact(contact* p);