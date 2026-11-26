//P1028 [NOIP2001 普及组] 数的计算 - 记忆化
//#include <iostream>
//using namespace std;
//int a[1010];
//int f(int n)
//{
//	if (a[n] != 0)
//		return a[n];
//	int cnt = 0;
//	cnt++;//本身算一种
//	for (int i = 1; i <= n / 2; i++)
//	{
//		cnt += f(i);
//	}
//	a[n] = cnt;
//	return a[n];
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << f(n);
//}
// 
//P1036 [NOIP2002 普及组] 选数 - 深度搜索
//#include <iostream>
//using namespace std;
//int a[30];
//int cnt = 0;
//int n, k;
//int sushu(int x)
//{
//	int i = 0; int j = 0;
//	for (int i = 2; i * i <= x; i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//void f(int p, int x, int s)
//{
//	if (x == k)
//	{
//		if (sushu(s) == 1)
//		{
//			cnt++;
//			return;
//		}
//	}
//	if (p > n)
//	{
//		return;
//	}
//	f(p + 1, x + 1, s + a[p]);//选了p
//	f(p + 1, x, s);//没选p
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	f(1, 0, 0);//第几号位置  用了几个数字  和是多少
//	cout << cnt;
//	return 0;
//}
// 
//P1149[NOIP2008 提高组] 火柴棒等式 
//#include <iostream>
//using namespace std;
//int m[10]= { 6,2,5,5,4,5,6,3,7,6 };
//int n = 0;
//int t = 0;
//int f(int x)//计算这样一个数字需要几根火柴棒
//{
//	if (x == 0)
//		return 6;
//	int sum = 0;
//	while (x > 0)
//	{
//		sum += m[x % 10];
//		x /= 10; 
//	}
//	return sum;
//}
//int main()
//{
//	int cnt = 0;
//	cin >> n;//火柴棒数量
//	t = n - 4;
//	for (int i = 0; i <= 1000; i++)
//	{
//		for (int j = 0; j <= 1000; j++)
//		{
//			if (f(i) + f(j) + f(i+j) == t)
//			{
//				cnt++;
//			}
//		}
//	}
//	cout << cnt;
//	return 0;
//}
// 
//回文质数
//#include <iostream>
//using namespace std;
//int m[10000];
//int x, y, a, b, c, d, e, p;
//int sushu(int x)
//{
//	if (x == 1)
//		return 0;
//	int i = 0; int j = 0;
//	for (int i = 2; i * i <= x; i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	cin >> x >> y;
//	for (int i = 1; i <= 9; i++)//一位数字
//	{
//		if (sushu(i) == 1)
//			m[++p] = i;
//	}
//	m[++p] = 11;//二位数字
//	for (int a = 1; a <= 9; a++)//三位数字
//	{
//		for (int b = 0; b <= 9; b++)
//		{
//			if (sushu(a * 100 + b * 10 + a) == 1)
//			{
//				m[++p] = a * 100 + b * 10 + a;
//			}
//		}
//	}
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 0; b <= 9; b++)
//		{
//			for (c = 0; c <= 9; c++)
//			{
//				if (sushu(a * 10000 + b * 1000 + c * 100 + b * 10 + a) == 1)
//				{
//					m[++p] = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
//				}
//			}
//		}
//	}
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 0; b <= 9; b++)
//		{
//			for (c = 0; c <= 9; c++)
//			{
//				for (d = 0; d <= 9; d++)
//				{
//					if (sushu(a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a) == 1)
//					{
//						m[++p] = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= p; i++)
//	{
//		if (m[i] >= x && m[i] <= y)
//		{
//			cout << m[i] << endl;
//		}
//	}
//	return 0;
//
//}
// 
//P1478 陶陶摘苹果（升级版）
//#include <iostream>
//using namespace std;
//int n, s, a, b, x, y;
//struct mem
//{
//	int hi;
//	int ti;
//}m[5050];
//int main()
//{
//	cin >> n >> s;
//	cin >> a >> b;
//	int h = a + b;//最大高度
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x; cin >> y;
//		int p1 = x; int p2 = y;
//		m[i].hi = x; m[i].ti = y;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < n - i; j++)
//		{
//			if (m[j].ti >= m[j + 1].ti)
//			{
//				int temp = m[j].hi; m[j].hi = m[j + 1].hi; m[j + 1].hi = temp;
//				int flag = m[j].ti; m[j].ti = m[j + 1].ti; m[j + 1].ti = flag;
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (m[i].hi <= h  && s>0)
//		{
//			cnt++;
//			s -= m[i].ti;
//		/*	if (s <= 0)
//			{
//				break;
//			}*/
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}
//
//P1618 三连击（升级版）
//#include <iostream>
//using namespace std;
//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
//	int x, y, z,flag;
//	flag = 0;
//	for (x = 123; x <= 987; x++)
//	{
//		y = x / a * b;
//		z = x / a * c;
//		if (x % a != 0 || y >= 1000 || z >= 1000)
//		{
//			continue;
//		}
//		if (x / 100 + x / 10 % 10 + x % 10 +
//			y / 100 + y / 10 % 10 + y % 10 +
//			z / 100 + z / 10 % 10 + z % 10 == 45 &&
//			(x / 100) * (x / 10 % 10) * (x % 10) *
//			(y / 100) * (y / 10 % 10) * (y % 10) *
//			(z / 100) * (z / 10 % 10) * (z % 10) == 362880)
//		{
//			flag = 1;
//			cout << x << " " << y << " " << z << endl;
//		}
//	}
//	if (flag == 0)
//	{
//		cout << "No!!!";
//	}
//	return 0;
//}
//
//P1579 哥德巴赫猜想（升级版）
//#include <iostream>
//using namespace std;
//#include <string>
//int n;
//int sushu(int x)
//{
//	if (x <= 1)
//		return 0;
//	int i = 0; int j = 0;
//	for (int i = 2; i * i <= x; i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//void f(int n)
//{
//	int a, b, c;
//	for (a = 2; a < n; a++)
//	{
//		if (sushu(a) == 1)
//		{
//			for (b = 2; b < n; b++)
//			{
//				if (sushu(b) == 1 && sushu(n-a-b)==1)
//				{
//					cout << a << " " << b << " " << n-a-b;
//					return ;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	f(n);
//}

//P1464 Function - 记忆化
//#include <iostream>
//#include <math.h>
//#include <stdio.h>
//using namespace std;
//long long a, b, c;
//long long mem[22][22][22];
//long long w(long long a, long long b, long long c)
//{
//	if (a <= 0 || b <= 0 || c <= 0)
//	{
//		return 1;
//	}
//	else if (a > 20 || b > 20 || c > 20)
//	{
//		return w(20, 20, 20);
//	}
//	else if (mem[a][b][c] )
//	{
//		return mem[a][b][c];
//	}
//	else if (a < b && b < c)
//	{
//		return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//	}
//	else
//		return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//}
//int main()
//{
//	while (cin >> a >> b >> c)
//	{
//		if (a == -1 && b == -1 && c == -1)
//		{
//			break;
//		}
//		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)<<endl;
//	}
//	return 0;
//}
// 
//P1014 [NOIP1999 普及组] Cantor 表
//#include <iostream>
//using namespace std;
//int n;
//int main()
//{
//	cin >> n;
//	int a = 1;//a表示在第几个环里
//	while (n - a > 0)
//	{
//		n -= a;
//		a++;
//	}
//	if (a % 2 == 0)
//	{
//		cout << n << "/" << a + 1 - n;
//	}
//	else
//	{
//		cout << a + 1 - n << "/" << n;
//	}
//	return 0;
//}
//
//P1022 [NOIP2000 普及组] 计算器的改良
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int main()
//{
//	int deng = 1; int jiaj= 1;
//	int s = 0; int k = 0; int kx = 0;
//	char c = 0;
//	char x = 0;
//	while (cin>>c)
//	{
//		if (c >= 'a' && c <= 'z')//c是字母
//		{
//			x = c;
//			if (s == 0)
//				s = 1;
//			kx += s * deng * jiaj;
//			s = 0;
//		}
//		if (c >= '0' && c <= '9')//c是数字
//		{
//			s = s * 10 + c - '0';
//		}
//		if (c == '=')
//		{
//			k += s * deng * jiaj;
//			s = 0;
//			deng = -1;
//			jiaj = 1;
//		}
//		if (c == '+')
//		{
//			k += s * deng * jiaj;
//			s = 0;
//			jiaj = 1;
//		}
//		if (c == '-')
//		{
//			k += s * deng * jiaj;
//			s = 0;
//			jiaj = -1;
//		}
//	}
//	k += s * deng * jiaj;
//	printf("%c=%.3f",x,-1.0 * (k / kx) );
//	return 0;
//}

//P1003 [NOIP2011 提高组] 铺地毯
//#include <iostream>
//using namespace std;
//int a[100000],b[100000],g[100000],k[100000];
//int x, y;
//int main()
//{
//	int n; cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i] >> b[i] >> g[i] >> k[i];
//	}
//	cin >> x >> y;
//	for (int i = n; i >= 1; i--)
//	{
//		if (a[i] <= x && b[i] <= y && a[i] + g[i] >= x && b[i] + k[i] >= y)
//		{
//			cout << i;
//			return 0;
//		}
//	}
//	cout << -1;
//	return 0;
//}
// 
//P1540 [NOIP2010 提高组] 机器翻译
//#include <iostream>
//#include <queue>
//using namespace std;
//int n, m,k,i;
//int a[1001]; //读入所有数据
//int b[1001]; //模拟队列
//int v[1001]; //标记出现的数字
//int main()
//{
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	int head = 1; int tail = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!v[a[i]])
//		{
//			b[++tail] = a[i];
//			v[a[i]] = 1;
//			
//		}
//		if (tail - head >= m)
//		{
//			v[b[head]] = 0 ;
//			head++;
//		}
//	}
//	cout << tail;
//	return 0;
//}
//
//P1056 [NOIP2008 普及组] 排座椅
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int main()
//{
//	int m, n, k, l, d;
//	cin >> m >> n >> k >> l >> d;
//	int x[1010] = { 0 }, y[1010] = {0};//行列状态
//	for (int i = 1; i <= d; i++)
//	{
//		int aa, bb, cc, dd;
//		cin >> aa >> bb >> cc >> dd;
//		if (aa == cc)//行相同 列划分
//		{
//			y[min(bb, dd)]++;
//		}
//		else
//		{
//			x[min(aa, cc)]++;
//		}
//	}
//	while (k--)
//	{
//		int m1 = 0; int p;
//		for (int i = 1; i <= m; i++)
//		{
//			if (m1 < x[i])
//			{
//				m1 = x[i];
//				p = i;
//			}
//		}
//		x[p] = -1;
//	}
//	while (l--)
//	{
//		int m1 = 0; int p = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (m1 < y[i])
//			{
//				m1 = y[i];
//				p = i;
//			}
//		}
//		y[p] = -1;
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		if (x[i] == -1)
//			printf("%d ", i);
//	}
//	printf("\n");
//	for (int i = 1; i <= n; i++)
//	{
//		if (y[i] == -1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//P1030 [NOIP2001 普及组] 求先序排列
//#include <iostream>
//#include <cstring>
//using namespace std;
//char a[10];
//char b[10];
//void f(int x, int y, int z)//中序起点 后序起点 长度
//{
//	if (z == 0)
//		return;
//	//根
//	cout << b[y + z - 1];
//	int len;
//	for (int i = x; i < x + z; i++)
//	{
//		if (a[i] == b[y + z - 1])
//		{
//			len = i - x;
//			break;
//		}
//	}
//	//先序 左子树
//	f(x, y, len);
//	//先序 右子树
//	f(x + len + 1, y + len, z - 1 - len);
//}
//int main()
//{
//	cin >> a;
//	cin >> b;
//	f(0, 0, strlen(a));
//}
//
//P1002 [NOIP2002 普及组] 过河卒
//#include <iostream>
//using namespace std;
//int xx[9] = { 0,-2,-2,-1,-1,1,1,2,2 };//马可以抵达的行数
//int yy[9] = { 0,-1,1,-2,2,-2,2,-1,1 };
//long long f[30][30];//兵
//bool m[30][30];//马
//int main()
//{
//	int x, y, ma, mb;
//	cin >> x >> y >> ma >> mb;
//	x++, y++, ma++, mb++;//清除边界
//	for (int i = 0; i < 9; i++)//标记马的位置
//	{
//		int dx = ma + xx[i];
//		int dy = mb + yy[i];
//		m[dx][dy] = 1;
//	}
//	f[1][1] = 1;//兵开始
	//for (int i = 1; i <= x; i++)
	//{
	//	for (int j = 1; j <= y; j++)
	//	{
	//		if (m[i][j] == 1 || i==1&&j==1)
	//			continue;
	//		f[i][j] = f[i - 1][j] + f[i][j - 1];
	//	}
	//}
//	cout << f[x][y];
//	return 0;
//}
//
//P1044 [NOIP2003 普及组] 栈
//#include <iostream>
//using namespace std;
//int main()
//{
//	long long a[30] = { 0 };
//	int n = 0;
//	cin >> n;
//	a[0] = 1;
//	a[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			a[i] += a[j - 1] * a[i - j];//卡特兰
//		}
//	}
//	cout << a[n];
//	return 0;
//}

//快速排序
//#include <iostream>
//using namespace std;
//int a[10005];
//int n;
//void quicksort(int l, int r)
//{
//	int x = l; int y = r;
//	int m = a[(x + y) / 2];
//	while (x <= y)
//	{
//		while (a[x] < m)
//			x++;
//		while (a[y] > m)
//			y--;
//		if (x <= y)
//		{
//			swap(a[x], a[y]);
//			x++, y--;
//		}
//	}
//	if (y > l)
//	{
//		quicksort(l, y);
//	}
//	if (x < r)
//	{
//		quicksort(x, r);
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	quicksort(1,n);
//	for (int i = 1; i <= n; i++)
//	{
//		cout << a[i]<<" ";
//	}
//}
//
//

//P1162 填涂颜色
//#include <iostream>
//#include <queue>
//using namespace std;
//int xx[4] = { 0,-1,0,1 };
//int yy[4] = { 1,0,-1,0 };
//int a[40][40];
//int v[40][40];
//int n;
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	queue<int>x; queue<int>y;
//	x.push(0); y.push(0);
//	v[0][0] = 1;
//	while (!x.empty())
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			int fx = x.front() + xx[i];
//			int fy = y.front() + yy[i];
//			if (fx >= 0 && fx <= n + 1 && fy >= 0 && fy <= n + 1 && a[fx][fy] == 0 && !v[fx][fy])
//			{
//				x.push(fx); y.push(fy);
//				v[fx][fy] = 1;
//			}
//		}
//		x.pop(); y.pop();
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (a[i][j] == 0 && v[i][j] == 0)
//				cout << 2 << " ";
//			else
//				cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//P1443 马的遍历
//#include <iostream>
//#include <queue>
//using namespace std;
//int n,m,x,y;
//int a[410][410];
//int xx[8] = { 2,2,1,1,-1,-1,-2,-2 };
//int yy[8] = { 1,-1,2,-2,2,-2,1,-1 };
//struct Node 
//{
//	int dx, dy, step;//行列坐标 步数
//}t;
//int main()
//{
//	cin >> n >> m;
//	cin >> x >> y;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			a[i][j] = -1;
//	}
//	t.dx = x; t.dy = y; t.step = 0;
//	queue<Node> q;
//	q.push(t);
//	a[x][y] = 0;
//	while (!q.empty())
//	{
//		for (int i = 0; i < 8; i++)
//		{
//			int dx = xx[i] + q.front().dx;
//			int dy = yy[i] + q.front().dy;
//			if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy]==-1)
//			{
//				Node p;
//				p.dx = dx;
//				p.dy = dy;
//				p.step = q.front().step + 1;
//				q.push(p);
//				a[dx][dy] = q.front().step +1;
//			}
//		}
//		q.pop();
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
//}
//P1135 奇怪的电梯
//#include <iostream>
//#include <queue>
//using namespace std;
//int n, a, b;
//int k[500];
//int main()
//{
//	cin >> n >> a >> b;
//	for (int i = 1; i <= n; i++)
//		cin >> k[i];
//	int vis[500] = { 0 };//标记走过的楼层
//	queue<int>f; queue<int>s;//楼层和步数
//	f.push(a); s.push(0);
//	vis[a] = 1;
//	while (!f.empty())
//	{
//		if (f.front() == b)
//		{
//			cout << s.front();
//			return 0;
//		}
//		int t = f.front() + k[f.front()];
//		if (t <= b && !vis[t])
//		{
//			f.push(t);
//			s.push(s.front() + 1);
//			vis[t] = 1;
//		}
//		t = f.front() - k[f.front()];
//		if (t >= 1 && !vis[t])
//		{
//			f.push(t);
//			s.push(s.front() + 1);
//			vis[t] = 1;
//		}
//		f.pop(); s.pop();
//	}
//	cout << -1;
//	return 0;
//}
//
//P1141 01迷宫
//#include <iostream>
//#include <queue>
//using namespace std;
//int n, m,o,p;
//int vis[1010][1010];
//bool a[1010][1010];
//int xx[4] = { 0,1,0,-1 };
//int yy[4] = { 1,0,-1,0 };
//int color, cnt=0;
//int ans[1010101];
//void bfs(int h, int l)
//{
//	queue<int>x; queue<int>y;
//	x.push(h); y.push(l);
//	vis[h][l] = color;
//	while (!x.empty())
//	{
//		for (int k = 0; k < 4; k++)
//		{
//			int dx = x.front() + xx[k];
//			int dy = y.front() + yy[k];
//			if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && !vis[dx][dy] && a[dx][dy] != a[x.front()][y.front()])
//			{
//				x.push(dx); y.push(dy);
//				vis[dx][dy] = color;
//			}
//		}
//		x.pop(); y.pop();
//		cnt++;
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			char x; cin >> x;
//			if (x == '1')
//			{
//				a[i][j] = 1;
//			}
//			else
//				a[i][j] = 0;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (!vis[i][j])
//			{
//				color++;
//				bfs(i, j);
//				ans[color] = cnt;
//				cnt = 0;
//			}
//		}
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> o >> p;
//		cout << ans[vis[o][p]] << endl;
//	}
//}

//P1706 全排列问题
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int n;
//bool vis[100];
//int a[100];
//void pr()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%5d", a[i]);
//	}
//	printf("\n");
//}
//void dfs(int x)
//{
//	if (x > n)
//	{
//		pr();
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!vis[i])
//		{
//			a[x] = i;
//			vis[i] = 1;
//			dfs(x + 1);
//			vis[i] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	dfs(1);
//	return 0;
//}
//
//P1219 [USACO1.5] 八皇后 Checker Challenge
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int n, cnt = 0;
//bool lie[20];
//bool zy[40];
//bool yz[40];
//int a[40];
//void pr()
//{
//	if (cnt <= 3)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << endl;
//	}
//}
//void dfs(int x)
//{
//	if (x > n)
//	{
//		cnt++;
//		pr();
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!lie[i] && !zy[x - i + n] && !yz[x + i])
//		{
//			lie[i] = 1; zy[x - i + n] = 1; yz[x + i] = 1;
//			a[x] = i;
//			dfs(x + 1);
//			lie[i] = 0; zy[x - i + n] = 0; yz[x + i] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	dfs(1);
//	cout << cnt;
//	return 0;
//}
//
//P1605 迷宫
//#include <iostream>
//using namespace std;
//int n, m, t,ans=0;
//int sx, sy, fx, fy;
//int x, y;
//int a[1010][1010];
//bool vis[1010][1010];
//int xx[4] = { 1,0,-1,0 };
//int yy[4] = { 0,-1,0,1 };
//void dfs(int h, int l)
//{
//	if (h == fx && l == fy)
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int dx = xx[i] + h;
//		int dy = yy[i] + l;
//		if (dx >= 1 && dy >= 1 && dx <= n && dy <= m && !vis[dx][dy] && !a[dx][dy])
//		{
//			vis[dx][dy] = 1;
//			dfs(dx, dy);
//			vis[dx][dy] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m >> t;
//	cin >> sx >> sy >> fx >> fy;
//	while (t--)
//	{
//		cin >> x >> y;
//		a[x][y] = 1;//标记障碍物
//	}
//	vis[sx][sy] = 1;
//	dfs(sx, sy);
//	cout << ans;
//	return 0;
//}
//
//P1101 单词方阵
//#include <iostream>
//#include <cstring>
//using namespace std;
//char s[] = "yizhong";
//char a[110][110];
//bool vis[110][110];
//int n;
//int xx[8] = { 1,1,1,0,0,-1,-1,-1 };
//int yy[8] = { 1,0,-1,-1,1,-1,0,1 };
//void dfs(int h, int l)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j <= 6; j++)
//		{
//			int dx = h + xx[i] * j;
//			int dy = l + yy[i] * j;
//			if (s[j] != a[dx][dy] || dx<1 || dy<1 || dx>n || dy>n)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag==1)
//		{
//			for (int j = 0; j <= 6; j++)
//			{
//				int dx = h + xx[i] * j;
//				int dy = l + yy[i] * j;
//				vis[dx][dy] = 1;
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (a[i][j] == 'y')
//			{
//				dfs(i, j);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (!vis[i][j])
//			{
//				cout << "*";
//			}
//			else
//				cout << a[i][j];
//		}
//		cout << endl;
//	}
//}
//
//P1019 [NOIP2000 提高组] 单词接龙
//#include <iostream>
//#include <cstring>
//using namespace std;
//string a[22];
//char t;
//int n,ans = 0;
//int vis[22];
//void dfs(string x, int s)
//{
//	ans = max(ans, s);
//	for (int i = 1; i <= n; i++)
//	{
//		int p = 1; int flag = 0;
//		int la = x.length();
//		int lb = a[i].length();
//		while (p < min(la, lb))
//		{
//			if (x.substr(la - p) == a[i].substr(0, p) && vis[i] < 2)
//			{
//				vis[i]++;
//				dfs(a[i], s + lb - p);
//				vis[i]--;
//				break;
//			}
//			p++;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	cin >> t;
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i][0] == t)
//		{
//			vis[i]++;
//			dfs(a[i], a[i].length());
//			vis[i]--;
//		}
//	}
//	cout << ans;
//	return 0;
//}

//P1601 A+B Problem（高精）
//#include <iostream>
//using namespace std;
//int a[1000], la;
//int b[1000], lb;
//int c[1000], lc;
//string x, y;
//int main()
//{
//	cin >> x >> y;
//	la = x.length(); lb = y.length();
//	for (int i = 0; i < la; i++)
//	{
//		a[la-i] = x[i] - '0';
//	}
//	for (int i = 0; i < lb; i++)
//	{
//		b[lb - i] = y[i] - '0';
//	}
//	lc = max(la, lb);
//	for (int i = 1; i <= lc; i++)
//	{
//		c[i] += a[i] + b[i];
//		c[i + 1] = c[i] / 10;
//		c[i] %= 10;
//	}
//	if (c[lc + 1] > 0)
//	{
//		lc++;
//	}
	//for (int i = lc; i >= 1; i--)
	//	cout << c[i];
//}
//
//P2142 高精度减法
//#include <iostream>
//#include <cstring>
//using namespace std;
//int a[100005], la;
//int b[100005], lb;
//int c[100005], lc;
//string x,y;
//int main()
//{
//	cin >> x >> y;
//	la = x.length(); lb = y.length();
//	if (la < lb || la==lb && x<y)
//	{
//		swap(x, y);
//		swap(la, lb);
//		cout << "-";
//	}
//	for (int i = 0; i < la; i++)
//	{
//		a[la - i] = x[i] - '0';
//	}
//	for (int i = 0; i < lb; i++)
//	{
//		b[lb - i] = y[i] - '0';
//	}
//	//借位
//	for (int i = 1; i <= la; i++)
//	{
//		if (a[i] < b[i])
//		{
//			a[i] += 10;
//			a[i + 1]--;
//		}
//		c[i] = a[i] - b[i];
//	}
//	while (c[la] == 0 && la > 1)
//	{
//		la--;
//	}
//	for (int i = la; i >= 1; i--)
//		cout << c[i];
//	return 0;
//}
//
//P1303 A*B Problem
//#include <iostream>
//using namespace std;
//string x, y;
//int a[100005], la;
//int b[100005], lb;
//int c[100005], lc;
//int main()
//{
//	cin >> x >> y;
//	la = x.length(); lb = y.length();
//	for (int i = 0; i < la; i++)
//	{
//		a[la - i] = x[i] - '0';
//	}
//	for (int i = 0; i < lb; i++)
//	{
//		b[lb - i] = y[i] - '0';
//	}
//	for (int i = 1; i <= la; i++)
//	{
//		for (int j = 1; j <= lb; j++)
//		{
//			c[i + j - 1] += a[i] * b[j];
//			c[i + j] += c[i + j - 1] / 10;
//			c[i + j - 1] %= 10;
//		}
//	}
//	lc = la + lb;
//	while (c[lc] == 0 && lc > 1)
//		lc--;
//	for (int i = lc; i >= 1; i--)
//		cout << c[i];
//}
//
//P1255 数楼梯
//#include <iostream>
//#include <cstring>
//using namespace std;
//int a[50001], b[50001], c[50001], lc = 1;
//int main()
//{
//	a[1] = 1; b[1] = 2;
//	int n;
//	cin >> n;
//	if (n == 1)
//	{
//		cout << 1;
//		return 0;
//	}
//  if (n == 2)
//  {
//      cout << 2;
//      return 0;
//  }
//	for (int i = 3; i <= n; i++)
//	{
//		memset(c, 0, sizeof(c));
//		for (int j = 1; j <= lc; j++)
//		{
//			c[j] += a[j] + b[j];
//			c[j + 1] = c[j] / 10;
//			c[j] %= 10;
//		}
//		if (c[lc + 1] > 0)
//			lc++;
//		for (int j = 1; j <= lc; j++)
//		{
//			a[j] = b[j];
//		}
//		for (int j = 1; j <= lc; j++)
//		{
//			b[j] = c[j];
//		}
//	}
//	for (int i = lc; i >= 1; i--)
//	{
//		cout << c[i];
//	}
//}
//
//P1604 B进制星球
//#include <iostream>
//using namespace std;
//string x, y;
//int a[10005], la;
//int b[10005], lb;
//int c[10005], lc;
//int n;
//int main()
//{
//	cin >> n;
//	cin >> x >> y;
//	la = x.length(); lb = y.length();
//	for (int i = 0; i < la; i++)
//	{
//		if (x[i] >= 'A' && x[i] <= 'Z')
//		{
//			a[la - i] = x[i] - 'A' + 10;
//		}
//		else
//			a[la - i] = x[i] - '0';
//	}
//	for (int i = 0; i < lb; i++)
//	{
//		if (y[i] >= 'A' && y[i] <= 'Z')
//		{
//			b[lb - i] = y[i] - 'A' + 10;
//		}
//		else
//			b[lb - i] = y[i] - '0';
//	}
//	lc = max(la, lb);
//	for (int i = 1; i <= lc; i++)
//	{
//		c[i] += a[i] + b[i];
//		c[i + 1] = c[i] / n;
//		c[i] %= n;
//	}
//	if (c[lc + 1] > 0)
//	{
//		lc++;
//	}
//	for (int i = lc; i >= 1; i--)
//	{
//		if (c[i] >= 10)
//		{
//			cout << (char)(c[i] + 'A' - 10);
//		}
//		else
//			cout << c[i];
//	}
//	return 0;
//}

//P1603 斯诺登的密码
//#include <iostream>
//#include <algorithm>
//using namespace std;
//string a[] = {"one","two","three","four","five","six","seven","eight",
//		      "nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen",
//		      "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third" };
//int b[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3 };
//int c[10];
//int n;
//string t;
//int main()
//{
//	for (int i = 1; i <= 6; i++)
//	{
//		cin >> t;
//		for (int j = 0; j < 26; j++)
//		{
//			if (t == a[j])
//			{
//				c[++n] = b[j];
//				c[n] *= c[n];
//				c[n] %= 100;
//			}
//		}
//	}
//	sort(c + 1, c + 1 + n);
//	if (n == 0)
//	{
//		cout << 0;
//		return 0;
//	}
//	cout << c[1];
//	for (int i = 2; i <= n; i++)
//	{
//		if (c[i] < 10)
//			cout << 0;
//		cout << c[i];
//	}
//}
//
//P1071 [NOIP2009 提高组] 潜伏者
//#include <iostream>
//#include <cstring>
//using namespace std;
//string x, y;
//char a[100], b[100];
//int len, la, lb,cnt = 0;
//int main()
//{
//	memset(a, '?', sizeof(a));
//	memset(b, '?', sizeof(b));
//	cin >> x >> y;
//	len = x.length();
//	for (int i = 0; i < len; i++)
//	{
//		if (a[x[i]] == '?' && b[y[i]]=='?') //确保密文原文一一对应且只对应一次
//		{
//			a[x[i]] = y[i];
//			b[y[i]] = x[i];
//			cnt++;
//		}
//		else if (a[x[i]] != y[i])//判断多次出现的但是不匹配
//		{
//			cout << "Failed";
//			return 0;
//		}
//	}
//	if (cnt < 26)
//	{
//		cout << "Failed";
//		return 0;
//	}
//	string t;
//	cin >> t;
//	for (int i = 0; i < t.length(); i++)
//	{
//		cout << a[t[i]];
//	}
//}

//P1192 台阶问题
//#include <iostream>
//using namespace std;
//int a[100005] = { 1 }, n, k;
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i < k; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			//a[i]=a[0]+...+a[i-k]
//			a[i] += a[j];
//			a[i] %= 100003;
//		}
//	}
//	for (int i = k; i <= n; i++)
//	{
//		for (int j = i - k; j < i; j++)
//		{
//			//a[i]=a[i-1]+a[i-2]+...+a[i-k]
//			a[i] += a[j];
//			a[i] %= 100003;
//		}
//	}
//	cout << a[n];
//}
//
//P1025 [NOIP2001 提高组] 数的划分
//#include <iostream>
//using namespace std;
//int n, k,cnt = 0;
//int a[1010];
//void dfs(int x, int y, int z)//数字 总和 个数
//{
//	if (z == k)
//	{
//		if (y == n)
//		{
//			cnt++;
//		}
//		return;
//	}
//	for (int i = x; i + y <= n; i++)
//	{
//		dfs(i, i + y, z + 1);
//	}
//}
//int main()
//{
//	cin >> n >> k;
//	dfs(1, 0, 0);
//	cout << cnt;
//}
//
//P1057 [NOIP2008 普及组] 传球游戏
//#include <iostream>
//using namespace std;
//int n, m;
//int f[40][40] = { 1 };//i表示传了几轮 j表示人 f表示到这个人的方案数
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			f[i][j] = f[i - 1][(j - 1 + n) % n] + f[i - 1][(j + 1) % n];
//		}
//	}
//	cout << f[m][0];
//}
//
//P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles
//#include <iostream>
//#include <cstring>
//using namespace std;
//int r,ans = 0;
//int a[1010][1010],dp[1010][1010];
//int dfs(int h, int l)
//{
//	if (dp[h][l] != -1)
//		return dp[h][l];
//	if (h == r)
//	{
//		dp[h][l] = a[h][l];
//	}
//	else
//	{
//		dp[h][l] = max(dfs(h + 1, l), dfs(h + 1, l + 1)) + a[h][l];
//	}
//	return dp[h][l];
//}
//int main()
//{
//	memset(dp, -1, sizeof(dp));
//	cin >> r;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j <= i; j++)
//			cin >> a[i][j];
//	}
//	cout << dfs(0, 0);//行数 列数
//}

//P1048 [NOIP2005 普及组] 采药
//#include<iostream>
//using namespace std;
//int m, t;
//int c[1010], v[1010];
//int dp[1010];
//int main()
//{
//	cin >> t >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> c[i] >> v[i];
//	}
//	for (int i = 1; i <= m; i++)//选第i个
//	{
//		for (int j = t; j >= c[i]; j--)//选第i个，有j空间 dp[j]表示最多的价值
//		{
//			dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//		}
//	}
//	cout << dp[t];
//	return 0;
//}
//
//P1060 [NOIP2006 普及组] 开心的金明
//#include<iostream>
//using namespace std;
//int n, m, t;
//int v[1010], c[1010];
//int dp[1010];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> v[i] >> c[i];
//		c[i] = v[i] * c[i];
//	}
//	for (int i = 1; i <= m; i++)//选第i个
//	{
//		for (int j = n; j >= v[i]; j--)//选第i个，有j空间 dp[j]表示最多的价值
//		{
//			dp[j] = max(dp[j], dp[j-v[i]] + c[i]);
//		}
//	}
//	cout << dp[n];
//	return 0;
//}
//
//P1049 [NOIP2001 普及组] 装箱问题
//#include<iostream>
//using namespace std;
//int n, m;
//int v[101010];
//int dp[101010];
//int main()
//{
//	cin >> n;//总体积
//	cin >> m;//物品数量
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> v[i];//物体体积
//	}
//	for (int i = 1; i <= m; i++)//选第i个
//	{
//		for (int j = n; j >= v[i]; j--)//选第i个，有j空间 dp[j]表示最多的占用空间
//		{
//			dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
//		}
//	}
//	cout << n - dp[n];
//	return 0;
//}
//
//P1164 小A点菜
//#include<iostream>
//using namespace std;
//int n, m, cnt = 0;
//int v[101010];
//int dp[101010] = { 1 };
//int main()
//{
//	cin >> n >> m;//菜的种类还有钱数
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v[i];
//	}
//	for (int i = 1; i <= n; i++)//选第i个
//	{
//		for (int j = m; j >= v[i]; j--)//对于第i个，有j钱  dp[j]表示花完的方案
//		{
//			dp[j] = dp[j] + dp[j - v[i]];
//		}
//	}
//	cout << dp[m];
//	return 0;
//}
//
//P1734 最大约数和
//#include <iostream>
//using namespace std;
//int n, m;
//int dp[1010], c[1010], v[1010];
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				v[i] += j;//求1-n对应的价值 即约数之和
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)//对于第i个数字
//	{
//		c[i] = i;//给予c[i]体积
//		for (int j = n; j >= c[i]; j--)//选第i个 不选第i个 有j空间，dp[j]表示最大价值
//		{
//			dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//		}
//	}
//	cout << dp[n];
//}
//
//P1510 精卫填海
//#include <iostream>
//using namespace std;
//int t, n, m;
//int dp[1010], c[1010], v[1010];
//int main()
//{
//	cin >> t >> n >> m;//需要的体积 石块数量 剩余体力
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v[i] >> c[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = m; j >= c[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//		}
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		if (dp[i] >= t)
//		{
//			cout << m - i;
//			return 0;
//		}
//	}
//	cout << "Impossible";
//	return 0;
//}
//
//P1466 [USACO2.2] 集合 Subset Sums
//#include <iostream>
//using namespace std;
//int n, m;
//long long dp[1010] = { 1 }, c[1010], v[1010];
//int main()
//{
//	cin >> n;
//	m = n * (n + 1) / 2;
//	if (m % 2 == 1)
//	{
//		cout << 0;
//		return 0;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = m/2; j >= i; j--)
//		{
//			dp[j] = dp[j] + dp[j - i];
//		}
//	}
//	cout << dp[m/2]/2;
//}
//
//P1616 疯狂的采药
//#include <iostream>
//using namespace std;
//int n, m;
//int dp[101010], c[101010], v[101010];
//int main()
//{
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> c[i] >> v[i];
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = c[i]; j <= m; j++)
//		{
//			dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//		}
//	}
//	cout << dp[m];
//}
//
//P1679 神奇的四次方数
//#include <iostream>
//#include <cstring>
//using namespace std;
//int n, m;
//int dp[101010], c[101010], v[101010];
//int main()
//{
//	memset(dp, 63, sizeof(dp));
//	dp[0] = 0;//0对应0
//	cin >> m;
//	for (int i = 1; i*i*i*i <= m; i++)
//	{
//		c[i] = i * i * i * i;
//		n = i;//数量
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = c[i]; j <= m; j++)
//		{
//			dp[j] = min(dp[j], dp[j - c[i]] + 1);
//		}
//	}
//	cout << dp[m];
//}
//
//P1757 通天之分组背包
//#include <iostream>
//#include <cstring>
//#include <stdio.h>
//using namespace std;
//int n, m;
//struct bag
//{
//	int tot;
//	long long w[1010], v[1010];
//}a[1010];
//long long dp[1010];
//int main()
//{
//	cin >> m >> n;
//	int t = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		t = max(t, z);
//		a[z].tot++;//每一组的成员数量
//		a[z].w[a[z].tot] = x;
//		a[z].v[a[z].tot] = y;
//	}
//	for (int i = 1; i <= t; i++)
//	{
//		for (int j = m; j >= 0; j--)
//		{
//			for (int k = 1; k <= a[i].tot; k++)
//			{
//				if (j - a[i].w[k] >= 0)
//					dp[j] = max(dp[j], dp[j - a[i].w[k]] + a[i].v[k]);
//			}
//		}
//	}
//	cout << dp[m];
//}

//P2196 [NOIP1996 提高组] 挖地雷
//#include <iostream>
//using namespace std;
//int p[1010], m[1010][1010];
//int n, ans, ansi;
//int a[1010], dp[1010];
//void dg(int x)
//{
//	if (x == 0)
//		return;
//	dg(p[x]);
//	cout << x << " ";
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		dp[i] = a[i];
//	}
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = i+1; j <= n; j++)
//		{
//			cin >> m[i][j];//表示从i可以连到j
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (m[j][i])//j到i连通
//			{
//				if (dp[i] < (dp[j] + a[i]))
//				{
//					dp[i] = dp[j] + a[i];
//					p[i] = j;//到i的最优方法是j
//				}
//			}
//		}
//		if (ans < dp[i])
//		{
//			ans = dp[i];
//			ansi = i;//记录地窖
//		}
//	}
//	dg(ansi);
//	cout << endl << ans;
//}
//
//P1802 5 倍经验日
//#include <iostream>
//using namespace std;
//int n, x;
//long long l[1010], w[1010], c[1010], dp[1010];
//int main()
//{
//	cin >> n >> x;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> l[i] >> w[i] >> c[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = x; j >= 0; j--)
//		{
//			if (j >= c[i])
//				dp[j] = max(dp[j] + l[i], dp[j - c[i]] + w[i]);
//			else
//				dp[j] = dp[j] + l[i];
//		}
//	}
//	cout << dp[x] * 5;
//}
//
//P4017 最大食物链计数
//#include <iostream>
//using namespace std;
//const int Mn  = 5005;
//int n, m, ans;
//int a[Mn], b[Mn], c[Mn][Mn],r[Mn];
//int mod = 80112002;
//int dfs(int x)
//{
//	if (r[x])
//		return r[x];
//	if (!b[x])
//	{
//		return 1;
//	}
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (c[i][x])
//		{
//			sum = (sum + dfs(i)) % mod;
//		}
//	}
//	return r[x] = sum;
//}
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int x, y;
//		cin >> x >> y;
//		c[x][y] = 1;
//		a[x]++;
//		b[y]++;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!a[i])
//		{
//			ans = (ans + dfs(i)) % mod;
//		}
//	}
//	cout << ans;
//}

//P1118 [USACO06FEB] Backward Digit Sums G/S
//#include <iostream>
//using namespace std;
//int n, sum;
//int y[20][20], vis[20], a[20];
//int flag = 0;
//void dfs(int x, int s)
//{
//	if (flag == 1)
//		return;
//	if (x > n)
//	{
//		if (s == sum)
//		{
//			for (int i = 1; i <= n; i++)
//				cout << a[i] << " ";
//			flag = 1;
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!vis[i])
//		{
//			a[x] = i;
//			vis[i] = 1;
//			if(s + y[n][x] * i <= sum)
//				dfs(x + 1, s + y[n][x] * i);
//			vis[i] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> sum;
//	y[1][1] = 1;
//	for (int i = 2; i <= 13; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			y[i][j] = y[i - 1][j - 1] + y[i - 1][j];
//		}
//	}
//	dfs(1,0);//第几号数字 和
//	return 0;
//}
//
//P1434 [SHOI2002] 滑雪
//#include <iostream>
//using namespace std;
//int c, r;
//int a[110][110],dp[110][110];
//int xx[4] = { 0,-1,0,1 };
//int yy[4] = { 1,0,-1,0 };
//int ans = 0;
//int dfs(int x, int y)
//{
//	if (dp[x][y] > 0)
//	{
//		return dp[x][y];
//	}
//	int maxn = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int dx = xx[i] + x;
//		int dy = yy[i] + y;
//		if (dx >= 1 && dy >= 1 && dx <= r && dy <= c && a[dx][dy] < a[x][y])
//		{
//			maxn = max(maxn, dfs(dx, dy) + 1);
//		}
//	}
//	return dp[x][y] = maxn;
//}
//int main()
//{
//	cin >> r >> c;
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= c; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
	//for (int i = 1; i <= r; i++)
	//{
	//	for (int j = 1; j <= c; j++)
	//	{
	//		ans = max(ans,dfs(i, j));
	//	}
	//}
//	cout << ans;
//}
//
//P1784 数独 -超时一个点
//#include <iostream>
//using namespace std;
//int m[10][10];
//int vx[10][10], vy[10][10], vc[10][10];
//void dfs(int x, int y)
//{
//	if (x == 9)
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				cout << m[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return;
//	}
//	if (y == 9)//列搜完了，转到下一行
//	{
//		dfs(x + 1, 0);
//		return;
//	}
//	if (m[x][y])
//		dfs(x, y + 1);
//	else
//	{
//		for(int i=1;i<=9;i++)
//		{
//			if (!vx[x][i] && !vy[y][i] && !vc[x / 3 * 3 + y / 3][i])
//			{
//				vx[x][i] = 1;
//				vy[y][i] = 1;
//				vc[x / 3 * 3 + y / 3][i] = 1;
//				m[x][y] = i;
//				dfs(x, y + 1);
//				m[x][y] = 0;
//				vx[x][i] = 0;
//				vy[y][i] = 0;
//				vc[x / 3 * 3 + y / 3][i] = 0;
//			}
//		}
//	}
//}
//int main()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			cin >> m[i][j];
//			vx[i][m[i][j]] = 1;//第i行的某个数字已经用过
//			vy[j][m[i][j]] = 1;//第j列的某个数字已经用过
//			vc[i / 3 * 3 + j / 3][m[i][j]] = 1;//第几个九宫格的某个数字用过
//		}
//	}
//	dfs(0, 0);
//}

//P1352 没有上司的舞会
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> a[101010];
//int b[101010];
//int n;
//bool flag[101010];
//int dp[1010][1010];
//int dfs(int pos, bool m)
//{
//	if (dp[pos][m])
//		return dp[pos][m];
//	if (!a[pos].size())//无子节点
//	{
//		if (m)
//			return b[pos];
//		else
//			return 0;
//	}
//	int res = 0;
//	if (m)
//	{
//		for (int i = 0; i < a[pos].size(); i++)
//		{
//			int next = a[pos][i];
//			res += dfs(next, 0);
//		}
//	}
//	else
//	{
//		for (int i = 0; i < a[pos].size(); i++)
//		{
//			int next = a[pos][i];
//			res += max(dfs(next, 1), dfs(next, 0));
//		}
//	}
//	
//	return dp[pos][m] = m ? res + b[pos] : res;
//	
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> b[i];//价值
//	for (int i = 1; i <= n - 1; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		a[y].push_back(x);//x是y的儿子
//		flag[x] = true;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!flag[i])
//		{
//			cout << max(dfs(i, 1), dfs(i, 0));
//			return 0;
//		}
//	}
//}

//P1223 排队接水
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a[1010010];
//long long n,sum;
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		a[i] = a[i] * 1001 + i;
//	}
//	sort(a + 1, a + 1 + n);
//	for (int i = 1; i <= n; i++)
//	{
//		cout << a[i] % 1001 << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += a[i] / 1001 * (n-i);//第i个人 需要n-i个人等待
//	}
//	printf("%.2lf", 1.0 * sum / n);
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <assert.h>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//class person
//{
//public:
//	person(int num, int t)
//	{
//		this->mnum = num; this->mt = t;
//	}
//	int mnum; int mt;
//};
//bool cmp(person& p1, person& p2)
//{
//	return p1.mt < p2.mt;
//}
//int main()
//{
//	int n = 0; cin >> n;
//	vector<person>v;
//	int num, t;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t; num = i + 1;
//		person p(num, t);
//		v.push_back(p);
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].mnum << " ";
//	}
//	cout << endl;
//	double time = 0;
//	for (int j = n - 1; j >= 1; j--)
//	{
//		int i = n - j;//当前最少时间的人序号和要等待的人数之和=n
//		time += v[i - 1].mt * j;
//	}
//	printf("%.2lf", time / n);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int func(int a, int b)
//{
//	if (!a)
//		return b;
//	return func((a & b) << 1, a ^ b);
//}
//int main()
//{
//	int a = 4, b = 9, c = -7;
//	printf("%d", func(a, func(b, c)));
//}
//a   00000000 00000000 00000000 00000100
//b   00000000 00000000 00000000 00000100
//c   11111111 11111111 11111111 11111111
//b&c 00000000 00000000 00000000 00001001
// 
//A   00000000 00000000 00000000 00010010
//B   11111111 11111111 11111111 11110110
//A&B 00000000 00000000 00000000 00010010
// 
//Aa  00000000 00000000 00000000 00100100
//Bb  11111111 11111111 11111111 11100100
//&   00000000 00000000 00000000 00100100
// 
//Aaa 00000000 00000000 00000000 01001000
//Baa 11111111 11111111 11111111 11000000
//&   00000000 00000000 00000000 01000000
// 
//AA  00000000 00000000 00000000 10000000
//BB  11111111 11111111 11111111 10001000
//&   00000000 00000000 00000000 10000000
//
//AAA 00000000 00000000 00000001 00000000
//BBB 11111111 11111111 11111111 00001000



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;

int n;
struct Edge
{
    int id, w;
};
vector<Edge> h[N];
int dist[N];

void dfs(int u, int father, int distance)
{
    dist[u] = distance;
    for (vector<Edge>::iterator it = h[u].begin(); it != h[u].end(); it++)
    {
        Edge node = *it;
        if (node.id != father)
            dfs(node.id, u, distance + node.w);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({ b, c });
        h[b].push_back({ a, c });
    }

    dfs(1, -1, 0);

    int u = 1;
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[u])
            u = i;

    dfs(u, -1, 0);

    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[u])
            u = i;

    int s = dist[u];

    printf("%lld\n", s * 10 + s * (s + 1ll) / 2);

    return 0;
}