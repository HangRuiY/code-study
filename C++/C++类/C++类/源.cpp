#include <iostream>
#include <string>
using namespace std;
//访问权限
//public 类内类外都可以访问 protected 类内可以，类外不行。儿子可以访问父亲保护的内容 private 类内可以，类外不同。儿子不能访问父亲隐私内容
//三种权限修饰的都是属性+行为
//class Person
//{
//public:
//	string name;
//protected:
//	string car;
//private:
//	int pwd;
//public:
//	void func()//类内可以访问
//	{
//		name = "张三"; car = "奔驰"; pwd = 2004;
//	}
//};
//int main()
//{
//	Person p1;
//	p1.func();
//}

//成员变量设置为私有,方便控制读写
//class Person
//{
//public:
//	//设置姓名
//	void setname(string n)
//	{	name = n;	}
//	//获取姓名
//	string getname()
//	{	return name;	}
//	//获取年龄
//	int getage()
//	{	return age;	}
//	string getidol(string n)
//	{
//		idol = n;
//	}
//private:
//	string name;//可读可写
//	int age = 18;//只读
//	string idol;//只写
//};
//int main()
//{
//	Person p1;
//	p1.setname("张三"); 
//	cout << p1.getname() << endl;
//	cout << p1.getage() << endl;
//	p1.getidol("蔡徐坤");
//
//}

//对象的初始化和清理
//构造函数，进行初始化。析构函数，进行清理
//class Person
//{
//public:
//	//1.没有返回值，不用写void 2.函数名与类名相同 3.可以无参，可以重载（名字相同，参数类型不同，或者顺序不同，或者个数不同）
//	//创建对象时，会自动调用一次构造函数
//	Person()
//	{
//		cout << "Person构造函数的调用" << endl;
//	}
//	//1.没有返回值，不写void 2.函数名与类名相同，加一个~ 3.无参，不可以重载
//	//销毁对象时，会自动调用一次析构函数
//	~Person()
//	{
//		cout << "Person析构函数的调用" << endl;
//	}
//
//};
//void test1()
//{
//	Person p;
//}
//int main()
//{
//	test1();
//}

//构造函数的分类和使用
//class Person
//{
//public:
//	//普通构造
//	Person()//无参(默认构造)
//	{
//		cout << "Person的无参构造函数" << endl;
//	}
//	Person(int a)//有参
//	{
//		age = a;
//		cout << "Person的有参构造函数" << endl;
//	}
//	//拷贝构造
//	Person(const Person& p)
//	{
//		cout << "Person的拷贝构造函数" << endl;
//		age = p.age;//将传入的类中所有属性赋值给当前属性
//	}
//	~Person()
//	{
//		cout << "Person的析构函数" << endl;
//	}
//	int age;
//};
//void test1()
//{
//	//括号法
//	//Person p1;//默认无参构造函数调用 不加括号
//	//Person p2(10);//有参构造函数调用
//	//Person p3(p2);//拷贝构造函数调用
//	//cout << "p3的年龄：" << p3.age << endl;
//	//显示法
//	Person p1;//无参构造
//	Person p2 = Person(10);//有参构造
//	Person p3 = Person(p2);//拷贝构造
//}
//int main()
//{
//	test1();
//}
//一个类创建后，编译器自动给予无参构造和拷贝构造，以及析构函数
//如果自己提供了有参构造，则编译器会自动提供拷贝构造，但是不提供无参构造

//深拷贝和浅拷贝
//class person
//{
//public:
//	person()
//	{
//		cout << "person的无参构造" << endl;
//	}
//	person(int a,int height)
//	{
//		age = a;
//		this->height = new int(height);
//		cout << "person的有参构造" << endl;
//	}
//	person(const person& p)
//	{
//		age = p.age;
//		height = new int (*p.height);
//		cout << "person的拷贝构造" << endl;
//	}
//	~person()
//	{
//		if (height != NULL)
//			delete height;
//		cout << "person的析构函数" << endl;
//	}
//	int age;
//	int* height;
//};
//void test1()
//{
//	person p1(18,180);
//	cout << "p1的年龄:" << p1.age<<"  p1的身高:"<<*p1.height<<endl;
//	person p2(p1);
//	cout << "p2的年龄:" << p2.age << "  p2的身高:" << *p2.height << endl;
//
//}
//int main()
//{
//	test1();
//}

//初始化列表
//class person
//{
//public:
//	person() :m_a(10),m_b(20)
//	{
//	}
//	person(int a, int b) : m_A(a), m_B(b)	{}
//	int m_A;
//	int m_B;
//};
//int main()
//{
//	person p(10,20);
//}

//类对象作为类成员
//class phone
//{
//public:
//	string m_pname;
//	phone(string pname)
//	{
//		cout << "phone有参构造" << endl;
//		m_pname = pname;
//	}
//};
//class person
//{
//public:
//	string m_name;
//	phone m_phone;
//	//phone m_phone = pname //隐式转换法
//	person(string name, string pname):m_name(name),m_phone(pname)
//	{
//		cout << "person有参构造" << endl;
//	}
//};
//int main()
//{
//	person p1("张三", "华为");
//	cout << "姓名:" << p1.m_name << " " << "手机:" << p1.m_phone.m_pname << endl;
//}

//静态成员
//1.所有对象共享一份数据 2.类内声明，类外初始化
//通过对象和类名访问
//class person
//{
//public:
//	static int m_A;
//	//静态成员变量有访问权限
//private:
//	static int m_B;
//};
//int person::m_A = 0;//类外初始化
//void test1()
//{
//	person p;
//	p.m_A = 50;
//	cout << p.m_A << endl;
//	person p2;
//	p2.m_A = 200;
//	cout << p.m_A << endl;//输出200，说明共享一份数据
//}
//int person::m_B = 0;
//void test2()
//{
//	//通过对象
//	person p;
//	cout << p.m_A << endl;
//	//通过类名
//	cout << person::m_A << endl;
//	//cout << person::m_B << endl;//不可访问
//}
//int main()
//{
//	//test1();
//	test2();
//}

//静态成员函数
//1.所有对象共享同一函数 2.静态成员函数只可以访问静态成员变量
//class person
//{
//private:
//	static int m_A;
//public:
//	static void func(int a)
//	{
//		m_A = a;
//		//m_B = 200;//静态成员函数只能访问静态成员变量
//		cout << "静态成员函数调用" << endl;
//	}
//	//静态成员函数也有访问权限
//	int m_B;
//	static void func2(int b)
//	{
//		m_A = b; //静态成员函数只能访问静态成员变量
//	}
//};
//int person::m_A = 0;
//void test1()
//{
//	//通过对象访问
//	person p;
//	p.func(100);
//	//通过类名访问
//	person::func2(100);
//}
//int main()
//{
//	test1();
//}

//友元
//class build
//{
//	friend void goodgay(build& building);
//public:
//	build():setroom("客厅"),bedroom("卧室") {}
//public:
//	string setroom;
//private:
//	string bedroom;
//};
//void goodgay(build& building)
//{
//	cout << "正在访问：" << building.bedroom << endl;
//}
//int main()
//{
//	build building;
//	goodgay(building);
//}

//类作友元
class building
{	
	//friend class gay;
public:
	string setroom;
private:
	string bedroom;
public:
	building(string x, string y)
	{
		setroom = x; bedroom = y;
	}
};
class gay
{
public:
	gay(string mname,string x,string y):name(mname),build(x,y){}
	string name;
	building build;
	void visit()//访问build中的属性
	{
		cout << name << "正在访问：" << build.setroom << endl;
		//cout << name << "正在访问：" << build.bedroom << endl;
	}
};
//类外写成员函数
//building::building():setroom("客厅"),bedroom("卧室"){}
//gay::gay()
//{
//	build = new building;
//}
//void gay::visit()
//{
//	cout <<name <<"正在访问：" << build.setroom << endl;
//	cout <<name <<"正在访问：" << build.bedroom << endl;
//}
int main() 
{
	gay p("张三","客厅","卧室");
	p.visit();
}

//成员函数作友元
//class build
//{
//	friend class gay;
//public:
//	build()
//	{
//		setroom = "客厅";
//		bedroom = "卧室";
//	}
//	string setroom;
//private:
//	string bedroom;
//};
//class gay
//{
//public:
//	gay()
//	{
//		b = new build;
//	}
//	build* b;
//	void visit();
//	void visit2();
//};
//void gay::visit()
//{
//	cout << "visit正在访问：" << b->setroom << endl;
//}
//void gay::visit2()
//{
//	cout << "visit2正在访问：" << b->bedroom << endl;
//}
//int main()
//{
//	gay p;
//	p.visit();
//	p.visit2();
//}

//继承
//实际上就是在子类中调用父类的成员
//class 派生类（子类） : 继承方式 基类（父类）
//class BasePage
//{
//public:
//	void header()
//	{
//		cout << "111111111111" << endl;
//	}
//};
//class JAVA : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "java学科视频" << endl;
//	}
//};
//class Python :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "python学科视频" << endl;
//	}
//};
//int main()
//{
//	JAVA j;
//	j.header(); j.content();
//	Python p;
//	p.header(); p.content();
//}

//继承的继承方式
//class base
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//class son1 :protected base//除private以外都变成protected
//{
//public:
//	void func()
//	{
//		a = 10;//父类公共成员到子类变为保护成员
//		b = 10;//父类保护成员到子类变为保护成员
//		//c = 10;//子类访问不到私有成员
//	}
//	void content()
//	{
//		cout << a;
//	}
//};
//class son2 :private base//都变成私有成员，类内可以访问
//{
//	friend class son1;
//public:
//	void func()
//	{
//		a = 100;
//		b = 100;
//	}
//	void content()
//	{
//		cout << a << " " << b;
//	}
//};
//class son3 :public base//public不影响父类的属性
//{
//public:
//	void func()
//	{
//		a = 10;//父类的公共权限成员，在子类中依然是公共权限成员
//		b = 10;//父类的保护权限成员，在子类中依然是保护权限成员，子类内部可以访问
//		//c = 10;//父类的私有权限成员，在子类中不可访问
//	}
//	void content()
//	{
//		cout << a << " " << b;
//	}
//};
//int main()
//{
//	son3 s;
//	s.func();
//	s.content();
//}

