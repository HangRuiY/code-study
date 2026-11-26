#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <set>
#include <list>
//评委打分
//class Person
//{
//public:
//	Person(string name, double score)
//	{
//		this->m_name = name;
//		this->m_score = score;
//	}
//	string m_name;
//	double m_score;
//};
//void creatPerson(vector<Person>& v)
//{
//	string nameseed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "选手";
//		name += nameseed[i]; //选手A 选手B 选手C 选手D 选手E
//
//		double score = 0;
//		Person p(name, score);
//		v.push_back(p);
//	}
//}
//void setscore(vector<Person>& v)
//{
//	
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		//将评委的分数放入deque容器
//		deque<double>d;
//		for (int i = 0; i < 10; i++) //10个评委打分
//		{
//			double score = rand()%41+60;
//			d.push_back(score);
//		}
//		cout << "选手：" << it->m_name << " " << "打分：" << endl;
//		for (deque<double>::iterator dit = d.begin(); dit != d.end(); dit++)
//		{
//			cout << (*dit) << " ";
//		}
//		cout << endl;
//		//排序
//		sort(d.begin(),d.end());
//		d.pop_back();
//		d.pop_front();
//		//取平均分
//		double sum = 0;
//		for (deque<double>::iterator dit = d.begin(); dit != d.end(); dit++)
//		{
//			sum += (*dit);
//		}
//		double ave = sum / d.size();
//		(*it).m_score = ave;
//	}
//
//}
//void showscore(vector<Person>& v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名：" << it->m_name << " " << "平均分：" << it->m_score << endl;
//	}
//}
//int main()
//{
//	//创建5个选手
//	vector<Person>v;
//	creatPerson(v);
//	//测验
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名：" << (*it).m_name << " " << "分数：" << (*it).m_score << endl;
//	}
//	//打分
//	setscore(v);
//	//显示平均分数
//	showscore(v);
//	
//	return 0;
//}

//员工分组
//#define CeHua 0
//#define MeiShu 1
//#define YanFa 2
//class Worker
//{
//public:
//	string m_name;
//	int m_salary;
//};
//void creatworker(vector<Worker>& v)
//{
//	string name = "ABCDEFGHIJ";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.m_name = "员工";
//		worker.m_name += name[i];
//
//		worker.m_salary = rand() % 10000 + 10000;
//		v.push_back(worker);
//	}
//}
//void setteam(vector<Worker>& v, multimap<int, Worker>& m)
//{
//	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		//产生随机部门编号
//		int dep = rand() % 3;//0 1 2
//		//将员工插入到分组中
//		m.insert(pair<int, Worker>(dep, *it));
//		//m.insert(make_pair(dep, *it));
//	}
//}
//void showworker(multimap<int, Worker>& m)
//{
//	cout << "策划部门：" << endl;
//	multimap<int, Worker>::iterator pos = m.find(CeHua);
//	int cnt = m.count(CeHua);//统计具体人数
//	int index = 0;
//	for (; pos != m.end() && index < cnt; pos++, index ++ )
//	{
//		cout << "姓名：" << pos->second.m_name << "  " << "薪水：" << pos->second.m_salary << endl;
//	}
//
//	cout << "美术部门：" << endl;
//	pos = m.find(MeiShu);
//	cnt = m.count(MeiShu);
//	index = 0;
//	for (; pos != m.end() && index < cnt; pos++, index++)
//	{
//		cout << "姓名：" << pos->second.m_name << "  " << "薪水：" << pos->second.m_salary << endl;
//	}
//
//	cout << "研发部门：" << endl;
//  	pos = m.find(YanFa);
//	cnt = m.count(YanFa);
//	index = 0;
//	for (; pos != m.end() && index < cnt; pos++, index++)
//	{
//		cout << "姓名：" << pos->second.m_name << "  " << "薪水：" << pos->second.m_salary << endl;
//	}
//}
//int main()
//{
//	//创建员工
//	vector<Worker>v;
//	creatworker(v);
//	//测试
//	/*for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//		cout << "姓名："<< it->m_name << "  " << "薪水：" << it->m_salary<<endl;*/
//	//分组
//	multimap<int, Worker>m;
//	setteam(v,m);
//	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
//		cout << "部门：" << it->first << "  " << "员工姓名：" << it->second.m_name << "  " << "薪水：" << it->second.m_salary << endl;
//	//显示信息
//	showworker(m);
//}

//list 自定义排序
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
//指定排序规则
bool compare(Person& p1, Person& p2)
{
	//年龄降序
	if (p1.m_age == p2.m_age)
		return p1.m_height > p2.m_height;//身高降序
	else
		return p1.m_age > p2.m_age;
}
void t1()
{
	list<Person>l;
	Person p1("刘备", 35, 195);
	Person p2("关羽", 30, 185);
	Person p3("张飞", 28, 182);
	Person p4("曹操", 35, 205);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << it->m_name << " " << "年龄：" << it->m_age << " " << "身高：" << it->m_height << endl;
	}
	cout << endl;
	//排序后
	l.sort(compare);
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << it->m_name << " " << "年龄：" << it->m_age << " " << "身高：" << it->m_height << endl;
	}
}
int main()
{
	t1();
}
//string a;
//int b[18];
//int temp; int flag; int sum; int mod;
//char x[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
//int q[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//int m[13] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//int d[32] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
//int arr[100] = { 11,12,13,14,15,21,22,23,31,32,33,34,35,36,37,41,42,43,44,45,46,50,51,52,53,54,61,62,63,64,65,81,82,83,91 };
//void Judge1(string a)
//{
//	temp = 0;
//	//前17位是不是数字
//	for (int i = 0; i < a.size()-1; i++)
//	{
//		if (a[i] < 48 || a[i] >57) //不是数字
//		{
//			printf("(%c)", a[i]);
//			temp++;
//		}
//		else
//			cout << a[i];
//	}
//	//第18位
//	if (a[a.size()-1] == 'x' || (a[a.size() - 1] >= 48 && a[a.size() - 1] <= 57) || a[a.size() - 1] == 'X')
//	{
//		printf("%c\n", a[a.size() - 1]);
//	}
//	else
//	{
//		printf("(%c)\n", a[a.size() - 1]);
//		temp++;
//	}
//	if (temp != 0)
//		cout << "No FeiFaZiFu:" << temp << endl;
//	else
//		return;
//}
//void Judge2(string a,int* arr)
//{
//	for (int i = 0; i < a.size(); i++)
//		b[i] = a[i] - 48; //全部转换成十进制
//	temp = b[0] * 10 + b[1];
//	for (int i = 0; i < 100; i++)
//	{
//		if (temp != arr[i])
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//		cout << "No ShengFenDaiMa:" << temp << endl;
//	else
//		return;
//}
//void Judge3(string a)
//{
//	for (int i = 0; i < a.size(); i++)
//		b[i] = a[i] - 48; //全部转换成十进制
//	int nian = (b[6]) * 1000 + (b[7]) * 100 + (b[8] * 10 + b[9]);
//	int yue = b[10] * 10 + b[11];
//	int ri = b[12] * 10 + b[13];
//	for (int i = 0; i < 13; i++)
//	{
//		if (yue == m[i])
//		{
//			temp = 1;
//			break;
//		}
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		if (ri == d[i])
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (nian < 0 || temp != 1 || flag != 1)//有问题
//		printf("No ChuShengRiQi:%c%c%c%c%c%c%c%c\n", a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]);
//	else
//		return;
//}
//void Judge4(string a)
//{
//	for (int i = 0; i < a.size(); i++)
//		b[i] = a[i] - 48; //全部转换成十进制
//	for (int i = 0; i < a.size() -1; i++)
//	{
//		sum += b[i] * q[i];
//	}
//	mod = sum % 11;
//	temp = b[17];//最后一位存入temp
//	if (x[mod] != a[17])
//		printf("No JiaoYanHaoMa:%c(%c is right)\n", a[17], x[mod]);
//	else
//		return;
//}
//int main()
//{
//	cin >> a;//输入
//	//判断够不够18位
//	if (a.size() != 18)
//	{
//		cout << "No WeiShuBuzu:" << a.size() << endl;
//		return 0;
//	}
//	//其他情况
//	//1.非法字符
//	//判断前17位是不是数字或者18位是不是X
//	Judge1(a); 
//	//2.省份代码
//	Judge2(a, arr); 
//	//3.出生日期
//	Judge3(a); 
//	//4.效验码错误
//	Judge4(a);
//	return 0;
//}