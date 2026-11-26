#include <iostream>
#include <math.h>
using namespace std;
//class Point {
//private:
//    double x;
//    double y;
//public:  
//    Point(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {} 
//    double getX() const { return x; }
//    double getY() const { return y; }
//};
//class Distance {
//private:
//    Point p1;
//    Point p2;
//    double distance;
//public:
//    Distance(const Point& point1, const Point& point2) : p1(point1), p2(point2) {
//        calculateDistance();
//    }
//    double getDistance() const {
//        return distance;
//    }
//private:
//    void calculateDistance() {
//        double deltaX = p2.getX() - p1.getX();
//        double deltaY = p2.getY() - p1.getY();
//        distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
//    }
//};
//
//int main() {
//    Point point1(0, 0);
//    Point point2(3, 4);
//    Distance dist(point1, point2);
//    double result = dist.getDistance();
//    cout << result;
//    return 0;
//}

//class Shape {
//protected:
//    double height;
//    double width;
//public:
//    Shape(double h, double w) : height(h), width(w) {}
//    Shape() : height(0.0), width(0.0) {}
//    Shape(const Shape& other) : height(other.height), width(other.width) {}
//    virtual ~Shape() {}
//    void setDimensions(double h, double w) {
//        height = h;
//        width = w;
//    }
//    virtual void displayInfo() const {
//        std::cout << "高度: " << height << ", 宽度: " << width << std::endl;
//    }
//    virtual double area() const = 0;
//};
//class Rectangle : public Shape {
//public:
//    Rectangle(double h, double w) : Shape(h, w) {}
//    double area() const override {
//        return height * width;
//    }
//};
//class IsoscelesTriangle : public Shape {
//public:
//    IsoscelesTriangle(double h, double w) : Shape(h, w) {}
//    double area() const override {
//        return 0.5 * height * width;
//    }
//};
//int main() {
//    Rectangle rectangle(5.0, 4.0);
//    std::cout << "矩阵面积: " << rectangle.area() << std::endl;
//    IsoscelesTriangle triangle(6.0, 3.0);
//    std::cout << "三角形面积: " << triangle.area() << std::endl;
//    return 0;
//}

//class Information {
//private:
//    int age;
//    string sex;
//public:
//    Information(int age, std::string sex) : age(age), sex(sex) {}
//    Information() : age(0), sex("Unknown") {}
//    ~Information() {}
//    void setAge(int newAge) {
//        age = newAge;
//    }
//    int getAge() const {
//        return age;
//    }
//    void setSex(std::string newSex) {
//        sex = newSex;
//    }
//    std::string getSex() const {
//        return sex;
//    }
//    void printInfo() const {
//        cout << "Age: " << age << ", Sex: " << sex << endl;
//    }
//};
//class Student {
//private:
//    int id;
//    string name;
//    double mathScore;
//    double chineseScore;
//    double totalScore;
//    Information info;
//
//public:
//    Student(int id, std::string name, double mathScore, double chineseScore, const Information& info)
//        : id(id), name(name), mathScore(mathScore), chineseScore(chineseScore), info(info) {
//        totalScore = mathScore + chineseScore;
//    }
//    Student() : id(0), name("Unknown"), mathScore(0), chineseScore(0), totalScore(0) {}
//
//    ~Student() {}
//    void setStudentInfo(int newId, std::string newName, double newMathScore, double newChineseScore, const Information& newInfo) {
//        id = newId;
//        name = newName;
//        mathScore = newMathScore;
//        chineseScore = newChineseScore;
//        info = newInfo;
//        totalScore = mathScore + chineseScore;
//    }
//    void getStudentInfo(int& getId, std::string& getName, double& getMathScore, double& getChineseScore, Information& getInfo) const {
//        getId = id;
//        getName = name;
//        getMathScore = mathScore;
//        getChineseScore = chineseScore;
//        getInfo = info;
//    }
//    void displayStudentInfo() const {
//        std::cout << "ID: " << id << ", Name: " << name << ", Math Score: " << mathScore << ", Chinese Score: " << chineseScore << ", Total Score: " << totalScore << std::endl;
//        info.printInfo();
//    }
//    void getTopStudentInfo(int& getId, std::string& getName, std::string& getSex, int& getAge, double& getMathScore, double& getChineseScore) const {
//        getId = id;
//        getName = name;
//        getSex = info.getSex();
//        getAge = info.getAge();
//        getMathScore = mathScore;
//        getChineseScore = chineseScore;
//    }
//    static double calculateAverageScore(const Student* students, int numStudents) {
//        double totalScore = 0;
//        for (int i = 0; i < numStudents; ++i) {
//            totalScore += students[i].totalScore;
//        }
//        return (numStudents > 0) ? (totalScore / numStudents) : 0;
//    }
//    static void sortStudentsByTotalScore(Student* students, int numStudents) {
//        for (int i = 0; i < numStudents - 1; ++i) {
//            for (int j = 0; j < numStudents - i - 1; ++j) {
//                if (students[j].totalScore > students[j + 1].totalScore) {
//                    std::swap(students[j], students[j + 1]);
//                }
//            }
//        }
//    }
//};
//int main() {
//    int numStudents;
//    cout << "输入学生个数: ";
//    cin >> numStudents;
//    Student* students = new Student[numStudents];
//    for (int i = 0; i < numStudents; ++i) {
//        int id;
//        string name;
//        double mathScore, chineseScore;
//        int age; string sex;
//        cout << "输入学生" << i + 1 << " 信息:" << endl;
//        cout << "ID: ";
//        cin >> id;
//        cout << "Name: ";
//        cin >> name;
//        cout << "Math Score: ";
//        cin >> mathScore;
//        cout << "Chinese Score: ";
//        cin >> chineseScore;
//        cout << "Age:";
//        cin >> age;
//        cout << "Sex:";
//        cin >> sex;
//        Information info(age, sex);
//        students[i].setStudentInfo(id, name, mathScore, chineseScore, info);
//    }
//    double averageScore = Student::calculateAverageScore(students, numStudents);
//    cout << "平均分: " << averageScore << endl;
//
//    int topId;
//    string topName, topSex;
//    int topAge;
//    double topMathScore, topChineseScore;
//    students[0].getTopStudentInfo(topId, topName, topSex, topAge, topMathScore, topChineseScore);
//    cout << "第一名信息:" << endl;
//    cout << "ID: " << topId << ", Name: " << topName << ", Sex: " << topSex << ", Age: " << topAge << ", Math Score: " << topMathScore << ", Chinese Score: " << topChineseScore << std::endl;
//
//    Student::sortStudentsByTotalScore(students, numStudents);
//    cout << "升序排列:" << endl;
//    for (int i = 0; i < numStudents; ++i) {
//        students[i].displayStudentInfo();
//    }
//    delete[] students;
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//#define M_PI 3.14
//class Shape {
//public:
//    virtual double getArea() = 0;
//    virtual double getPerim() = 0;
//};
//
//class Rectangle : public Shape 
//{
//private:
//    double length;
//    double width;
//
//public:
//    Rectangle(double l, double w) : length(l), width(w) { }
//
//    double getArea() {
//        return length * width;
//    }
//
//    double getPerim() {
//        return 2 * (length + width);
//    }
//};
//
//class Circle : public Shape 
//{
//private:
//    double radius;
//
//public:
//    Circle(double r) : radius(r) { }
//
//    double getArea() {
//        return M_PI * radius * radius;
//    }
//
//    double getPerim() {
//        return 2 * M_PI * radius;
//    }
//};
//
//int main() {
//    int shapeType;
//    cin >> shapeType;
//
//    if (shapeType == 1) {
//        double length, width;
//        cin >> length >> width;
//
//        Rectangle rectangle(length, width);
//        cout << "area=" << rectangle.getArea() << endl;
//        cout << "perim=" << rectangle.getPerim() << endl;
//    }
//    else if (shapeType == 2) {
//        double radius;
//        cin >> radius;
//        Circle circle(radius);
//        cout << "area=" << circle.getArea() << endl;
//        cout << "perim=" << circle.getPerim() << endl;
//    }
//    else {
//        cout << "输入无效的图形类型！" << endl;
//    }
//
//    return 0;
//}

#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int n, m, t, w, flag1 = 1, flag2 = 1, flag4 = 1, flag5 = 1;
    int* Available, * Request, * Finish;
    int** Allocation, ** Max, ** Need, ** Work;
    FILE* fp;

    fp = fopen("/home/shiyanlou/data.txt", "r");
    fscanf(fp, "%d", &n), fscanf(fp, "%d", &m);

    Available = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        fscanf(fp, "%d", &Available[i]);

    Allocation = (int**)malloc(sizeof(int) * n);
    Max = (int**)malloc(sizeof(int*) * n);
    Need = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        Allocation[i] = (int*)malloc(sizeof(int) * m);
        Max[i] = (int*)malloc(sizeof(int) * m);
        Need[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &t);
        for (int j = 0; j < m; j++)
            fscanf(fp, "%d", &Allocation[t][j]);
        for (int j = 0; j < m; j++)
            fscanf(fp, "%d", &Max[t][j]);
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            Available[i] -= Allocation[j][i];

    fscanf(fp, "%d", &w);
    Request = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        fscanf(fp, "%d", &Request[i]);

    for (int i = 0; i < m; i++)
        if (Request[i] > Need[w][i])
            flag1 = 0;
    if (!flag1)
        printf("False");
    else {
        for (int i = 0; i < m; i++)
            if (Request[i] > Available[i])
                flag2 = 0;
        if (!flag2)
            printf("p %d 等待", w);
        else {
            for (int i = 0; i < m; i++) {
                Available[i] -= Request[i];
                Allocation[w][i] += Request[i];
                Need[w][i] -= Request[i];
            }

            Work = (int**)malloc(sizeof(int*) * n);
            for (int i = 0; i < n; i++)
                Work[i] = (int*)malloc(sizeof(int) * m);
            Finish = (int*)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
                Finish[i] = 0;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    Work[i][j] = Available[j];
            printf("Safe Sequence: ");
            while (flag5) {
                for (int i = 0; i < n; i++) {
                    int flag3 = 1;
                    for (int j = 0; j < m; j++)
                        if (Need[i][j] > Work[i][j])
                            flag3 = 0;
                    if (!Finish[i] && flag3) {
                        printf("%d ", i);  // 输出安全序列
                        Finish[i] = 1;
                        for (int j = 0; j < n; j++)
                            for (int k = 0; k < m; k++)
                                if (j != i && !Finish[j])
                                    Work[j][k] = Work[i][k] + Allocation[i][k];
                        break;
                    }
                    else if (i == n - 1) {
                        for (int j = 0; j < n; j++)
                            if (!Finish[j])
                                flag4 = 0;
                        if (flag4) {
                            printf("\n系统处于安全状态\n");
                            printf("Work:\n");
                            for (int j = 0; j < n; j++) {
                                for (int k = 0; k < m; k++)
                                    printf("%4d", Work[j][k]);
                                printf("\n");
                            }
                            printf("Allocation:\n");
                            for (int j = 0; j < n; j++) {
                                for (int k = 0; k < m; k++)
                                    printf("%4d", Allocation[j][k]);
                                printf("\n");
                            }
                            printf("Need:\n");
                            for (int j = 0; j < n; j++) {
                                for (int k = 0; k < m; k++)
                                    printf("%4d", Need[j][k]);
                                printf("\n");
                            }
                            printf("Available:\n");
                            for (int j = 0; j < m; j++)
                                printf("%4d", Work[n - 1][j] + Allocation[n - 1][j]);
                            flag5 = 0;
                        }
                        else {
                            printf("系统处于不安全状态\n");
                            for (int j = 0; j < m; j++) {
                                Available[j] += Request[j];
                                Allocation[w][j] -= Request[j];
                                Need[w][j] += Request[j];
                            }
                            flag5 = 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}