#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//乒乓球
//int main()
//{
//	char ch[2501][30];
//	bool pd = true;
//	int tot = 0; // 用来记下题设所给字符串中有效字符串的个数，即在“E”之前的字符串。
//	cin >> ch[0];
//	int left = 0, right = 0;  //左比分，右比分
//	while (pd)
//	{
//		int len = strlen(ch[tot]);
//		for (int i = 0; i < len; i++)
//		{
//			if (ch[tot][i] == 'W') left++;
//			if (ch[tot][i] == 'L') right++;
//			if (ch[tot][i] == 'E')
//			{
//				cout << left << ':' << right << endl;
//				pd = false;
//				i = len;
//			}
//			if ((left >= 11 || right >= 11) && (abs(left - right)) >= 2)
//			{
//				cout << left << ':' << right << endl;
//				left = 0;
//				right = 0;
//			}
//		}
//		if (pd)
//		{
//			tot++;
//			cin >> ch[tot];
//		}
//	}
//	cout << endl;
//	left = 0;
//	right = 0;          
//	//21分制的初始化
//	for (int j = 0; j <= tot; j++)
//	{
//		int len = strlen(ch[j]);
//		for (int i = 0; i < len; i++)
//		{
//			if (ch[j][i] == 'W') left++;
//			if (ch[j][i] == 'L') right++;
//			if (ch[j][i] == 'E')
//			{
//				cout << left << ':' << right << endl;
//				return 0;//直接结束程序
//			}
//			if ((left >= 21 || right >= 21) && (abs(left - right)) >= 2)
//			{
//				cout << left << ':' << right << endl;
//				left = 0;
//				right = 0;
//			}
//		}
//	}
//}
//

//扫雷
//char arr[101][101];
//int main()
//{
//	int n, m;
//	cin >> n >> m;  //3  3
//	for (int i = 0; i < n; i++)
//	{                                 // * ? ?
//	  	for (int j = 0; j < m; j++)   // ? ? ?
//			cin >> arr[i][j];         // ? * ?
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (arr[i][j] == '*')
//			{
//				cout << '*';
//				continue;
//			}
//			int cnt = 0;
//			for (int x = i - 1; x <= i + 1; x++)
//				for (int y = j - 1; y <= j + 1; y++)
//					if (x != i || y != j)
//					{
//						if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '*')
//							cnt++;
//					}
//			cout << cnt;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//

//A+B高精度
//string s1, s2;
//int a[503], b[503], c[503];
//int la, lb, lc;
//int main()
//{
//	cin >> s1 >> s2;
//	la = s1.size();
//	lb = s2.size();
	//for (int i = 0; i < la; i++)   //字符转化为数值，并转置存放 
	//	a[la - i] = s1[i] - '0';
	//for (int i = 0; i < lb; i++)
	//	b[lb - i] = s2[i] - '0';
//	lc = max(la, lb) + 1;
//	for (int i = 1; i < lc; i++)
//	{
//		c[i] += a[i] + b[i];     //核心代码 
//		c[i + 1] = c[i] / 10;
//		c[i] = c[i] % 10;
//	}//01001 09909
//	if (c[lc] == 0)              //删除前导0 
//		lc--;
//	for (int i = lc; i > 0; i--) //输出c[lc] ~ c[1]
//		cout << c[i];
//	return 0;
//}
//

//A*B高精度
//char a1[50001], b1[50001];
//int a[50001], b[50001], i, x, len, j, c[50001];
//int main()
//{
//    cin >> a1 >> b1;//读入两个数
//    a[0] = strlen(a1); b[0] = strlen(b1);//计算长度
//    for (i = 1; i <= a[0]; ++i)
//        a[i] = a1[a[0] - i] - '0';//将字符串转换成数字
//    for (i = 1; i <= b[0]; ++i)
//        b[i] = b1[b[0] - i] - '0';
//    for (i = 1; i <= a[0]; ++i)
//        for (j = 1; j <= b[0]; ++j)
//            c[i + j - 1] += a[i] * b[j];//按乘法
//    len = a[0] + b[0];                                       //原理进行高精乘
//    for (i = 1; i < len; ++i)
//        if (c[i] > 9)
//        {
//            c[i + 1] += c[i] / 10;
//            c[i] %= 10;
//        }//进位
//    while (c[len] == 0 && len > 1)
//        len--;//判断位数
//    for (i = len; i >= 1; --i)
//        cout << c[i];//输出
//    return 0;
//}
// 
 
//分解最大乘积
//vector<int>mul(vector<int>&A, int b) 
//{
//    vector<int>C;
//    int t = 0;
//    for (int i = A.size() - 1; i >= 0; i--) 
//    {
//        t += A[i] * b;
//        C.push_back(t % 10);
//        t /= 10;
//    }
//    while (t) 
//    {
//        C.push_back(t % 10);
//        t /= 10;
//    }
//    while (C.size() > 1 && C.back() == 0)
//        C.pop_back();
//    reverse(C.begin(), C.end());
//    return C;
//}
//int s[5000];
//int n = 0;
//int main()
//{
//	cin >> n;//10
//	if (n <= 4)
//	{
//		cout << 1 << " " << n - 1 << endl;
//		cout << n - 1 << endl;
//	}
//	else
//	{
//        int res = 0, index = 0;
//        vector<int>v;
//        v.push_back(1);
//        for (int i = 2; res < n; i++) 
//        {
//            res += i;
//            s[index++] = i;
//        }
//        if (res > n)
//            index--;
//        for (int i = 0; i <= index; i++) 
//        {
//            if (s[i] == res - n)
//                continue;
//            v = mul(v, s[i]);
//            cout << s[i] << " ";
//        }
//        cout << endl;
//        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//            cout << *it;
//	}
//    return 0;
//}
//
 
//石头剪刀布
//int main()
//{
//	int n = 0;//次数
//	cin >> n;
//	int arr1[201] = { 0 }; int a1; //a的周期 
//	int arr2[201] = { 0 }; int a2; //b的周期
//	cin >> a1 >> a2; // 5 6
//	for (int i = 0; i < a1; i++)
//		cin >> arr1[i]; //0 1 2 3 4
//	for (int i = 0; i < a2; i++)
//		cin >> arr2[i];//0 3 4 2 1 0
//	int sa = 0; int sb = 0;
//	int a_pos = 0; int b_pos = 0;
//	while (n--)
//	{
//		//a赢
//		if ((arr1[a_pos] == 0 && (arr2[b_pos] == 2 || arr2[b_pos] == 3)) ||
//			(arr1[a_pos] == 1 && (arr2[b_pos] == 3 || arr2[b_pos] == 0)) ||
//			(arr1[a_pos] == 2 && (arr2[b_pos] == 4 || arr2[b_pos] == 1)) ||
//			(arr1[a_pos] == 3 && (arr2[b_pos] == 4 || arr2[b_pos] == 2)) ||
//			(arr1[a_pos] == 4 && (arr2[b_pos] == 1 || arr2[b_pos] == 0)))
//		{
//			sa++;
//		}
//		//b赢
//		else if ((arr2[b_pos] == 0 && (arr1[a_pos] == 2 || arr1[a_pos] == 3)) ||
//			     (arr2[b_pos] == 1 && (arr1[a_pos] == 3 || arr1[a_pos] == 0)) ||
//			     (arr2[b_pos] == 2 && (arr1[a_pos] == 4 || arr1[a_pos] == 1)) ||
//			     (arr2[b_pos] == 3 && (arr1[a_pos] == 4 || arr1[a_pos] == 2)) ||
//			     (arr2[b_pos] == 4 && (arr1[a_pos] == 1 || arr1[a_pos] == 0)) )
//		{
//			sb++;
//		}
//		a_pos++; b_pos++;
//		if (a_pos == a1 )
//			a_pos = 0;
//		if (b_pos == a2 )
//			b_pos = 0;
//	}
//	cout << sa << " " << sb;
//	return 0;
//}
//

//玩具眼镜
//struct MyStruct
//{
//	int h;
//	string name;
//}a[100001];
//int  main() 
//{
//	int n, m, x, y;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) 
//	{
//		cin >> a[i].h >> a[i].name;
//	}
//	int z = 0;
//	for (int i = 0; i < m; i++) 
//	{
//		cin >> x >> y;
//		if (x == 0 && a[z].h == 0) 
//		{//往左数并且面朝里，顺时针
//			z = (z + n - y) % n;
//		}
//		else if (x == 0 && a[z].h == 1) 
//		{//往左数，面朝外，逆时针
//			z = (z + y) % n;
//		}
//		else if (x == 1 && a[z].h == 0) 
//		{//往右数，面朝里，逆时针
//			z = (z + y) % n;
//		}
//		else if (x == 1 && a[z].h == 1) 
//		{//往左数，面朝外，顺时针
//			z = (z + n - y) % n;
//		}
//	}
//	cout << a[z].name;
//	return 0;
//}
//

//魔法少女
//int a[1000][1000];
//int b[1000][1000];
//void chuangershuzu(int p)//创建一个1到n^2的二维数组
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < p; i++)
//	{
//		for (j = 0; j < p; j++)
//		{
//			a[i][j] = ++k;
//		}
//	}
//
//}
//void xuanzhuanshuzu(int x, int y, int r, int z)
//{
//	if (z == 0)//顺时针
//	{
//
//		for (int i = 0; i <= 2 * r; i++)
//		{
//			for (int j = 0; j <= 2 * r; j++)
//			{
//				b[i][j] = a[x + r - 1 - j][y - r - 1 + i];//x+r-1是应该旋转的最后一行，y-r-1是第一列，这样就可以找到左下角的数，然后把每一列分别旋转到行的位置，就实现了顺时针旋转
//			}
//		}
//
//		for (int i = 0; i <= 2 * r; i++)//减一是因为数组有第0行，而现实说的时候没有
//		{
//			for (int j = 0; j <= 2 * r; j++)
//			{
//				a[x - r - 1 + i][y - r - 1 + j] = b[i][j];//将b数组传回去
//			}
//		}
//
//	}
//	else if (z == 1)//逆时针
//	{
//		for (int i = 0; i <= 2 * r; i++)
//		{
//			for (int j = 0; j <= 2 * r; j++)//参考顺时针旋转
//			{
//				b[i][j] = a[x - r - 1 + j][y + r - 1 - i];
//			}
//		}
//		for (int i = 0; i <= 2 * r; i++)
//		{
//			for (int j = 0; j <= 2 * r; j++)
//			{
//				a[x - r - 1 + i][y - r - 1 + j] = b[i][j];
//			}
//		}
//
//	}
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	getchar();
//	int i = 0;
//	int j = 0;
//	int x = 0; int y = 0; int r = 0; int z = 0;
//	chuangershuzu(n);//创建二维数组
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d %d %d %d", &x, &y, &r, &z);
//
//		xuanzhuanshuzu(x, y, r, z);//旋转数组
//	}
//	for (i = 0; i < n; i++)//输出
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//

//阶乘数码
//int m[10000008];
//void JC(int k) {
//	int i, j;
//	for (i = 1; i < m[0]; i++) 
//	{//乘法
//		m[i] *= k;
//	}
//	for (i = 1; i < m[0]; i++) {//进位，这样进位是为了让程序更有可读性
//		if (m[i] >= 10) 
//		{
//			m[i + 1] += m[i] / 10;
//			m[i] %= 10;
//		}
//	}
//	while (m[m[0]]) 
//	{//在最高位不为零时接着进位
//		m[m[0] + 1] += m[m[0]] / 10;
//		m[m[0]] %= 10;
//		m[0]++;
//	}
//}
//
//int main() 
//{
//	int n, t, a, i, j;
//	cin >> t;
//	while (t--) 
//	{
//		cin >> n >> a;
//		memset(m, 0, sizeof(m));//每次初始化为0 
//		m[0] = m[1] = 1;
//		int cnt = 0;
//		for (i = 1; i <= n; i++) 
//		{
//			JC(i);
//		}
//		for (i = 1; i < m[0]; i++) 
//		{
//			if (m[i] == a) 
//			{
//				cnt++;
//			}
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}
//

//两个牛
//char m[12][12];//地图
//int f[3], c[3], ans, tdz;//农夫，奶牛，秒数，专属值
//bool zt[160005];//记录专属值是否出现
//void move(int x, int y, int mi, int h) 
//{//移动函数
//	if (mi == 0) 
//	{
//		if (m[x - 1][y] == '*')
//		{
//			if (h == 0)
//				f[0] = 1;
//			else 
//				c[0] = 1;
//		}
//		else if (h == 0) 
//			f[1]--; 
//		else 
//			c[1]--;
//	}
//	else if (mi == 1) 
//	{
//		if (m[x][y + 1] == '*')
//		{
//			if (h == 0)
//				f[0] = 2;
//			else c[0] = 2;
//		}
//		else if (h == 0) 
//			f[2]++; 
//		else 
//			c[2]++;
//	}
//	else if (mi == 2) 
//	{
//		if (m[x + 1][y] == '*')
//		{
//			if (h == 0)
//				f[0] = 3;
//			else c[0] = 3;
//		}
//		else if (h == 0) 
//			f[1]++; 
//		else c[1]++;
//	}
//	else 
//	{
//		if (m[x][y - 1] == '*')
//		{
//			if (h == 0)
//				f[0] = 0;
//			else c[0] = 0;
//		}
//		else if (h == 0) 
//			f[2]--; 
//		else c[2]--;
//	}
//}
//bool pd() 
//{ //判断循环终止条件：如果奶牛坐标与农夫坐标相等，则他们重叠，返回0，退出循环
//	if (f[1] == c[1] && f[2] == c[2]) 
//		return 0;
//	else 
//		return 1;
//}
//int main() 
//{
//	//定义一个12*12的表格，这样便于判断边界 ，输入10*10的表格，表示牛和农夫
//	for (int i = 0; i <= 11; i++)
//		m[i][0] = '*', m[i][11] = '*';
//	for (int i = 1; i <= 11; i++) 
//		m[0][i] = '*', m[11][i] = '*';
//	for (int i = 1; i <= 10; i++) 
//	{
//		for (int j = 1; j <= 10; j++) 
//		{
//			cin >> m[i][j];
//			if (m[i][j] == 'F') 
//				f[1] = i, f[2] = j;
//			if (m[i][j] == 'C') 
//				c[1] = i, c[2] = j;
//		}
//	}
//	while (pd()) 
//	{//模拟每秒
//		tdz = f[1] + f[2] * 10 + c[1] * 100 + c[2] * 1000 + f[0] * 10000 + c[0] * 40000;
//		if (zt[tdz]) 
//		{//死循环了就输出0并结束程序
//			cout << 0 << endl;
//			return 0;
//		}
//		zt[tdz] = 1;//标记
//		move(f[1], f[2], f[0], 0);
//		move(c[1], c[2], c[0], 1);//依次移动农夫和奶牛
//		ans++;//记录秒数
//	}
//	cout << ans << endl;//输出
//	return 0;
//}
//

//帮贡排序
//#include <map>
//typedef struct member 
//{
//	string name;
//	string post;
//	long long banggong;
//	int level;
//}member;
//
//int main()
//{
//	member a[120];
//	int n;
//	map<string, int>m;
//	m.insert(make_pair("yishuchu", -1));
//	m.insert(make_pair("BangZhong", 0));
//	m.insert(make_pair("JingYing", 1));
//	m.insert(make_pair("TangZhu", 2));
//	m.insert(make_pair("ZhangLao",3));
//	m.insert(make_pair("HuFa", 4));
//	string plist[38] = { "HuFa","HuFa",
//	"ZhangLao","ZhangLao","ZhangLao","ZhangLao",
//	"TangZhu","TangZhu","TangZhu","TangZhu","TangZhu","TangZhu","TangZhu",
//	"JingYing","JingYing","JingYing","JingYing","JingYing",
//	"JingYing","JingYing","JingYing","JingYing","JingYing",
//	"JingYing","JingYing","JingYing","JingYing","JingYing",
//	"JingYing","JingYing","JingYing","JingYing","JingYing",
//	"JingYing","JingYing","JingYing","JingYing","JingYing" };
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i].name >> a[i].post >> a[i].banggong >> a[i].level;
//	}
//	for (int i = 3; i < n; i++)
//	{
//		int max = -1, t;
//		for (int j = 3; j < n; j++)
//		{
//			if (a[j].banggong > max)
//			{
//				t = j;
//				max = a[j].banggong;
//			}
//		}
//		if (i - 3 > 37)
//		{
//			a[t].post = "BangZhong";
//		}
//		else
//		{
//			a[t].post = plist[i - 3];
//		}
//		a[t].banggong = -2;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		cout << a[i].name << ' ' << a[i].post << ' ' << a[i].level << endl;
//	}
//	for (int i = 3; i < n; i++)
//	{
//		int t = 3;
//		for (int j = 4; j < n; j++)
//		{
//			if ((m[a[j].post] > m[a[t].post]) || (a[j].post == a[t].post && a[j].level > a[t].level))
//			{
//				t = j;
//			}
//		}
//		cout << a[t].name << ' ' << a[t].post << ' ' << a[t].level << endl;
//		a[t].post = "yishuchu";
//	}
//
//	return 0;
//}
// 
// 
 
//字符串-垂直柱状图
//int main()
//{
//	vector<int>num;
//	num.resize(26, 0);
//	vector<char>word;
//	word.push_back('A');
//	word.push_back('B');
//	word.push_back('C');
//	word.push_back('D');
//	word.push_back('E');
//	word.push_back('F');
//	word.push_back('G');
//	word.push_back('H');
//	word.push_back('I');
//	word.push_back('J');
//	word.push_back('K');
//	word.push_back('L');
//	word.push_back('M');
//	word.push_back('N');
//	word.push_back('O');
//	word.push_back('P');
//	word.push_back('Q');
//	word.push_back('R');
//	word.push_back('S');
//	word.push_back('T');
//	word.push_back('U');
//	word.push_back('V');
//	word.push_back('W');
//	word.push_back('X');
//	word.push_back('Y');
//	word.push_back('Z');
//	string s;
//	string S;
//	for (int i = 0; i < 4; i++) 
//	{
//		getline(cin, s);
//		S += s;
//	}
//	for (int i = 0; i < S.size(); i++) 
//	{
//		for (int j = 0; j < 26; j++) 
//		{
//			if (S[i] == word[j]) 
//			{
//				num[j]++;
//				break;
//			}
//		}
//	}
//	int Max = num[0];
//	for (int i = 1; i < 26; i++) 
//	{
//		if (num[i] >= Max) 
//		{
//			Max = num[i];
//		}
//	}
//	int temp = Max;
//	for (int i = 0; i < Max; i++) 
//	{
//		for (int j = 0; j < 26; j++)
//		{
//			if (num[j] >= temp) 
//			{
//				if (j != 25) 
//				{
//					cout << "*" << " ";
//				}
//				else 
//				{
//					cout << "*";
//				}
//			}
//			else 
//			{
//				cout << " " << " ";
//			}
//		}
//		cout << endl;
//		temp--;
//	}
//	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
//	return 0;
//}