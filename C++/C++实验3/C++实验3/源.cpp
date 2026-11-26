//#include <iostream>
//using namespace std;
//class score
//{
//public:
//	float computer;
//	float math;
//	float english;
//	score() {}
//	score(float x1, float y1, float z1)
//	{
//		computer = x1; english = y1; math = z1;
//	}
//	void print()
//	{
//		cout << "学生成绩如下:" << endl;
//		cout << "计算机:" << computer << endl;
//		cout << "英语:" << english << endl;
//		cout << "数学:" << math << endl;
//	}
//	void modify(float x2, float y2, float z2)
//	{
//		computer = x2; english = y2; math = z2;
//	}
//};
//class student
//{
//public:
//	string name;
//	int num;
//	score obj;
//	student() { }
//	student(score o)
//	{
//		obj = o;
//	}
//	void showifm()
//	{
//		cout << "学生姓名:" << name << endl;
//		cout << "学生学号:" << num << endl;
//	}
//	
//};
//int main()
//{
//	student p1;
//	string n1;
//	cout << "输入学生姓名:"; cin >> n1;
//	p1.name = n1;
//	int num;
//	cout << "输入学生学号:"; cin >> num;
//	p1.num = num;
//	cout << "学生信息如下:" << endl;
//	p1.showifm();
//	cout << "输入学生成绩:" << endl;
//	float a, b, c;
//	cout << "计算机:"; cin >> a; cout << endl;
//	cout << "英语:"; cin >> b; cout << endl;
//	cout << "数学:"; cin >> c; cout << endl;
//	score p2(a, b, c);
//	student p3(p2);
//	p1.obj = p2;
//	p1.obj.print();
//	cout << "输入修改后的成绩:" << endl;
//	cout << "计算机:"; cin >> a; cout << endl;
//	cout << "英语:"; cin >> b; cout << endl;
//	cout << "数学:"; cin >> c; cout << endl;
//	p1.obj.modify(a, b, c);
//	p1.obj.print();
//
//	return 0;
//}

#include <iostream>
using namespace std;
class score
{
public:
	int cm; int en; int ma;
    score() {};
	score(int a, int b, int c)
	{
		cm = a; en = b; ma = c;
	}
};
class student
{
public:
	string name; int num; score obj;
	student() {};
	student(string m_name, int m_num, score tar)
	{
		name = m_name; num = m_num; obj = tar;
	}
	void print()
	{
		cout << name << " " << num << " " << obj.cm << " " << obj.en << " " << obj.ma;
	}
};
int main()
{
	score p(90, 90, 90);
	student p1("张三", 2004, p);
	p1.print();
}