#include "pdm.h"
#include <stdlib.h>
#include <assert.h>
//初始化
void Initsystem(syslist** p)
{
	*p = NULL;
}
void systemmain(syslist** p)
{
	printf("****************    欢迎使用学生体温管理系统    ******************\n");
	printf("\n");
	printf(" 本系统可以实现人员信息的添加、删除、查找、修改、排序、打印等功能\n");
	printf("\n");
	printf("****************     现在请你开始使用本系统     ******************\n");
	printf("\n");
	
		printf("******************************************************************\n");
		printf("*******************     学生体温管理系统     *********************\n");
		printf("*******************        1.登录/注册       *********************\n");
		printf("*******************        2.退出            *********************\n");
		printf("******************************************************************\n");
		int input = 0;
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:
			LoginAndRegister(p);
			break;
		case 2:
			printf("退出登录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
}

//主面板
void menu()
{
	printf("********************     即将进入菜单栏     **********************\n");
	printf("******************************************************************\n");
	printf("********************  1. 添加      2. 删除  **********************\n");
	printf("********************  3. 查找      4. 修改  **********************\n");
	printf("********************  5. 排序      6. 打印  **********************\n");
	printf("********************  7. 统计      8. 文件  **********************\n");
	printf("********************  0. 退出        -选择  **********************\n");
	printf("******************************************************************\n");
}
enum option
{
	exIt,
	add,
	del,
	search,
	change,
	sort,
	Print,
	Total,
	FilE
};
//面板函数
void Facebook(syslist** p)
{
	int input = 0;
	do
	{
		menu();
		printf("请选择功能:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addsystem(p); //增加
			printf("\n");
			break;
		case del: //删除
			delsystem(p);
			printf("\n");
			break;
		case search:
			searchsystem(p); //查找
			printf("\n");
			break;
		case change: //修改
			changesystem(p);
			printf("\n");
			break;
		case sort: //排序
			sortsystem(p);
			printf("\n");
			break;
		case Print:
			printsystem(p); //打印
			printf("\n");
			break;
		case Total:
			totalsystem(p);//统计信息个数
			printf("\n");
			break;
		case FilE:
			File(p);
			printf("\n");
			break;
		case exIt:
			//销毁系统
			destroysystem(p);
			printf("退出管理系统\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}

//登录注册系统
void LoginAndRegister(syslist** p)
{
	char NAME[max_name] = "guanli";
	char WORD[max_word] = "123456";
	char name[max_name];
	char word[max_word];
	char username[max_name];
	char password[max_word];
	int n = 0; int input = 0;
	while (1)
	{
		printf("******************************************************************\n");
		printf("***********************  管理员登录系统  *************************\n");
		printf("***********************      1.注册      *************************\n");
		printf("***********************      2.登录      *************************\n");
		printf("***********************      3.退出      *************************\n");
		printf("******************************************************************\n");
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			char ch[max_name] = {0};
			rl t = { 0 };
			printf("请输入用户名:>");
			scanf("%s", t.user_name);
			strcpy(ch, t.user_name);
			printf("请输入密码:>");
			int i = 0;
			int is_b = 0;
			char c;
			while (1) 
			{
				c = getch();
				if (c == '\r') 
				{
					if (is_b == 1) 
					{
						t.pass_word[i] = 0;
					}
					break;
				}
				else if (c == '\b') 
				{
					is_b = 1;
					printf("\b \b");
					--i;
				}
				else 
				{
					t.pass_word[i++] = c;
					printf("*");
				}
			}
			t.pass_word[i] = '\0';
			printf("\n");
			printf("注册成功\n");
			
			FILE* pf;
			//打开文件
			pf = fopen(ch, "wt");
			if (pf == NULL)
			{
				printf("打开文件失败\n");
				return;
			}
			//保存操作	
			fprintf(pf, "%s\n",t.pass_word);
			//关闭文件 
			fclose(pf); pf = NULL;
			break;
		}
		case 2:
		{
			printf("请输入用户名:>");
			scanf("%s", name);
			FILE* pf;
			pf = fopen(name, "r+");
			if (pf == NULL)
			{
				printf("打开文件失败\n");
				printf("用户不存在\n");
				return;
			}
			char password[max_word];
			fscanf(pf, "%s\n", password);
			char word[max_word];
			int n = 1;
			while (n <= 3)
			{
				printf("请输入密码:>");
				int i = 0;
				int is_b = 0;
				char c;
				while (1)
				{
					c = getch();
					if (c == '\r')
					{
						if (is_b == 1)
						{
							word[i] = 0;
						}
						break;
					}
					else if (c == '\b')
					{
						is_b = 1;
						printf("\b \b");
						--i;
					}
					else {
						word[i++] = c;
						printf("*");
					}
				}
				word[i] = '\0';
				printf("\n");
				if (strcmp(word, password) == 0 || strcmp(word, WORD) == 0)
				{
					printf("\n");
					printf("******************************************************************\n");
					printf("*******************      恭喜您登录成功!       *******************\n");
					printf("*******************    现在您可以开始使用了    *******************\n");
					printf("******************************************************************\n");
					printf("\n\n");
					Facebook(p);
					return;
				}
				else
				{
					printf("密码错误，请重新输入:>\n");
				}
				n++;
			}
			if (n >= 3)
			{
				printf("密码多次不正确，请确认好再登录\n");
			}
			break;
			fclose(pf); pf = NULL;
		}
		case 3:
			printf("退出登录\n");
			return;
		default:
			printf("输入错误\n");
			break;
		}
	}
}


//打印表
void printsystem(syslist** p)
{
	if (*p == NULL)
	{
		printf("没有存入信息,无法进行打印\n");
		return;
	}
	syslist* cur = *p;
	printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话","地址","隔离地址");
	while (cur != NULL)
	{
		printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", cur->data.name,cur->data.num, cur->data.tem,
			                                       cur->data.id, cur->data.tele, cur->data.addr,cur->data.addr2);
		cur = cur->next;
	}
}
void menu0()
{
	printf("**********************************\n");
	printf("**********   统计操作   **********\n");
	printf("**********  1.全部信息  **********\n");
	printf("**********  2.体温信息  **********\n");
	printf("**********  3.隔离信息  **********\n");
	printf("**********  4.组合信息  **********\n");
	printf("**********    0.退出    **********\n");
	printf("**********************************\n");
}
enum option0
{
	QUit,All,TEm,Div,TAM
};
syslist* findsystem_tem(syslist* phead)
{
	syslist* cur = phead;
	while (cur)
	{
		if (cur->data.tem >= 38.50)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//统计信息个数
void totalsystem(syslist** p)
{
	int input = 0;
	do
	{
		menu0();
		printf("请选择要统计的信息:>");
		scanf("%d", &input);
		switch (input)
		{
		case All:
		{
			int cnt = 0;
			syslist* cur = *p;
			while (cur != NULL)
			{
				cur = cur->next;
				cnt++;
			}
			printf("存入的人员信息个数为：%d\n\n", cnt);
			break;
		}
		case TEm:
		{
			double t = 0;
			printf("请输入要统计多少体温以上的人员数量(输入体温):>");
			scanf("%lf", &t);
			int cnt = 0;
			syslist* cur = *p;
			while (cur != NULL )
			{
				if (cur->data.tem > t)
					cnt++;
				cur = cur->next;
			}
			printf("体温在此温度以上的人员共有:%d\n\n", cnt);
			break;
		}
		case Div:
		{
			int cnt = 0;
			syslist* cur = *p;
			while (cur != NULL)
			{
				if (cur->data.tem > 38.50)
					cnt++;
				cur = cur->next;
			}
			printf("需要隔离的人员(体温在38.5以上)数量为:%d\n\n", cnt);
			printf("请选择是否隔离这些人员(1或者0):>");
			enum choice
			{
				n,y
			};
			int put = 0; scanf("%d", &put);
			switch (put)
			{
			case y:
			{
		        for(int i=1;i<=cnt;i++)
				{
					syslist* pos = findsystem_tem(*p);
					if (pos != NULL)
					{
						printf("需要隔离的人员信息如下:\n");
						printsystem(&pos);
						printf("请输入第%d人的隔离地址:>",i);
						char tmp[max_addr] = { 0 };
						scanf("%s", tmp);
						strcpy(pos->data.addr2, tmp);
						printf("输入成功\n");
					}
					else
						return;
				}
				break;
			}
			case n:
				printf("不需要进行隔离操作\n"); break;
			default:
				printf("选择错误\n"); break;
			}
			break;
		}
		case TAM:
		{
			int input = 0;
			do
			{
				printf("************************************\n");
				printf("************ 1.个人地址 ************\n");
				printf("************ 2.隔离地址 ************\n");
				printf("************   0.退出   ************\n");
				printf("************************************\n");
			    
				printf("请选择要进行组合统计的方式:>");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
				{
					char addr[max_addr]; double t;
					printf("请输入要统计多少温度以上的某个相同地址的人数:>\n");
					printf("请输入温度:>"); scanf("%lf", &t);
					printf("请输入个人地址:>"); scanf("%s", addr);
					int cnt = 0;
					syslist* cur = *p;
					while (cur != NULL)
					{
						if (cur->data.tem >= t && strcmp(cur->data.addr, addr) == 0)
						{
							printf("人员信息如下:>\n");
							printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址", "隔离地址");
							printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", cur->data.name, cur->data.num, cur->data.tem,
								                                       cur->data.id, cur->data.tele, cur->data.addr, cur->data.addr2);
							cnt++;
						}
						cur = cur->next;
					}
					printf("组合统计的信息个数共有:> %d个\n", cnt);
					break;
				}
				case 2:
				{
					char addr2[max_addr]; double t;
					printf("请输入要统计多少温度以上的某个相同地址的人数:>\n");
					printf("请输入温度:>"); scanf("%lf", &t);
					printf("请输入隔离地址:>"); scanf("%s", addr2);
					int cnt = 0;
					syslist* cur = *p;
					while (cur != NULL)
					{
						if (cur->data.tem >= t && strcmp(cur->data.addr2, addr2) == 0)
						{
							printf("人员信息如下:>\n");
							printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址", "隔离地址");
							printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", cur->data.name, cur->data.num, cur->data.tem,
									                                   cur->data.id, cur->data.tele, cur->data.addr, cur->data.addr2);
							cnt++;
						}
						cur = cur->next;
					}
					printf("组合统计的信息个数共有:> %d个\n", cnt);
					break;
				}
				case 0:
					printf("退出功能\n"); break;
				default:
					printf("输入错误\n"); break;
				}
			} while (input);
			break;
		}
		case QUit:
			printf("退出统计操作\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}

//输入信息
void pushsystem(people* data)
{
	printf("请输入姓名:>");
	scanf("%s", data->name);
	printf("请输入学号:>");
	scanf("%s", data->num);
	printf("请输入体温(35-42):>");
	scanf("%lf", &data->tem);
	{
		for (int i = 1; i <= 3; i++)
		{
			if (data->tem < 35 || data->tem>42)
			{
				printf("请重新输入:>");
				scanf("%lf", &data->tem);
				if (data->tem >= 35 && data->tem <= 42)
					break;
			}
		}
	}
	printf("请输入身份证号码(18位):>");
	scanf("%s", data->id);
	{
		for (int i = 1; i <= 3; i++)
		{
			if (strlen(data->id) != 18)
			{
				printf("请重新输入:>");
				scanf("%s", data->id);
				if (strlen(data->id) == 18)
					break;
			}
		}
	}
	printf("请输入电话(11位):>");
	scanf("%s", data->tele);
	{
		for (int i = 1; i <= 3; i++)
		{
			if (strlen(data->tele) != 11)
			{
				printf("请重新输入:>");
				scanf("%s", data->tele);
				if (strlen(data->tele) == 11)
					break;
			}
		}
	}
	printf("请输入住址:>");
	scanf("%s", data->addr);
	printf("请输入隔离地址:>");
	scanf("%s", data->addr2);

	printf("输入成功\n");
}
//添加信息的菜单
void menu1()
{
	printf("********************************************\n");
	printf("**********   1.在某学号之后添加   **********\n");
	printf("**********   2.在某学号之前添加   **********\n");
	printf("**********   3.在表的最后添加     **********\n");
	printf("**********   0.退出添加   --选择  **********\n");
	printf("********************************************\n");
}
enum option1
{
	QUIT,After,Front,Rear
};
//增加(尾插)
void addsystem(syslist** p)
{
	int input = 0; char num[max_num];
	do
	{
		menu1();
		printf("请选择您要添加信息的地方:>");
		scanf("%d", &input);
		switch (input)
		{
		case After:
		{
			printf("请输入要在哪个的学号之后添加(输入学号):>");
			scanf("%s", num);
			syslist* pos = findsystem_num(*p, num); //找到pos位置-通过学号
			if (pos == NULL)
			{
				printf("不存在此学号\n"); break;
			}
			//输入信息
			people data = { 0 };
			pushsystem(&data);
			//创建新的节点
			syslist* newnode = (syslist*)malloc(sizeof(syslist));
			if (newnode == NULL)
			{
				perror("addsystem");
				return;
			}
			newnode->data = data;
			newnode->next = NULL;

			syslist* next = pos->next;
			pos->next = newnode;
			newnode->next = next;
			printf("添加成功\n"); break;
		}
		case Front:
		{
			printf("请输入要在哪个的学号之前添加(输入学号):>");
			scanf("%s", num);
			syslist* pos = findsystem_num(*p, num); //找到pos位置
			if (pos == NULL)
			{
				printf("不存在此学号\n"); break;
			}
			//输入信息
			people data = { 0 };
			pushsystem(&data);
			//创建新的节点
			syslist* newnode = (syslist*)malloc(sizeof(syslist));
			if (newnode == NULL)
			{
				perror("addsystem");
				return;
			}
			newnode->data = data;
			newnode->next = NULL;

			if (pos == *p)//查找到的节点就是头节点
			{
				//头插
				newnode->next = pos;
				*p = newnode;
			}
			else
			{
				//找到pos的前一个节点
				syslist* posprev = *p;
				while (posprev->next != pos)
				{
					posprev = posprev->next;
				}
				posprev->next = newnode;
				newnode->next = pos;
			}
			printf("添加成功\n"); break;
		}
		case Rear:
		{
			//输入信息
			people data = { 0 };
			pushsystem(&data);
			//创建新的节点
			syslist* newnode = (syslist*)malloc(sizeof(syslist));
			if (newnode == NULL)
			{
				perror("addsystem");
				return;
			}
			newnode->data = data;
			newnode->next = NULL;
			//尾插
			if (*p == NULL)
			{
				*p = newnode;
			}
			else//找尾节点
			{
				syslist* tail = *p;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = newnode;
			}
			printf("添加成功\n"); break;
		}
		case QUIT:
			printf("退出添加\n");
			break;
		default:
			printf("输入错误\n"); break;
		}
	} while (input);
}
//判断是否有重名
int countif(syslist** p,char* name)
{
	int cnt = 0;
	syslist* cur = *p;
	while (cur != NULL)
	{
		if (strcmp(cur->data.name, name) == 0)
			cnt++;
		cur = cur->next;
	}
	return cnt;
}
//查找有没有此人-姓名
syslist* findsystem_name(syslist* phead, char* name)
{
	syslist* cur = phead;
	while (cur)
	{
		if (strcmp(cur->data.name,name)==0)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//查找有没有此人-学号
syslist* findsystem_num(syslist* phead, char* num)
{
	syslist* cur = phead;
	while (cur)
	{
		if (strcmp(cur->data.num, num) == 0)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//查找有没有此人-身份证
syslist* findsystem_id(syslist* phead, char* id)
{
	syslist* cur = phead;
	while (cur)
	{
		if (strcmp(cur->data.id, id) == 0)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
void menu2()
{
	printf("******************************************\n");
	printf("***********    1.姓名          ***********\n");
	printf("***********    2.学号          ***********\n");
	printf("***********    3.身份证        ***********\n");
	printf("***********    0.退出  --选择  ***********\n");
	printf("******************************************\n");
}
enum option2
{
	Back,
	NaMe,
	NuM,
	ID
};
//删除人员信息
void delsystem(syslist** p)
{
	if (*p == NULL)
	{
		printf("系统内未存入任何人员信息\n");
		return;
	}
	int input = 0;
	do
	{
		menu2();
		printf("请选择通过什么方式删除:>");
		scanf("%d", &input);
		switch (input)
		{
		case NaMe:
		{
			char name[max_name];//要删除的人的名字
			printf("请输入要删除的人的姓名:>");
			scanf("%s", name);
			syslist* pos = findsystem_name(*p, name);
			if (pos == NULL)
			{
				printf("要删除的人不存在\n");
				return;
			}
			if (countif(p,name) > 1)
			{
				printf("存在重名的人员,请选择其他删除方法\n");
				menu2();
				printf("请选择通过什么方式删除信息:>");
				int m = 0; scanf("%d", &m);
				switch (m)
				{
				case NuM:
				{
					char num[max_num];//要查找的人的学号
					printf("请输入要删除的人的学号:>");
					scanf("%s", num);
					syslist* pos = findsystem_num(*p, num);
					if (pos == NULL)
					{
						printf("要删除的人不存在\n");
						return;
					}
					if (pos == *p)
					{
						*p = pos->next;
						free(pos);
						pos = *p;
					}
					else
					{
						syslist* prev = *p;
						while (prev->next != pos)
						{
							prev = prev->next;
						}
						prev->next = pos->next;
						free(pos);
						pos = NULL;
					}
					printf("删除人员信息成功\n\n");
					break;
				}
				case ID:
				{
					char id[max_id];
					printf("请输入要删除的人的身份证:>");
					scanf("%s", id);
					syslist* pos = findsystem_id(*p, id);
					if (pos == NULL)
					{
						printf("要删除的人不存在\n");
						return;
					}
					if (pos == *p)
					{
						*p = pos->next;
						free(pos);
						pos = *p;
					}
					else
					{
						syslist* prev = *p;
						while (prev->next != pos)
						{
							prev = prev->next;
						}
						prev->next = pos->next;
						free(pos);
						pos = NULL;
					}
					printf("删除人员信息成功\n\n");
					break;
				}
				case Back:
					printf("退出删除功能\n");
					break;
				default:
					printf("输入错误\n");
					break;
				}
			}
			else
			{
				if (pos == *p)
				{
					*p = pos->next;
					free(pos);
					pos = *p;
				}
				else
				{
					syslist* prev = *p;
					while (prev->next != pos)
					{
						prev = prev->next;
					}
					prev->next = pos->next;
					free(pos);
					pos = NULL;
				}
				printf("删除人员信息成功\n\n");
				break;
			}
			break;
		}
		case NuM:
		{
			char num[max_num];//要查找的人的学号
			printf("请输入要删除的人的学号:>");
			scanf("%s", num);
			syslist* pos = findsystem_num(*p, num);
			if (pos == NULL)
			{
				printf("要删除的人不存在\n");
				return;
			}
			if (pos == *p)
			{
				*p = pos->next;
				free(pos);
				pos = *p;
			}
			else
			{
				syslist* prev = *p;
				while (prev->next != pos)
				{
					prev = prev->next;
				}
				prev->next = pos->next;
				free(pos);
				pos = NULL;
			}
			printf("删除人员信息成功\n\n");
			break;
		}
		case ID:
		{
			char id[max_id];
			printf("请输入要删除的人的身份证:>");
			scanf("%s", id);
			syslist* pos = findsystem_id(*p, id);
			if (pos == NULL)
			{
				printf("要删除的人不存在\n");
				return;
			}
			if (pos == *p)
			{
				*p = pos->next;
				free(pos);
				pos = *p;
			}
			else
			{
				syslist* prev = *p;
				while (prev->next != pos)
				{
					prev = prev->next;
				}
				prev->next = pos->next;
				free(pos);
				pos = NULL;
			}
			printf("删除人员信息成功\n\n");
			break;
		}
		case Back:
			printf("退出删除功能\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}

//查找人员信息功能的菜单
void menu3()
{
	printf("******************************************\n");
	printf("***********    1.姓名          ***********\n");
	printf("***********    2.学号          ***********\n");
	printf("***********    3.身份证        ***********\n");
	printf("***********    0.退出  --选择  ***********\n");
	printf("******************************************\n");
}
enum option3
{
	EXIT,
	name,
	num,
	id
};
//查找一个人的信息-三种方法
void searchsystem(syslist** p)
{
	if (*p == NULL)
	{
		printf("系统内未存入任何人员信息\n");
		return;
	}
	int input = 0;
	do
	{
		menu3();
		printf("请选择通过什么方式查找信息:>");
		scanf("%d", &input);
		switch (input)
		{
		case name:
		{
			char name[max_name];//要查找的人的名字
			printf("请输入要查找的人的姓名:>");
			scanf("%s", name);
			syslist* pos = findsystem_name(*p, name);
			if (pos == NULL)
			{
				printf("要查找的人不存在\n");
				return;
			}
			if (countif(p, name) > 1)
			{
				printf("存在重名的人员,请选择其他查询方法\n"); 
				menu3();
				printf("请选择通过什么方式查找信息:>");
				int m = 0; scanf("%d", &m);
				switch (m)
				{
				case num:
				{
					char num[max_num];//要查找的人的学号
					printf("请输入要查找的人的学号:>");
					scanf("%s", num);
					syslist* pos = findsystem_num(*p, num);
					if (pos == NULL)
					{
						printf("要查找的人不存在\n");
						return;
					}
					printf("此人存在，其信息如下：\n");
					printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址","隔离地址");
					printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", pos->data.name, pos->data.num, pos->data.tem,
						                                    pos->data.id, pos->data.tele, pos->data.addr,pos->data.addr2);
					printf("\n");
					break;
				}
				case id:
				{
					char id[max_id];//要查找的人的学号
					printf("请输入要查找的人的身份证:>");
					scanf("%s", id);
					syslist* pos = findsystem_id(*p, id);
					if (pos == NULL)
					{
						printf("要查找的人不存在\n");
						return;
					}
					printf("此人存在，其信息如下：\n");
					printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址", "隔离地址");
					printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", pos->data.name, pos->data.num, pos->data.tem,
						                                   pos->data.id, pos->data.tele, pos->data.addr, pos->data.addr2);
					printf("\n");
					break;
				}
				case EXIT:
					printf("退出查询\n");
					break;
				default:
					printf("输入错误\n");
					break;
				}
			}
			else
			{
				printf("此人存在，其信息如下：\n");
				printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址", "隔离地址");
				printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", pos->data.name, pos->data.num, pos->data.tem,
					                                       pos->data.id, pos->data.tele, pos->data.addr, pos->data.addr2);
				printf("\n");
			}
			break;
		}
		case num:
		{
			char num[max_num];//要查找的人的学号
			printf("请输入要查找的人的学号:>");
			scanf("%s", num);
			syslist* pos = findsystem_num(*p, num);
			if (pos == NULL)
			{
				printf("要查找的人不存在\n");
				return;
			}
			printf("此人存在，其信息如下：\n");
			printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址","隔离地址");
			printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", pos->data.name, pos->data.num, pos->data.tem,
				                                        pos->data.id, pos->data.tele, pos->data.addr,pos->data.addr2);
			printf("\n");
			break;
		}
		case id:
		{
			char id[max_id];//要查找的人的学号
			printf("请输入要查找的人的身份证:>");
			scanf("%s", id);
			syslist* pos = findsystem_id(*p, id);
			if (pos == NULL)
			{
				printf("要查找的人不存在\n");
				return;
			}
			printf("此人存在，其信息如下：\n");
			printf("%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址", "隔离地址");
			printf("%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", pos->data.name, pos->data.num, pos->data.tem,
				                                       pos->data.id, pos->data.tele, pos->data.addr, pos->data.addr2);
			printf("\n");
			break;
		}
		case EXIT:
			printf("退出查询\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}

//修改信息的菜单
void menu4()
{
	printf("******************************************\n");
	printf("***********    1.姓名          ***********\n");
	printf("***********    2.学号          ***********\n");
	printf("***********    3.身份证        ***********\n");
	printf("***********    0.退出  --选择  ***********\n");
	printf("******************************************\n");
}
enum option4
{
	Tui,Nm,Nu,I
};
void menu4_2()
{
	printf("*****************************************\n");
	printf("**********   1.姓名  2.学号    **********\n");
	printf("**********   3.体温  4.身份证  **********\n");
	printf("**********   5.电话  6.地址    **********\n");
	printf("**********   7.隔离地址        **********\n");
	printf("**********   0.退出            **********\n");
	printf("*****************************************\n");
}
enum option4_2
{
	Exit,Name,Num,Tem,Id,Tele,Addr,Addr2
};
//修改一个人的信息
void changesystem(syslist** p)
{
	char name[max_name];//要修改的人的名字
	if (*p == NULL)
	{
		printf("系统内未存入任何人员信息\n");
		return;
	}
	printf("请输入要修改的人的姓名:>");
	scanf("%s", name);
	syslist* pos = findsystem_name(*p, name);
	if (pos == NULL)
	{
		printf("此人不存在\n");
		return;
	}
	if (countif(p, name) > 1)
	{
		printf("存在重名的人员,请选择其他方法\n");
		menu4();
		printf("请选择通过什么方式找到要修改的人员:>");
		int m = 0; scanf("%d", &m);
		switch(m)
		{
		case Nu:
		{
			char num[max_num];//要查找的人的学号
			printf("请输入要修改的人的学号:>");
			scanf("%s", num);
			syslist* pos = findsystem_num(*p, num);
			if (pos == NULL)
			{
				printf("此人不存在\n");
				return;
			}
			else
			{
				printf("此人存在\n");
				int input = 0;
				do
				{
					menu4_2();
					printf("请选择要修改的信息:>");
					scanf("%d", &input);
					switch (input)
					{
					case Name:
						printf("请输入修改后的姓名:>");
						scanf("%s", pos->data.name);
						printf("修改成功\n\n");
						break;
					case Num:
						printf("请输入修改后的学号:>");
						scanf("%s", pos->data.num);
						printf("修改成功\n\n");
						break;
					case Tem:
						printf("请输入修改后的温度:>");
						scanf("%lf", &pos->data.tem);
						printf("修改成功\n\n");
						break;
					case Id:
						printf("请输入修改后的身份证号:>");
						scanf("%s", pos->data.id);
						printf("修改成功\n\n");
						break;
					case Tele:
						printf("请输入修改后的电话:>");
						scanf("%s", pos->data.tele);
						printf("修改成功\n\n");
						break;
					case Addr:
						printf("请输入修改后的地址:>");
						scanf("%s", pos->data.addr);
						printf("修改成功\n\n");
						break;
					case Addr2:
						printf("请输入修改后的隔离地址:>");
						scanf("%s", pos->data.addr2);
						printf("修改成功\n\n");
						break;
					case Exit:
						printf("退出修改\n");
						break;
					default:
						printf("输入错误\n");
						break;
					}
				} while (input);
				printf("修改成功\n");
			}
			break;
		}
		case I:
		{
			char id[max_id];//要查找的人的学号
			printf("请输入要查找的人的身份证:>");
			scanf("%s", id);
			syslist* pos = findsystem_id(*p, id);
			if (pos == NULL)
			{
				printf("要查找的人不存在\n");
				return;
			}
			else
			{
				printf("此人存在\n");
				int input = 0;
				do
				{
					menu4_2();
					printf("请选择要修改的信息:>");
					scanf("%d", &input);
					switch (input)
					{
					case Name:
						printf("请输入修改后的姓名:>");
						scanf("%s", pos->data.name);
						printf("修改成功\n\n");
						break;
					case Num:
						printf("请输入修改后的学号:>");
						scanf("%s", pos->data.num);
						printf("修改成功\n\n");
						break;
					case Tem:
						printf("请输入修改后的温度:>");
						scanf("%lf", &pos->data.tem);
						printf("修改成功\n\n");
						break;
					case Id:
						printf("请输入修改后的身份证号:>");
						scanf("%s", pos->data.id);
						printf("修改成功\n\n");
						break;
					case Tele:
						printf("请输入修改后的电话:>");
						scanf("%s", pos->data.tele);
						printf("修改成功\n\n");
						break;
					case Addr:
						printf("请输入修改后的地址:>");
						scanf("%s", pos->data.addr);
						printf("修改成功\n\n");
						break;
					case Addr2:
						printf("请输入修改后的隔离地址:>");
						scanf("%s", pos->data.addr2);
						printf("修改成功\n\n");
						break;
					case Exit:
						printf("退出修改\n");
						break;
					default:
						printf("输入错误\n");
						break;
					}
				} while (input);
				printf("修改成功\n");
			}
			break;
		}
		case Tui:
			printf("退出操作\n"); break;
		default:
			printf("输入错误\n"); break;
		}
	}
	else
	{
		printf("此人存在\n");
		int input = 0;
		do
		{
			menu4_2();
			printf("请选择要修改的信息:>");
			scanf("%d", &input);
			switch (input)
			{
			case Name:
				printf("请输入修改后的姓名:>");
				scanf("%s", pos->data.name);
				printf("修改成功\n\n");
				break;
			case Num:
				printf("请输入修改后的学号:>");
				scanf("%s", pos->data.num);
				printf("修改成功\n\n");
				break;
			case Tem:
				printf("请输入修改后的温度:>");
				scanf("%lf", &pos->data.tem);
				printf("修改成功\n\n");
				break;
			case Id:
				printf("请输入修改后的身份证号:>");
				scanf("%s", pos->data.id);
				printf("修改成功\n\n");
				break;
			case Tele:
				printf("请输入修改后的电话:>");
				scanf("%s", pos->data.tele);
				printf("修改成功\n\n");
				break;
			case Addr:
				printf("请输入修改后的地址:>");
				scanf("%s", pos->data.addr);
				printf("修改成功\n\n");
				break;
			case Addr2:
				printf("请输入修改后的隔离地址:>");
				scanf("%s", pos->data.addr2);
				printf("修改成功\n\n");
				break;
			case Exit:
				printf("退出修改\n");
				break;
			default:
				printf("输入错误\n");
				break;
			}
		} while (input);
		printf("修改成功\n");
	}
}
//排序的菜单
void menu5()
{
	printf("*******************************************\n");
	printf("*******   1.学号升序   2.学号降序   *******\n");
	printf("*******   3.字符升序   4.字符降序   *******\n");
	printf("*******   0.退出排序       --选择   *******\n");
	printf("*******************************************\n");
}
enum option5
{
	Quit,Up,Down,Sup,Sdown
};
//排序 学号,字符串
void sortsystem(syslist** p)
{
	if (*p == NULL)
	{
		printf("系统中无任何信息，无需排序\n");
		return;
	}
	if ((*p)->next == NULL)
	{
		printf("系统中只有一个人员信息，无需排序\n");
		return;
	}
	int input = 0;
	do
	{
		menu5();
		printf("请选择排序方法:>");
		scanf("%d", &input);
		switch (input)
		{
		case Up:
		{
			syslist* cur = *p;
			syslist* flag = NULL;
			while (cur->next != NULL)
			{
				flag = cur->next;
				while (flag != NULL)
				{
					if (strcmp(flag->data.num, cur->data.num) < 0)
					{
						syslist tmp = { 0 };
						tmp = *cur; *cur = *flag; *flag = tmp;
						tmp.next = cur->next;
						cur->next = flag->next;
						flag->next = tmp.next;
					}
					flag = flag->next;
				}
				cur = cur->next;
			}
			printf("排序成功\n"); break;
		}
		case Down:
		{
			syslist* cur = *p;
			syslist* flag = NULL;
			while (cur->next != NULL)
			{
				flag = cur->next;
				while (flag != NULL)
				{
					if (strcmp(flag->data.num, cur->data.num) > 0)
					{
						syslist tmp = { 0 };
						tmp = *cur; *cur = *flag; *flag = tmp;
						tmp.next = cur->next;
						cur->next = flag->next;
						flag->next = tmp.next;
					}
					flag = flag->next;
				}
				cur = cur->next;
			}
			printf("排序成功\n"); break;
		}
		case Sup:
		{
			syslist* cur = *p;
			syslist* flag = NULL;
			while (cur->next != NULL)
			{
				flag = cur->next;
				while (flag != NULL)
				{
					if (strcmp(flag->data.name, cur->data.name) < 0)
					{
						syslist tmp = { 0 };
						tmp = *cur; *cur = *flag; *flag = tmp;
						tmp.next = cur->next;
						cur->next = flag->next;
						flag->next = tmp.next;
					}
					flag = flag->next;
				}
				cur = cur->next;
			}
			printf("排序成功\n"); break;
		}
		case Sdown:
		{
			{
				syslist* cur = *p;
				syslist* flag = NULL;
				while (cur->next != NULL)
				{
					flag = cur->next;
					while (flag != NULL)
					{
						if (strcmp(flag->data.name, cur->data.name) > 0)
						{
							syslist tmp = { 0 };
							tmp = *cur; *cur = *flag; *flag = tmp;
							tmp.next = cur->next;
							cur->next = flag->next;
							flag->next = tmp.next;
						}
						flag = flag->next;
					}
					cur = cur->next;
				}
				printf("排序成功\n"); break;
			}
		}
		case Quit:
			printf("退出排序\n"); break;
		default:
			printf("输入错误\n"); break;
		}
	} while (input);
	
}
//文件的菜单
void menu6()
{
	printf("********************************\n");
	printf("**********  文件操作   *********\n");
	printf("**********   1.存储    *********\n");
	printf("**********   2.写入    *********\n");
	printf("**********   3.读入    *********\n");
	printf("**********   0.退出    *********\n");
	printf("********************************\n");
}
enum option6
{
	ExIT, St, Wr, Re
};
syslist* Read(syslist** p)
{
	FILE* pf;
	char fileName[40];
	printf("请输入要读取的文件名:>");
	scanf("%s", fileName);
	pf = fopen(fileName, "r+");
	if (pf == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	syslist* node;
	while (!feof(pf))
	{
		node = (syslist*)malloc(sizeof(syslist));
		assert(node);
		people data = { 0 };
		static char name[max_name];//姓名
		static char num[max_num];//学号
		static double tem;//体温
		static char id[max_id];//身份证
		static char tele[max_tele];//手机号码
		static char addr[max_addr];//地址
		static char addr2[max_addr];//隔离地址
		fscanf(pf, "%s%s%lf%s%s%s%s\n", name, num, &tem, id, tele, addr,addr2);
		strcpy(data.name, name);
		strcpy(data.num, num);
		data.tem = tem;
		strcpy(data.id, id);
		strcpy(data.tele, tele);
		strcpy(data.addr, addr);
		strcpy(data.addr2, addr2);
		node->data = data;
		node->next = NULL;
		if (*p == NULL)
		{
			*p = node;
		} 
		else//找尾节点
		{
			syslist* tail = *p;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = node;
		}
	}
	fclose(pf); pf = NULL;
	printf("读取成功\n\n");
	return p;
}
void File(syslist** p)
{
	int input = 0;
	do 
	{
		menu6();
		printf("请选择对文件的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case St:
		{
			if (*p == NULL)
			{
				printf("系统中无任何信息，无法存储文件\n");
				return;
			}
			syslist* cur = *p;
			FILE* pf;
			char fileName[20]; 
			printf("请输入文件名:>");
			scanf("%s", fileName);
			//异常预处理
			if (cur == NULL)
			{
				printf("节点为空，保存失败\n");
				return;
			}
			//打开文件
			pf = fopen(fileName, "wt");
			if (pf == NULL)
			{
				printf("打开文件失败\n");
				return;
			}

			//fprintf(pf, "%-12s\t%-15s\t%s\t%-20s\t%-12s\t%-20s\n", "姓名", "学号", "体温", "身份证号", "电话", "地址");
			//保存操作	
			while (cur != NULL)
			{
				fprintf(pf, "%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", cur->data.name, cur->data.num, cur->data.tem, 
					                                               cur->data.id, cur->data.tele, cur->data.addr,cur->data.addr2);
				cur = cur->next;
			}
			//关闭文件 
			fclose(pf); pf = NULL;
			printf("已保存\n\n");
			break;
		}
		case Wr:
		{
			FILE* pf;
			char fileName[20];
			printf("请输入要写入的文件名:>");
			scanf("%s", fileName);

			pf = fopen(fileName, "ab");
			if (pf == NULL)
			{
				printf("打开文件失败\n");
				return;
			}
			people data = { 0 };
			pushsystem(&data);
			fprintf(pf, "%-12s\t%-15s\t%.2lf\t%-20s\t%-12s\t%-20s\t%-20s\n", data.name, data.num, data.tem, data.id, 
				                                                            data.tele, data.addr,data.addr2);
			fclose(pf); pf = NULL;
			printf("信息已写入文件\n\n"); 
			break;
		}
		case Re:
		{
			p = Read(p);
			break;
		}
		case ExIT:
			printf("退出文件操作\n\n"); break;
		default:
			printf("输入错误\n"); break;
		}
	} while (input);
}

//销毁系统
void destroysystem(syslist** p)
{
	*p = NULL;
	printf("*****************      期待您的再次使用        *****************\n");
}