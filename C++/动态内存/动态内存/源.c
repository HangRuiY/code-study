#include "通讯录.h"
//动态内存开辟
// //malloc
//int main()
//{
//	//int arr[10] = { 0 };//栈区
//	int* p = (int*)malloc(40); //10* sizeof(int)
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//		printf("%d ", p[i]);
//	free(p);
//	p = NULL;
//	return 0;
//}
// calloc
//int main()
//{
//	int* p = calloc(10, sizeof(int));  //开辟的同时 初始化0
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", p[i]);      p[i]==*(p+1i)
//	}
//	return 0;
//}
//realloc
//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	int i = 0;
//	if (p == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//		printf("%d ", p[i]);
//	}
//	再加20个数字
//	realloc 调整
//	int* pc = realloc(p, 20 * sizeof(int));
//	if (pc != NULL)
//	{
//		p = pc;
//		for (i = 10; i < 20; i++)
//		{
//			*(p + i) = i;
//			printf("%d ", p[i]);
//		}
//	}
//	free(p); p = NULL;
//	return 0;
//}

//通讯录
//存放1000个人的信息  每个人的信息包含：名字，年龄，性别，电话，地址
//可以增加/删除人的信息   修改人的信息   查找人的信息   排序信息
//动态增长的版本
//1->初始化后能存放三个人的信息
//2->空间放满后 增加两个信息
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

int main()
{
	int input = 0;
	//创建通讯录
	contact con;//通讯录
	//初始化通讯录   contact con={ 0 };也可以
	//给data开辟一块连续的堆区空间
	//sz=0 capacity 初始化为当前最大容量
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
			/*sortcontact(&con);*/
			break;
		case Print:
			print(&con); //打印
			break;
		case exit:
			//保存信息到文件
			savecontact(&con);
			//销毁通讯录
			destroycontact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

//经典题目
//1.void getmem(char* p)
//{
//	p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	getmem(str);
//	strcpy(str, "hello");
//	printf(str);
//}
//改：
//char* getmen(char* p)
//{
//	p = (char*)malloc(100);
//  return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str=getmem(str);
//	strcpy(str, "hello");
//	printf(str);
//  free(str);
//  str=NULL;
//}

//柔性数组
//struct S
//{
//	int a;
//	int arr[];
//};
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 40); //存十个元素
//	p->a = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	struct S* str = (struct S*)realloc(p, sizeof(int) * 20);
//	if (str != NULL)
//		p = str;
//	free(p);
//	p = NULL;
//}

//struct S
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S));
//	if (p == NULL)
//		return 1;
//	p->n = 10;
//	p->arr = (int*)malloc(10 * sizeof(int));
//	if (p->arr == NULL)
//		return 2;
//	for (int i = 0; i < 10; i++)
//		p->arr[i] = i;
//	int* str = realloc(p->arr, 10 * sizeof(int));
//	if (str != NULL)
//		p->arr = str;
//	free(p->arr);
//	p->arr = NULL;
//	free(p);
//	p = NULL;
//}
