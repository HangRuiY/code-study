#include <iostream>
#include <cstring>
using namespace std;
class student
{
public:
	string name;
	int num;
	student(string NAME, int NUM)
	{
		name=NAME;
		num = NUM;
	}
};
int main()
{
	student a[5] = { student("张一",1),
					student("张二",2),student("张三",3),
					student("张四",4),student("张五",5)};
	printf("信息如下:>\n");
	cout << a[0].name << "  " << a[0].num << endl;
	cout << a[1].name << "  " << a[1].num << endl;
	cout << a[2].name << "  " << a[2].num << endl;
	cout << a[3].name << "  " << a[3].num << endl;
	cout << (a+4)->name << "  " << (a+4)->num << endl;
	return 0;
}

//class samp
//{
//	int i;
//public:
//	samp(int n) { i = n; }
//	void set_i(int n)
//	{
//		i = n;
//	}
//	int get_i()
//	{
//		return i;
//	}
//};
//void sqr_it(samp& o)
//{
//	o.set_i(o.get_i() * o.get_i());
//	cout << "Copy of a has i value of " << o.get_i() << endl;
//}
//int main()
//{
//	samp a(10);
//	sqr_it(a);
//	cout << "Copy of a has i value of " << a.get_i();
//	return 0;
//}

//class Circle
//{
//public:
//	Circle(float r)
//	{
//		radius = r;
//		count++;
//	}
//	~Circle() { --count; }
//	static int num() { return count; }
//private:
//	float radius;
//	static int count;
//};
//int Circle::count;
//int main()
//{
//	Circle p1(0.1);
//	Circle p2(0.2);
//	Circle p3(0.3);
//	cout << p1.num() << endl;
//	cout << p2.num() << endl;
//	cout << p3.num() << endl;
//	return 0;
//}

//class Point
//{
//public:
//	Point(double xi, double yi)
//	{
//		X = xi;
//		Y = yi;
//	}
//	double GetX() { return X; }
//	double GetY() { return Y; }
//	friend double Distandce(Point& a, Point& b);
//private:
//	double X, Y;
//};
//double Distance(Point& a, Point& b)
//{
//	double dx = a.X - b.X;
//	double dy = a.Y - b.Y;
//	return sqrt(dx * dx + dy * dy);
//}
//int main()
//{
//	Point p1(3.0, 5.0), p2(4.0, 5.0);
//	double d = Distance(p1, p2);
//	cout << "The distance is " << d << endl;
//	return 0;
//}

//class Point
//{
//public:
//	Point(double xi, double yi) { X = xi; Y = yi; }
//	double GetX() { return X; }
//	double GetY() { return Y; }
//	double Distance(Point& b);
//private:
//	double X, Y;
//};
//double Point::Distance(Point& b)
//{
//	double dx = X - b.X;
//	double dy = Y - b.Y;
//	return sqrt(dx * dx + dy * dy);
//}
//int main()
//{
//	Point p1(3.0, 5.0), p2(4.0, 6.0);
//	double d = p1.Distance(p2);
//	cout << "The distance is " << d << endl;
//	return 0;
//}