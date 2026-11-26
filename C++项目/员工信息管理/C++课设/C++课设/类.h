#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Information
{
private:
    int age;
    float weight;
public:
    Information() {}
    Information(int mage, float mweight) :age(mage), weight(mweight) {}
    int getage()
    {
        return age;
    }
    float getweight()
    {
        return weight;
    }
    void setage(int mage) { age = mage; }
    void setweight(float mweight) { weight = mweight; }
    void print1()
    {
        cout << "年龄：" << age <<"  "<< "体重：" << weight << endl;
    }
};

class Employee
{
private:
    static string CompanyName;
    int id;
    string name;
    Information emp;
protected:
    float money;
public:
    Employee() {}
    Employee(int id, string name, int mage, float mweight)
    {
        this->id = id; this->name = name;
        this->emp = Information(mage, mweight);
    }
    static void setCompanyName(string companyName)
    {
        CompanyName = companyName;
    }
    void setEmployee(int id, string name, int mage, float mweight)
    {
        this->id = id;
        this->name = name;
        this->emp.setage(mage);
        this->emp.setweight(mweight);
    }
    void print2()
    {
        emp.print1();
        cout << CompanyName << "," << "工号为" << id << "号的员工" << name << "本月工资为" << money << "。" << endl;
    }
    void writefile()
    {
        ofstream ofs;
        ofs.open("employees.txt", ios::app);
        ofs << CompanyName << "，" << "工号为" << id << "号的员工" << name << "本月工资为" << money << "。" << endl;
        ofs.close();
    }
    virtual void pay() = 0;
    virtual void showtype() = 0;
};
string Employee::CompanyName = "腾讯公司";

class Technician :virtual public Employee
{
private:
    int hour;
    float hourlyRate;
public:
    Technician() {}
    Technician(int id, string name, int mage, float mweight, int mhour, float mhourlyRate)
          : Employee(id, name, mage, mweight), hour(mhour), hourlyRate(mhourlyRate) {}
    void setHour(int _hour) { hour = _hour; }
    int getHour() { return hour; }
    void setHourlyRate(float _hourlyRate) { hourlyRate = _hourlyRate; }
    float getHourlyRate() { return hourlyRate; }
    virtual void pay()
    {
        float salary = hour * hourlyRate;
        money = salary;
    }
    virtual void showtype()
    {
        cout << "员工类型：技术员工" << endl;
    }
};

class Manager : virtual public Employee 
{
protected:
    float monthlyPay;
public:
    Manager(int id, string name, int mage, float mweight, float mMonthlyPay)
        : Employee(id, name, mage, mweight), monthlyPay(mMonthlyPay) {}
    Manager() {}
    void setMonthlyPay(float pay) {    monthlyPay = pay;    }
    float getMonthlyPay() {    return monthlyPay;    }
    virtual void pay()
    {
        money = monthlyPay;
    }
    virtual void showtype()
    {
        cout << "经理类员工" << endl;
    }
};

class Salesman : virtual public Employee 
{
protected:
    float sales;
    float salesRate;
public:
    Salesman(int id, string name,int mage,float mweight, float msales,float mSalesRate)
        : Employee(id,name ,mage,mweight), sales(msales), salesRate(mSalesRate) {}
    Salesman() {}
    void setSales(float empSales) {sales = empSales;}
    void setSalesRate(float rate) {salesRate = rate;}
    virtual void pay()  
    {
        money = sales * salesRate;
    }
    virtual void showtype()
    {
        cout << "销售类员工" << endl;
    }
};

class ManagerSales : public Manager, public Salesman 
{
public:
    ManagerSales(int id, string name, int mage, float mweight, float mMonthlyPay, float msales,float mSalesRate)
    : Employee(id, name, mage, mweight),
      Manager(id, name, mage, mweight, mMonthlyPay),
      Salesman(id, name, mage, mweight, msales,mSalesRate) {}
    ManagerSales() : Employee(), Manager(), Salesman() {}
    virtual void pay() 
    {
        money = monthlyPay + (sales * salesRate);
    }
    virtual void showtype()
    {
        cout << "销售经理类员工" << endl;
    }
};

class Info
{
private:
    vector<Employee*> member;
    int num;
    Technician p1;
    Salesman p2;
    Manager p3;
    ManagerSales p4;
public:
    void addNatural(Employee* mem)
    {
        member.push_back(mem);
    }
    void addInfo()
    {
        int n; 
        printf("请输入员工类型:(1.技术人员 2.销售人员 3.经理 4.销售经理)\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            int id; string name; int mage; float mweight; int mhour; float mhourlyRate;
            printf("技术人员信息初始化...\n");
            printf("请输入员工编号："); scanf("%d", &id);
            printf("请输入员工姓名："); cin >> name;
            printf("请输入年龄："); scanf("%d", &mage);
            printf("请输入体重："); scanf("%f", &mweight);
            printf("请输入工作时间："); scanf("%d", &mhour);
            printf("请输入时薪："); scanf("%f", &mhourlyRate);
            Employee* p =new Technician(id, name, mage, mweight, mhour, mhourlyRate);
            addNatural(p);
            p->pay();
            break;
        }
        case 2:
        {
            int id; string name; int mage; float mweight; float msales; float msalesRate;
            printf("销售人员信息初始化...\n");
            printf("请输入员工编号："); scanf("%d", &id);
            printf("请输入员工姓名："); cin >> name;
            printf("请输入年龄："); scanf("%d", &mage);
            printf("请输入体重："); scanf("%f", &mweight);
            printf("请输入本月销售额："); scanf("%f", &msales);
            printf("请输入提成比例："); scanf("%f", &msalesRate);
            Employee* p = new Salesman(id, name, mage, mweight, msales, msalesRate);
            addNatural(p);
            p->pay();
            break;
        }
        case 3:
        {    
            int id; string name; int mage; float mweight; float mMonthlyPay;
            printf("经理人员信息初始化...\n");
            printf("请输入员工编号："); scanf("%d", &id);
            printf("请输入员工姓名："); cin >> name;
            printf("请输入年龄："); scanf("%d", &mage);
            printf("请输入体重："); scanf("%f", &mweight);
            printf("请输入经理固定月工资："); scanf("%f", &mMonthlyPay);
            Employee* p = new Manager(id, name, mage, mweight, mMonthlyPay);
            addNatural(p);
            p->pay();
            break;
        }
        case 4:
        {
            int id; string name; int mage; float mweight; float mMonthlyPay; float msales; float mSalesRate;
            printf("销售经理人员信息初始化...\n");
            printf("请输入员工编号："); scanf("%d", &id);
            printf("请输入员工姓名："); cin >> name;
            printf("请输入年龄："); scanf("%d", &mage);
            printf("请输入体重："); scanf("%f", &mweight);
            printf("请输入销售经理固定月工资："); scanf("%f", &mMonthlyPay);
            printf("请输入销售经理下属部门的本月销售额："); scanf("%f", &msales);
            printf("请输入销售经理的提成比例："); scanf("%f", &mSalesRate);
            Employee* p = new ManagerSales(id, name, mage, mweight, mMonthlyPay, msales, mSalesRate);
            addNatural(p);
            p->pay();
            break;
        }
        }
    }
    void showInfo()
    {
        for (vector<Employee*>::iterator it = member.begin(); it != member.end(); it++)
        {
            (*it)->print2();
        }
    }
    void wirteInfo()
    {
        for (vector<Employee*>::iterator it = member.begin(); it != member.end(); ++it)
        {
            (*it)->writefile();
        }
    }
    void readInfo()
    {
        ifstream ifs;
        ifs.open("employees.txt", ios::in);
        string line;
        while (getline(ifs, line))
        {
            cout << line << endl;
        }
        ifs.close();
    }
};
class Menu
{
private:
    Info info;
public:
    void select_menu()
    {
        printf("***********\n");
        printf("1.添加信息\n");
        printf("2.预览信息\n");
        printf("3.写入文件\n");
        printf("4.读取信息\n");
        printf("5.退出程序\n");
        printf("***********\n");
    }
    void handle_menu()
    {
        int input;
        do
        {
            select_menu();
            printf("请选择1-5："); scanf("%d", &input);
            switch (input)
            {
            case 1:  
                info.addInfo();
                break;
            case 2:
                info.showInfo();
                break;
            case 3:
                info.wirteInfo();
                break;
            case 4:
                info.readInfo();
                break;
            case 5:
                printf("退出程序\n");
                input = 0;
                break;
            default:
                printf("输入错误，请重新输入\n");
                input = 1;
                break;
            }
        } while (input);
    }
};

