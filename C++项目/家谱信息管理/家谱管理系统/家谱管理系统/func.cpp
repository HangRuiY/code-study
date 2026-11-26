#include "Sys.h"
#include <conio.h>
void sysmain()
{
	printf("****************      欢迎使用家谱管理系统      ******************\n");
	printf("\n");
	printf("****************     现在请你开始使用本系统     ******************\n");
	printf("\n");
	printf("******************************************************************\n");
	printf("*******************       家谱管理系统       *********************\n");
	printf("*******************        1.登录/注册       *********************\n");
	printf("*******************        0.退出            *********************\n");
	printf("******************************************************************\n");
	int input = 0;
	printf("请选择:>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		LoginAndRegister();
		break;
	case 0:
		printf("退出登录\n");
		break;
	default:
		printf("选择错误\n");
		break;
	}
}
void LoginAndRegister()
{
	char NAME[20] = "guanli";
	char WORD[20] = "123456";
	char name[20];
	char word[20];
	char username[20];
	char password[20];
	int n = 0; int input = 0;
	while (1)
	{
		printf("******************************************************************\n");
		printf("***********************  管理员登录系统  *************************\n");
		printf("***********************      1.注册      *************************\n");
		printf("***********************      2.登录      *************************\n");
		printf("***********************      0.退出      *************************\n");
		printf("******************************************************************\n");
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			char ch[20] = { 0 };
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
			fprintf(pf, "%s\n", t.pass_word);
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
			char password[20];
			fscanf(pf, "%s\n", password);
			char word[20];
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
					tree* t = NULL;
					t = InitTree();
					Facebook(&t);
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
		case 0:
			printf("退出登录\n");
			return;
		default:
			printf("输入错误\n");
			break;
		}
	}
}
//主面板
void menu()
{
	printf("********************     即将进入菜单栏     **********************\n");
	printf("******************************************************************\n");
	printf("********************  1. 添加      2. 删除  **********************\n");
	printf("********************  3. 查找      4. 修改  **********************\n");
	printf("********************  5. 统计      6. 打印  **********************\n");
	printf("********************  7. 文件      0. 退出  **********************\n");
	printf("********************                --选择  **********************\n");
	printf("******************************************************************\n");
}
//面板函数
void Facebook(tree** t)
{
	int input = 0;
	do
	{
		menu();
		printf("请选择功能:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addsystem(t); 
			printf("\n");
			break;
		case 2: 
			delsystem(t);
			printf("\n");
			break;
		case 3:
			searchsystem(t); 
			printf("\n");
			break;
		case 4: 
			changesystem(t);
			printf("\n");
			break;
		case 5: 
			totalsystem(t);
			printf("\n");
			break;
		case 6:
			printsystem(t);
			printf("\n");
			break;
		case 7:
			File(t);
			printf("\n");
			break;
		case 0:
			printf("退出管理系统\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
void new_left(tree** p,people info)
{
	tree* q = (tree*)malloc(sizeof(tree));
	q->data = info;
	q->left = q->right = NULL;
	(*p)->left = q;
	q->parent = (*p);
}
void new_right(tree** p, people info)
{
	tree* q = (tree*)malloc(sizeof(tree));
	q->data = info;
	q->left = q->right = NULL;
	(*p)->right = q;
	q->parent = (*p);
}

//tree* InitTree()
//{
//	tree* bt = (tree*)malloc(sizeof(tree));
//	printf("请输入祖先信息:>\n");
//	people human;
//	printf("请输入祖先姓名:>"); scanf("%s", human.name);
//	printf("请输入祖先性别:>"); scanf("%s", human.c);
//	printf("请输入祖先生日:>"); scanf("%s", human.birth);
//	if (strlen(human.birth) != 8)
//	{
//		printf("输入错误数据，请重新输入:>");
//		scanf("%s", human.birth);
//	}
//	int w = 0;
//	printf("请输入祖先结婚情况，已婚输入（1），未婚输入（0）:>"); scanf("%d", &w);
//	if (w == 1)
//		strcpy(human.wed, "已婚");
//	else if (w == 0)
//		strcpy(human.wed, "未婚");
//	else
//	{
//		printf("输入错误，请重新输入:>");
//		scanf("%d", &w);
//		if (w == 1)
//			strcpy(human.wed, "已婚");
//		else if (w == 0)
//			strcpy(human.wed, "未婚");
//	}
//	printf("请输入祖先的地址:>"); scanf("%s", human.addr);
//	int h = 0;
//	printf("请输入祖先健康情况，健在输入（1），否则输入（0）:>"); scanf("%d", &h);
//	if (h == 1)
//		strcpy(human.health, "是");
//	else if (h == 0)
//		strcpy(human.health, "否");
//	else
//	{
//		printf("输入错误，请重新输入:>");
//		scanf("%d", &h);
//		if (h == 1)
//			strcpy(human.health, "是");
//		else if (h == 0)
//			strcpy(human.health, "否");
//	}
//	bt->data = human; 
//	bt->left = bt->parent = bt->right = NULL;
//	printf("祖先信息录入完成\n");
//	return bt;
//}

tree* InitTree()
{
	people human[8] = {  {"张一","男","19450124","已婚","西安","是"},
						 {"张二","男","19510809","已婚","西安","是"},
						 {"张三","男","19500126","已婚","西安","是"},
						 {"张四","女","19781009","已婚","西安","是"},
						 {"张五","男","19820519","已婚","西安","是"},
		                 {"张六","男","19780519","已婚","西安","是"},
						 {"张七","男","20040107","未婚","西安","是"},
						 {"张八","女","20120128","未婚","西安","是"} };
	pe wife[6] = {  {1,"李一","女","19450124","已婚","西安","是"},
		            {1,"李二","女","19510809","已婚","西安","是"},
	                {1,"李三","女","19500126","已婚","西安","是"},
	                {1,"李四","男","19781009","已婚","西安","是"},
	                {1,"李五","女","19820519","已婚","西安","是"},
	                {1,"李六","女","19780519","已婚","西安","是"}  };
	human[0].wife = wife[0];
	human[1].wife = wife[1];
	human[2].wife = wife[2];
	human[3].wife = wife[3];
	human[4].wife = wife[4];
	human[5].wife = wife[5];
	tree* bt;
	bt = (tree*)malloc(sizeof(tree));
	bt->data = human[0];
	bt->left = bt->right = bt->parent = NULL;
	new_left(&bt, human[1]);
	new_right(&bt, human[2]);
	new_left(&(bt->left), human[3]);
	new_right(&(bt->left), human[4]);
	new_left(&(bt->right), human[5]);
	new_left(&(bt->left->right), human[7]);
	new_left(&(bt->right->left), human[6]);
	return bt;
}

//打印菜单
void menu1()
{
	printf("******************************************************************\n");
	printf("********************     请选择打印的方式     ********************\n");
	printf("********************       1.树状打印         ********************\n");
	printf("********************       2.层次打印         ********************\n");
	printf("********************       3.整体打印         ********************\n");
	printf("********************       0.退出             ********************\n");
	printf("******************************************************************\n");
}
//树状打印
void PrintTree1(tree* T, int h)
{
	if (!T)
		return;
	PrintTree1(T->right, h + 1);//打印右子树
	for (int i = 1; i <= h; i++)
	{
		cout << "--->";
	}
	cout << T->data.name << endl;
	PrintTree1(T->left, h + 1);
}
#include <queue>
//层次打印
void PrintTree2(tree* T)
{
	queue<tree*> q;
	tree* bt;
	q.push(T);
	while (!q.empty())
	{
		bt = q.front();
		printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "父/母亲", "婚否", "地址", "健在否");
		printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", bt->data.name, bt->data.c, bt->data.birth, bt->parent->data.name,
			                                                    bt->data.wed, bt->data.addr, bt->data.health);
		if (bt->data.wife.tag==1)
		{
			printf("此人存在配偶，其信息如下:>\n");
			printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日","婚否", "地址", "健在否");
			printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n\n", bt->data.wife.name, bt->data.wife.c, bt->data.wife.birth,
				bt->data.wife.wed, bt->data.wife.addr, bt->data.wife.health);
		}
		q.pop();
		if (bt->left)
			q.push(bt->left);
		if (bt->right)
			q.push(bt->right);
	}
}
//整体打印
void PrintTree3(tree* bt)
{
	queue<tree*>q1, q2;
	int i = 0;
    tree* t;
	if (bt != NULL)
	{
		q1.push(bt);
		while (!q1.empty())
		{
			while (!q1.empty())
			{
				t = q1.front();
				q1.pop();
				q2.push(t);
			}
			i++;
			int k = i;
			printf("第%d代兄弟/姐妹:>\n", k); 
			printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日","父/母亲","婚否", "地址", "健在否");
			while (!q2.empty())
			{
				t = q2.front();
				q2.pop();
				printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", t->data.name, t->data.c, t->data.birth,t->parent->data.name,
					                                           t->data.wed, t->data.addr, t->data.health);
				if (t->left != NULL)
					q1.push(t->left);
				if (t->right != NULL)
					q1.push(t->right);
			}
			printf("\n");
		}
	}
}
//打印
void printsystem(tree** t)
{
	int input = 0;
	do
	{
		menu1();
		printf("请选择打印方式:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("家谱图树状打印如下:>\n");
			PrintTree1(*t,1);
			printf("\n");
			break;
		case 2: 
			printf("家谱图层次打印如下:>\n");
			PrintTree2(*t);
			printf("\n");
			break;
		case 3:
			PrintTree3(*t);
			printf("\n");
			break;
		case 0:
			printf("退出打印操作\n");
			break;	
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
//查找菜单
void menu2()
{
	printf("******************************************************************\n");
	printf("********************     请选择查找的方式     ********************\n");
	printf("********************       1.姓名查找         ********************\n");
	printf("********************       2.生日查找         ********************\n");
	printf("********************       0.退出             ********************\n");
	printf("******************************************************************\n");
}
//通过名字查找
tree* searchname(tree* t,char* a)
{
	tree* L;
	tree* R;
	if (!t)
		return NULL;
	if (strcmp(t->data.name, a) == 0)
		return t;
	else
	{
		L = searchname(t->left, a);
		R = searchname(t->right, a);
		if (L)
			return L;
		else if (R)
			return R;
		else
			return NULL;
	}
}
//生日查找
tree* searchbir(tree* t, char* a)
{
	tree* L;
	tree* R;
	if (!t)
		return NULL;
	if (strcmp(t->data.birth, a) == 0)
		return t;
	else
	{
		L = searchbir(t->left, a);
		R = searchbir(t->right, a);
		if (L)
			return L;
		else if (R)
			return R;
		else
			return NULL;
	}
}
//找父母节点
tree* findparent(tree* t, tree* bt)
{
	tree* L; tree* R;
	if (t == bt || !t)//为空，或者根节点就是该节点
		return NULL;
	if (t->left == bt || t->right == bt)
		return t;
	else
	{
		L = findparent(t->left, bt);
		R = findparent(t->right, bt);
		if (L)
			return L;
		else if (R)
			return R;
		else
			return NULL;
	}
}
//查找
void searchsystem(tree** t)
{
	int input = 0;
	do
	{
		menu2();
		printf("请选择查找方式:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			char n[20];
			printf("请输入你想查找的人的姓名：");
			scanf("%s", n);
			tree* bt;
			bt = searchname(*t, n);
			if (bt)
			{
				if (strcmp((*t)->data.name, n) == 0)
					printf("此人为家谱中年纪最大的\n");
				else
				{
					printf("此人存在，其祖先信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", (*t)->data.name, (*t)->data.c, (*t)->data.birth,
						                                           (*t)->data.wed, (*t)->data.addr, (*t)->data.health);
				}
				printf("此人信息如下:>\n");
				printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
				printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", bt->data.name, bt->data.c, bt->data.birth,
					                                            bt->data.wed, bt->data.addr, bt->data.health);
				if (bt->data.wife.tag==1)
				{
					printf("此人存在配偶，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n\n", bt->data.wife.name, bt->data.wife.c, bt->data.wife.birth,
						bt->data.wife.wed, bt->data.wife.addr, bt->data.wife.health);
				}
				tree* temp;
				temp = findparent(*t, bt);
				if (temp)
				{
					printf("此人在家谱中有父/母亲，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", temp->data.name, temp->data.c, temp->data.birth,
						                                            temp->data.wed, temp->data.addr, temp->data.health);
					if (temp->data.wife.tag == 1)
					{
						printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", temp->data.wife.name, temp->data.wife.c, temp->data.wife.birth,
							temp->data.wife.wed, temp->data.wife.addr, temp->data.wife.health);
					}
				}
				else
					printf("此人在家谱中无父/母亲\n");
				tree* L = bt->left;
				tree* R = bt->right;
				if (L)
				{
					printf("此人在家谱中有左孩子，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", L->data.name, L->data.c, L->data.birth,
					                          	                    L->data.wed, L->data.addr, L->data.health);
				}
				else
					printf("此人在家谱中无左孩子\n");
				if (R)
				{
					printf("此人在家谱中有右孩子，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", R->data.name, R->data.c, R->data.birth,
					                                            	R->data.wed, R->data.addr, R->data.health);
				}
				else
					printf("此人在家谱中无右孩子\n");
			}
			else
			{
				printf("此人不存在\n");
			}
			break;
		case 2:
			char b[20];
			printf("请输入你想查找的人的生日：");
			scanf("%s", b);
			if (strlen(b) != 8)
			{
				printf("输入的是错误数据，请重新选择查找方式\n");
				break;
			}
			tree* bbt;
			bbt = searchbir(*t, b);
			if (bbt)
			{
				if (strcmp((*t)->data.name, n) == 0)
					printf("此人为家谱中年纪最大的\n");
				else
				{
					printf("此人存在，其祖先信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", (*t)->data.name, (*t)->data.c, (*t)->data.birth,
						(*t)->data.wed, (*t)->data.addr, (*t)->data.health);
				}
				printf("此人信息如下:>\n");
				printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
				printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", bbt->data.name, bbt->data.c, bbt->data.birth,
					                                            bbt->data.wed, bbt->data.addr, bbt->data.health);
				if (bbt->data.wife.tag == 1)
				{
					printf("此人存在配偶，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n\n", bbt->data.wife.name, bbt->data.wife.c, bbt->data.wife.birth,
						bbt->data.wife.wed, bbt->data.wife.addr, bbt->data.wife.health);
				}

				tree* temp;
				temp = findparent(*t, bbt);
				if (temp)
				{
					printf("此人在家谱中有父/母亲，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", temp->data.name, temp->data.c, temp->data.birth,
						                                            temp->data.wed, temp->data.addr, temp->data.health);
					if (temp->data.wife.tag == 1)
					{
						printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", temp->data.wife.name, temp->data.wife.c, temp->data.wife.birth,
							temp->data.wife.wed, temp->data.wife.addr, temp->data.wife.health);
					}
				}
				else
					printf("此人在家谱中无父/母亲\n");
				tree* L = bbt->left;
				tree* R = bbt->right;
				if (L)
				{
					printf("此人在家谱中有左孩子，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", L->data.name, L->data.c, L->data.birth,
						                                            L->data.wed, L->data.addr, L->data.health);
				}
				else
					printf("此人在家谱中无左孩子\n");
				if (R)
				{
					printf("此人在家谱中有右孩子，其信息如下:>\n");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "婚否", "地址", "健在否");
					printf("%-12s\t%-5s\t%-15s\t%-5s\t%-20s\t%-5s\n", R->data.name, R->data.c, R->data.birth,
						                                            R->data.wed, R->data.addr, R->data.health);
				}
				else
					printf("此人在家谱中无右孩子\n");
			}
			else
			{
				printf("此人不存在\n");
			}
			break;
		case 0:
			printf("退出查找操作\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
//判断生日重复
int flag;
int judgement(tree* t, char* a)
{
	if (t)
	{
		if (strcmp(t->data.birth, a) == 0 || strcmp(t->data.wife.birth, a) == 0)
		{
			return flag++;
		}
		judgement(t->left, a);
		judgement(t->right, a);
	}
	return 0;
}
//修改
void changesystem(tree** t)
{
	char n[20];
	tree* p;
	printf("请输入你想修改的人的姓名：");
	scanf("%s", n);
	p = searchname(*t, n);
	if (p == NULL)
	{
		printf("此人不存在，请重新输入\n");
		return;
	}
	printf("请输入修改过后的姓名：");
	scanf("%s", p->data.name); 
	printf("请输入修改过后的出生日期：");
	scanf("%s", p->data.birth); 
	if (strlen(p->data.birth) != 8)
	{
		printf("输入的是错误数据，请重新输入:>");
		scanf("%s", p->data.birth);
	}
	judgement(*t, p->data.birth);
	if (flag)
	{
		printf("输入的生日在家谱中已存在,请检查仔细后输入:>");
		scanf("%s", p->data.birth);
	}
	int p1 = 0;
	printf("请问修改过后的那个人结婚了吗？结婚请输入（1）,没结婚请输入（0）：");
	scanf("%d", &p1);
	if (p1 == 1)
		strcpy(p->data.wed, "已婚");
	if (p1 == 0)
		strcpy(p->data.wed, "未婚");
	printf("请输入修改过后的住址：");
	scanf("%s", p->data.addr); 
	int p2 = 0;
	printf("请问修改过后的那个人健在吗？健在请输入（1），死亡请输入（0）：");
	scanf("%d", &p2);
	if (p2 == 1)
		strcpy(p->data.health, "是");
	if (p2 == 0)
		strcpy(p->data.health, "否");
	printf("修改完毕\n");
}
//添加菜单
void menu3()
{
	printf("******************************************************************\n");
	printf("********************     请选择添加的方式     ********************\n");
	printf("********************        1.左孩子          ********************\n");
	printf("********************        2.右孩子          ********************\n");
	printf("********************        0.退出            ********************\n");
	printf("******************************************************************\n");
}
//增加新成员
void addsystem(tree** t)
{
	char n[20];
	int input = 0;
	tree* p;
	people newchild;
	do
	{
		menu3();
		printf("请选择添加方式："); scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要增加的成员的父/母的名字：");
			scanf("%s", n);
			p = searchname(*t, n);
			if (p == NULL)
			{
				printf("此人不存在，无法添加新成员\n");
				return;
			}
			if (strcmp(p->data.wed, "未婚") == 0)
			{
				strcpy(p->data.wed, "已婚");
			}
			if (p->data.wife.tag != 1)
			{
				pe wife;
				printf("请输入此成员的配偶姓名:>"); scanf("%s", wife.name);
				printf("请输入此成员的配偶性别:>"); scanf("%s", wife.c);
				printf("请输入此成员的配偶生日:>"); scanf("%s", wife.birth);
				if (strcpy(wife.wed, "未婚") == 0)
				{
					strcpy(wife.wed, "已婚");
				}
				printf("请输入此成员的配偶地址:>"); scanf("%s", wife.addr);
				printf("请输入此成员的配偶健康状态，健康输入（1），否则输入（0）:>");
				int k = 0;
				scanf("%d", &k);
				if (k == 1)
					strcpy(wife.health, "是");
				else
					strcpy(wife.health, "否");
				wife.tag = 1;
				p->data.wife = wife;
				printf("配偶信息添加完成\n");
			}
			if (p->left != NULL)
			{
				printf("此成员已有左孩子，无法添加\n");
				break;
			}
			else
			{
				printf("请输入该孩子的姓名：");
				scanf("%s", newchild.name);
				printf("请输入该孩子的性别：");
				scanf("%s", newchild.c);
				printf("请输入该孩子的生日：");
				scanf("%s", newchild.birth);
				if (strlen(newchild.birth) != 8)
				{
					printf("输入的是错误数据，请重新输入:>");
					scanf("%s", newchild.birth);
				}
				judgement(*t, newchild.birth);
				if (flag)
				{
					printf("输入的生日在家谱中已存在,请检查仔细后输入:>");
					scanf("%s", newchild.birth);
				}
				printf("请输入该孩子的结婚状态，已婚输入（1），未婚输入（0）：");
				int p1 = 0;
				scanf("%d", &p1);
				if (p1 == 1)
					strcpy(newchild.wed, "已婚");
				if (p1 == 0)
					strcpy(newchild.wed, "未婚");
				printf("请输入该孩子的地址：");
				scanf("%s", newchild.addr);
				printf("请输入该孩子的健康状态，健在输入（1），否则输入（0）：");
				int p2 = 0;
				scanf("%d", &p2);
				if (p2 == 1)
					strcpy(newchild.health, "是");
				if (p2 == 0)
					strcpy(newchild.health, "否");
				new_left(&p, newchild);
			}
			printf("添加成功\n");
			break;
		case 2:
			printf("请输入要增加的成员的父/母的名字：");
			scanf("%s", n);
			p = searchname(*t, n);
			if (strcmp(p->data.wed, "未婚") == 0)
			{
				strcpy(p->data.wed, "已婚");
			}
			if (p->data.wife.tag != 1)
			{
				pe wife;
				printf("请输入此成员的配偶姓名:>"); scanf("%s", wife.name);
				printf("请输入此成员的配偶性别:>"); scanf("%s", wife.c);
				printf("请输入此成员的配偶生日:>"); scanf("%s", wife.birth);
				if (strcpy(wife.wed, "未婚") == 0)
				{
					strcpy(wife.wed, "已婚");
				}
				printf("请输入此成员的配偶地址:>"); scanf("%s", wife.addr);
				printf("请输入此成员的配偶健康状态，健康输入（1），否则输入（0）:>");
				int k = 0;
				scanf("%d", &k);
				if (k == 1)
					strcpy(wife.health, "是");
				else
					strcpy(wife.health, "否");
				wife.tag = 1;
				p->data.wife = wife;
				printf("配偶信息添加完成\n");
			}
			if (p == NULL)
			{
				printf("此人不存在，无法添加新成员\n");
				return;
			}
			if (p->right != NULL)
			{
				printf("此成员已有右孩子，无法添加\n");
				break;
			}
			else
			{
				printf("请输入该孩子的姓名：");
				scanf("%s", newchild.name);
				printf("请输入该孩子的性别：");
				scanf("%s", newchild.c);
				printf("请输入该孩子的生日：");
				scanf("%s", newchild.birth);
				if (strlen(newchild.birth) != 8)
				{
					printf("输入的是错误数据，请重新输入:>");
					scanf("%s", newchild.birth);
				}
				judgement(*t, newchild.birth);
				if (flag)
				{
					printf("输入的生日在家谱中已存在,请检查仔细后输入:>");
					scanf("%s", newchild.birth);
				}
				printf("请输入该孩子的结婚状态，已婚输入（1），未婚输入（0）：");
				int p1 = 0;
				scanf("%d", &p1);
				if (p1 == 1)
					strcpy(newchild.wed, "已婚");
				if (p1 == 0)
					strcpy(newchild.wed, "未婚");
				printf("请输入该孩子的地址：");
				scanf("%s", newchild.addr);
				printf("请输入该孩子的健康状态，健在输入（1），否则输入（0）：");
				int p2 = 0;
				scanf("%d", &p2);
				if (p2 == 1)
					strcpy(newchild.health, "是");
				if (p2 == 0)
					strcpy(newchild.health, "否");
				new_right(&p, newchild);
			}
			printf("添加成功\n");
			break;
		case 0:
			printf("退出添加操作\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
//删除
void delsystem(tree** t)
{
	printf("该操作会使得该成员以及其所有后代均被删除\n");
	char n[20];
	tree* bt;
	tree* p;
	printf("请输入要删除的成员姓名：");
	scanf("%s", n);
	bt = searchname(*t, n);
	p = findparent(*t, bt);//p为bt的父母
	if (p != NULL)
	{
		if (p->left == bt)
		{
			p->left = NULL;
			free(bt);
		}
		if (p->right == bt)
		{
			p->right = NULL;
			free(bt);
		}
	}
	else//只有一个根节点
	{
		*t = NULL;
	}
	printf("删除成功\n");
}
//统计菜单
void menu4()
{
	printf("******************************************************************\n");
	printf("********************     请选择统计的内容     ********************\n");
	printf("********************       1.成员总数         ********************\n");
	printf("********************       2.无后代的人数     ********************\n");
	printf("********************       0.退出             ********************\n");
	printf("******************************************************************\n");
}
int cnt = 0;
void summary(tree* t)
{
	if (t)
		cnt++;
	else
		return;
	summary(t->left);
	summary(t->right);
}
int count2 = 0;
void Leaf(tree* T)
{
	if (T)
	{
		Leaf(T->left);
		if (T->left == NULL && T->right == NULL)
		{
			printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", T->data.name, T->data.c, T->data.birth,
				                        T->parent->data.name, T->data.wed, T->data.addr, T->data.health);
			count2++;
		}
		Leaf(T->right);
	}
}
//统计
void totalsystem(tree** t)
{
	int input = 0;
	do
	{
		menu4();
		printf("请选择需要统计的内容："); scanf("%d", &input);
		switch (input)
		{
		case 1:
			summary(*t);
			printf("成员总数一共为：%d", cnt); printf("\n");
			break;
		case 2:
			printf("无后代的成员信息如下:>\n");
			printf("%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\n", "姓名", "性别", "生日", "父/母亲","婚否", "地址", "健在否");
			Leaf(*t);
			printf("无后代的成员总数一共为：%d", count2); printf("\n");
			break;
		case 0:
			printf("退出统计操作\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
FILE* pf;
//存储文件
void cunchu(tree* t)
{
	if (t)
	{
		if (t->data.wife.tag == 1)
		{
			fprintf(pf, "%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\t%-10s\n", t->data.name, t->data.c, t->data.birth,
				t->parent->data.name, t->data.wed, t->data.addr, t->data.health,t->data.wife.name);
		}	
		else
		{
			fprintf(pf, "%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\t%-10s\n", t->data.name, t->data.c, t->data.birth,
				t->parent->data.name, t->data.wed, t->data.addr, t->data.health, "无");
		}
		cunchu(t->left);
		cunchu(t->right);
	}
}
//文件操作
void File(tree** t)
{
	printf("接下来要将此时系统内的信息存储到文件内:\n");
	if (*t == NULL)
	{
		printf("系统中无任何信息，无法进行文件存储\n");
		return;
	}
	char fileName[20];
	printf("请输入文件名:>");
	scanf("%s", fileName);
	pf = fopen(fileName, "wt");
	if (pf == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	fprintf(pf, "%-12s\t%-5s\t%-15s\t%-10s\t%-5s\t%-20s\t%-5s\t%-10s\n", "姓名", "性别", "生日","父/母亲","婚否", "地址", "健在否","配偶");
	cunchu(*t);
	//关闭文件 
	fclose(pf); pf = NULL;
	printf("已保存\n\n");
}

