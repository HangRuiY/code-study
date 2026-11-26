#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "contact.h"
//结构体自引用
//struct A
//{
//	int a; char c;
//};
//struct B
//{
//	char ch; struct A sa;
//};
//typedef struct Noede//重新命名
//{
//	int data;
//	struct Noede* next;
//}Node;
//int main()
//{
//	struct Noede Node ;
//	return 0;
//}
//结构体初始化+访问
//struct A
//{
//	char a; int b;
//};
//struct B
//{
//	int c; struct A s;
//};
//int main()
//{
//	struct B m = { 4,{'y',18} };
//	printf("%d %c %d\n", m.c, m.s.a, m.s.b);
//	struct B* p = &m;
//	printf("%d %c %d", p->c, p->s.a, p->s.b);
//	return 0;
//}
//结构体传参
//struct B
//{
//	char c; short s; double d;
//};
//struct Stu
//{
//	struct B sb;
//	char name;
//	int age;
//	char id;
//};
//void print(struct Stu* a)
//{
//	printf("%c %d %lf %c %d %c", a->sb.c,a->sb.s, a->sb.d, a->name, a->age, a->id);
//}
//int main()
//{
//	struct Stu S = { {'w',2,8.0},"张三",20,"2022" };
//	struct Stu* p = &S;
//	print(p);
//}
//

//枚举类型
//enum menu
//{
//	exit,//0
//	add,//1
//	sub,//2
//	mul,//3
//	div//4
//};
//int main()
//{
//	int input = 0;
//	do
//	{
//		scanf("%d", &input);
//		switch (input)
//		{
//		case add:
//			break;
//		case sub:
//			break;
//		case mul: 
//			break;
//		case div:
//			break;
//		case exit:
//			break;
//		default:
//			break;
//		}
//	} while (input);
//	return 0;
//}
//

//共用体
//int panduan()
//{
//	union U
//	{
//		char a;
//		int i;
//	}u;
//	u.i = 1;//00 00 00 01 
//	return u.a;
//}
//int main()
//{
//	
//	if (panduan() == 1)
//		printf("小端");
//	else
//		printf("大端");
//	return 0;
//}
//union U
//{
//	short a[7];//2 14 
//	int i;//4 4
//}u;
//int main()
//{
//	printf("%d", sizeof(u));//16
//}

//通讯录
//存放1000个人的信息  每个人的信息包含：名字，年龄，性别，电话，地址
//可以增加/删除人的信息   修改人的信息   查找人的信息   排序信息
void menu()
{
	printf("************************************\n");
	printf("*******  1. add      2. del  *******\n");
	printf("*******  3. search   4. gai  *******\n");
	printf("*******  5. sort     6. Print *******\n");
	printf("*******  0. exit             *******\n");
	printf("************************************\n");
}
enum option
{
	exit,
	add,
	del,
	search,
	gai,
	sort,
	Print
};
#define max 1000

int main()
{
	int input = 0;
	//创建通讯录
	contact con;//通讯录
	//初始化通讯录   contact con={ 0 };也可以
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addcontact(&con); //增加
			break;
		case del: //删除
			delcontact(&con);
			break;
		case search:
			searchcontact(&con); //查找
			break;
		case gai: //修改
			gaicontact(&con);
			break;
		case sort: //排序
			sortcontact(&con);
			break;
		case Print:
			print(&con); //打印
			break;
		case exit:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}