#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>         
#include <string.h>
#define MAX 15//哈希表的长度
#define NAMEMAX 8//名单长度
#define ERROR 0
#define OK 1
#define R 2//小于哈希表长度的R
typedef struct Nametable
{
    const char* name;      //姓名
    int ascii;             //对应的ascii码
    int length;            //查找长度
    Nametable* next;
}Name;
typedef struct Hastable
{
    int num;   //哈希表表位链接点个数
    Nametable* head;
    Nametable* end;
}Hash;
//初始化名单表
void Init(Name** NameList)
{
    *NameList = (Name*)malloc(NAMEMAX * sizeof(Name));
    int i, j;
    (*NameList)[0].name = "xmz";
    (*NameList)[1].name = "zmx";
    (*NameList)[2].name = "lhy";
    (*NameList)[3].name = "zqx";
    (*NameList)[4].name = "hwt";
    (*NameList)[5].name = "hzy";
    (*NameList)[6].name = "xqz";
    (*NameList)[7].name = "qzx";
  /*  (*NameList)[0].name = "yrh";
    (*NameList)[1].name = "dhf";
    (*NameList)[2].name = "zxx";
    (*NameList)[3].name = "zzq";
    (*NameList)[4].name = "zys";
    (*NameList)[5].name = "xjh";
    (*NameList)[6].name = "wlz";
    (*NameList)[7].name = "lzq";*/
    for (i = 0; i < NAMEMAX; i++)
    {
        (*NameList)[i].length = 0;
        (*NameList)[i].ascii = 0;
        (*NameList)[i].next = NULL;
        for (j = 0; *((*NameList)[i].name + j) != '\0'; j++)
            (*NameList)[i].ascii += toascii(*((*NameList)[i].name + j));   
    }
}
void Creat(Hash** &table, Name* NameList)
{
    table = (Hash**)malloc((MAX + 1) * sizeof(Hash*));//0号单元未用
    int i, HashSite;
    for (i = 1; i <= MAX; i++) 
    {
        table[i] = (Hash*)malloc(sizeof(Hash));
        table[i]->num = 0;
        table[i]->head = NULL;
        table[i]->end = NULL;
    }
    for (i = 0; i < NAMEMAX; i++)
    {
        if (NameList[i].length == 0)
        {
            HashSite = (NameList[i].ascii) % R;                 
            if (table[HashSite]->num == 0)                      //未发生冲突则将相关信息填充至哈希表
            {
                table[HashSite]->head = &NameList[i];
                table[HashSite]->end = &NameList[i];
                table[HashSite]->end->length++;
            }
            else                                                //发生冲突链接于最后一个记录之后
            {
                table[HashSite]->end->next = &NameList[i];
                NameList[i].length = table[HashSite]->end->length + 1;
                table[HashSite]->end = &NameList[i];
            }
            table[HashSite]->num++;
        }
    }
}
//查找函数
void Search(Hash** table)
{
    Name* cur = NULL;
    int i, j = 0;
    int hashnum = 0;
    int v = 0;
    char name[10] = { "0" };//存储查找的名字
    getchar();
    printf("请输入待查找姓名：");
    gets_s(name);

    for (j = 0; name[j] != '\0'; j++)
        v += toascii(name[j]);
    hashnum = (v) % R;
    printf("key是：%d\n", hashnum);

    cur = table[hashnum]->head;
    while (cur != NULL)
    {
        if (strcmp(cur->name, name) == 0)
        {
            printf("已从哈希表中查找到记录\n");
            printf("哈希表表位:%-4d姓名:%-4sascii:%-4d查找长度：%-4d\n", hashnum, cur->name, cur->ascii, cur->length);
            return;
        }
        cur = cur->next;
    }
    if (cur == NULL)
        printf("无此记录！！!\n");
}
//打印名单
void Print_NameList(Name* NameList)
{
    int i;
    for (i = 0; i < NAMEMAX; i++)
    {
        if (NameList[i].length != -1)
            printf("序号:%-4d名称:%-4sascii:%-4d\n", i + 1, NameList[i].name, NameList[i].ascii);
        else
            break;
    }
}
//打印哈希表
void Print_Hash(Hash** table)
{
    Name* cur = NULL;
    int j = 1;
    float ASL = 0.0;//平均查找长度
    while (j <= MAX)
    {
        if (table[j]->head == NULL)
            printf("哈希表表位:%-4d__NULL\n", j);
        else
        {
            for (cur = table[j]->head; cur != NULL; cur = cur->next)
            {
                printf("哈希表表位:%-4d节点个数:%-4d姓名:%-4sascii:%-4d查找长度：%-4d\n", 
                                   j, table[j]->num, cur->name, cur->ascii, cur->length);
                ASL += cur->length;
            }
        }
        ++j;
    }
    ASL /= NAMEMAX;
    printf("哈希表平均查找长度为：%4f\n", ASL);
}
void menu()
{
    printf("**********    1.打印名单    **********\n");
    printf("**********    2.打印哈希表  **********\n");  
    printf("**********    3.查找        **********\n");
    printf("**********    0.退出        **********\n");
}
int main()
{
    Name* NameList = NULL;//名单
    Hash** table = NULL;//哈希表向量
    int input = 1;
    Init(&NameList);
    Creat(table, NameList);
    while (input)
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Print_NameList(NameList); 
            break;
        case 2:
            Print_Hash(table); 
            break;
        case 3:
            Search(table); 
            break;
        case 0:
            printf("正在退出...\n"); 
            break;
        default: 
            printf("EROOR INPUT!\a\n"); 
            break;
        }
       
    }
    return 0;
}

