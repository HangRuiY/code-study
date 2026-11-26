#include "pdm.h"
//管理系统 存入人的姓名 学号 体温 身份证号 电话号 地址
//实现信息的 增加 删除 查找 修改 排序 打印 退出
int main()
{
	system("color 2");
	//创建管理系统
	syslist* pdm;
	//初始化系统（链表）
	Initsystem(&pdm);
	//进入系统
	systemmain(&pdm);
	return 0;
}