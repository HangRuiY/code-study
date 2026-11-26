#include "contact.h"
#include <stdio.h>
void Initcontact(contact* p) //初始化通讯录
{
	p->sz = 0;
	//memset() 内存设置 初始化为0
	memset(p->data, 0, sizeof(p->data)); //sizeof(arr)算整个数组大小
}

void addcontact(contact* p) //增加联系人
{
	if (p->sz == max) //最多放max=1000个数据
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", p->data[p->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(p->data[p->sz].age));
	printf("请输入性别:>");
	scanf("%s", p->data[p->sz].sex);
	printf("请输入电话:>");
	scanf("%s", p->data[p->sz].tele);
	printf("请输入地址:>");
	scanf("%s", p->data[p->sz].addr);
	p->sz++;  //每存一个 加一次 表示多存了一个数据
	printf("增加成功\n");
}

void print(const contact* p) //打印联系人信息 不修改
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",p->data[i].name,
			                                       p->data[i].age,
			                                       p->data[i].sex,
			                                       p->data[i].tele,
			                                       p->data[i].addr);
	}

}

//查找的函数
static int find(contact* p, char* name) //接收参数 两个指针
{ //static修饰 限定使用范围
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)//名字相等
			return i;
	}
	return -1; //下标不为-1
}
void delcontact(contact* p) //删除联系人
{
	char name[max_name]; //存放要删除的人的名字
	if (p->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除的人的名字:>");
	scanf("%s", name);
	//要删除：
	//1.查找要删除的人 有或者没有 
	int pos = find(p, name); //删除的位置 (下标)
	if (pos == -1) //下标不能为-1
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	int i = 0;
	for (i = pos; i < p->sz-1; i++)
	{                                  // 1 2 3 4 5 6 7 8 9 
		p->data[i] = p->data[i+1];   
	}
	p->sz--;
	printf("删除成功\n");
}

void searchcontact(contact* p) //查找联系人
{
	char name[max_name];
	printf("请输入要查找的名字:>");
	scanf("%s", name);
	int pos = find(p, name); //查找的位置 （下标）
	if (pos == -1)
	{
		printf("查找的人不存在\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", p->data[pos].name,
		                                        p->data[pos].age,
		                                        p->data[pos].sex,
		                                        p->data[pos].tele,
		                                        p->data[pos].addr);
}

//修改联系人
void gaicontact(contact* p)
{
	char name[max_name];
	printf("请输入要修改的名字:>");
	scanf("%s", name);
	int pos = find(p, name); //修改的位置 （下标）
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", p->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(p->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", p->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", p->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", p->data[pos].addr);
	
}

//排序联系人
void sortcontact(contact* p)
{  //年龄大的往后排
	int i = 0;
	for (i = 0; i < p->sz-1; i++)
	{
		for (int j = 0; j < p->sz - 1 - i; j++)
		{
			if (p->data[i].age > p->data[i + 1].age)
			{
				people t = { 0 };
				t = p->data[i];
				p->data[i] = p->data[i + 1];
				p->data[i + 1] = t;
			}
		}
		
	}
	printf("排序成功\n");
}