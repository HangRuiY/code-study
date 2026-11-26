#include <iostream>
#include <string>
using namespace std;
#include <vector>
//string 构造函数
void test01()
{
	string s1;//默认构造
	const char* str = "hello world";
	string s2(str);//用一个字符串去初始化
	cout << "s2:" << s2 << endl;
	string s3(s2);//拷贝初始化
	cout << "s3:" << s3 << endl;
	string s4(10, 'a');//10个a字符串
	cout << "s4:" << s4 << endl;
}
//string 赋值操作
void test02()
{
	string str1; str1 = "hello";
	cout << str1 << endl;

	string str2;
	str2 = str1;
	cout << str2 << endl;

	string str3;
	str3 = 'a';
	cout << str3 << endl;

	string str4;
	str4.assign("hello world");
	cout << str4 << endl;

	string str5;
	str5.assign("hello world",5); //输出前五个字符
	cout << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << str6 << endl;

	string str7;
	str7.assign(10, 'w');//10个w
	cout << str7 << endl;

}
//string 字符串拼接
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏:";
	cout << str1 << endl;
	string str2 = " lol dnf ";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << str3 << endl;
	str3.append("game abcdef", 4);//前四个字符拼接过去
	cout << str3 << endl;

	/*str3.append(str2); 
	cout << str3 << endl;*/
	//str3.append(str2,0,4);//从str2里面的第0个下标开始 截取4个元素
	//cout << str3 << endl;
	str3.append(str2, 4, 4);
	cout << str3 << endl;

}
//string 字符串查找
void test04()
{
	string str1 = "abcdefdef";
	int pos = str1.find("def"); //返回首字符的下标 找不到返回-1
	cout << pos << endl;
	//rfind 和 find
	//rfind从右往左查找，返回的下标依旧从0开始 find从左往右查
	pos = str1.rfind("def");
	cout << pos << endl;
}
//string 字符串替换
void test05()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111"); //从1下标开始 3个字符 替换成1111
	cout << str1 << endl;
}
//string 字符串比较
void test06()
{
	string s1 = "xello";
	string s2 = "hello";
	if (s1.compare(s2) == 0)
		printf("相等\n");
	else if (s1.compare(s2) > 0)
		printf("s1比s2大\n");
	else
		printf("s1比s2小\n");
}
//string 字符串存取
void test07()
{
	string str = "hello";
	//1.通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	//2.通过at访问
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//修改单个字符
	str[0] = 'x';
	cout << str << endl;
	str.at(1) = 'x';
	cout << str << endl;
}
//string 字符串插入和删除
void test08()
{
	string str = "hello";
	//插入
	str.insert(1, "111");//在下标为1的位置 之前 插入111
	cout << str << endl;
	//删除
	str.erase(1, 3);//从下标为1的位置开始 删除3个字符
	cout << str << endl;
}
//string 子串获取
void test09()
{
	//str求子串
	string str = "abcdef";
	string substr = str.substr(1, 3);
	cout << substr << endl;

	string s = "zhangsan@qq.com";
	int pos = s.find("@");
	string substr2 = s.substr(0, pos);
	cout << substr2 << endl;
}
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//    //test04();
//	//test05();
//	//test06();
//	//test07();
//	//test08();
//	test09();
//}
int countBalls(int lowLimit, int highLimit)
{
	int arr[1010] = {0};
	int ans = 0;
	for (int i = lowLimit; i <= highLimit; i++)
	{
		int x = i; int k = 0;
		while (x)
		{
			k = x % 10;
			x /= 10;
		}
		arr[k]++;
	}
	for (int i = 0; i < 1010; i++)
		ans = max(ans, arr[i]);
	return ans;
}
int main()
{
	cout << countBalls(5, 15);
}