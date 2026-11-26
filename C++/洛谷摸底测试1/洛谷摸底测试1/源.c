#include <stdio.h>
#include <string.h>
#include <math.h>
//分支
//买铅笔
//#include <stdio.h>
//int main()
//{
//	int n = 0; scanf("%d\n", &n);
//	int a = 0; int b = 0; int money = 0;
//	int min = 0;
//	for (int i = 1; i <= 3; i++)
//	{
//		scanf("%d %d\n", &a, &b);
//		//57
//		//2  2
//		//50 30
//		//1000 27
//		if (n % a == 0)
//		{
//			money = (n / a) * b;
//		}
//		else
//		{
//			if
//		}
//		min = money;
//		if (money < min)
//		{
//			min = money;
//		}
//	}
//	printf("%d", min);
//	return 0;
//}
//
//int main()
//{
//	int n, a1, a2, b1, b2, c1, c2, a, b, c, z;
//	scanf("%d", &n);
//	scanf("%d %d", &a1, &a2);
//	scanf("%d %d", &b1, &b2);
//	scanf("%d %d", &c1, &c2);
//	a = n / a1; a1 = n % a1 == 0 ? a : a + 1; a = a1 * a2;
//	b = n / b1; b1 = n % b1 == 0 ? b : b + 1; b = b1 * b2;
//	c = n / c1; c1 = n % c1 == 0 ? c : c + 1; c = c1 * c2;
//	if (a < b && a < c)
//		z = a;
//	if (b < a && b < c)
//		z = b;
//	if (c < b && c < a)
//		z = c;
//	printf("%d\n", z);
//	return 0;
//}

//循环
//直角三角形
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int x = 1;
//	for (int i = n; i >= 0; i--)
//	{
//		for (int j = i - 1; j >= 0; j--)
//		{
//			//4 3 2 1 0
//			//0102030405
//			//3 2 1 0
//			//06070809
//			if (x < 10)
//			{
//				printf("0%d", x);
//				x++;
//			}
//			else
//			{
//				printf("%d", x);
//				x++;
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//金币
//int main() 
//{
//    int k, b = 0, i = 1;
//    scanf("%d", &k);
//    while (k > i) 
//    {
//        b += i * i;
//        k -= i;
//        i++;
//    }
//    b += i * k;
//    printf("%d", b);
//    return 0;
//}
//回文质数
//int huiwen(int n)
//{
//	int p = n; int weishu = 0;
//	while (p)
//	{
//		weishu++;
//		p /= 10;
//	}
//	int arr[100] = { 0 };
//	int i = 0;
//	for (i = 0; i < weishu; i++)
//	{
//		arr[i] = (n % 10);
//		n /= 10;
//	}
//	int left = 0; int right = weishu - 1; int flag = 0;;
//	while (left < right)
//	{
//		if (arr[left] == arr[right])
//		{
//			flag++;
//		}
//		left++; right--;
//	}
//	if (flag == weishu / 2)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a = 0; int b = 0; 
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		int t = a; a = b; b = t;
//	} //保证a<b
//	for (int i = a; i <= b; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (i == j && huiwen(i)==1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//
//}
//数字逆序
//int weishu(int n)
//{
//	int he = 0;
//	while (n)
//	{
//		he++;
//		n /= 10;
//	}
//	return he;
//}
//int main()
//{ 
//	int n = 0; scanf("%d", &n); //1234  -3 -8
//	int k = weishu(n);//计算位数
//	int arr[10000] = { 0 };
//	int sum = 0;
//	//把每一位存到arr
//	for (int i = 0; i < k && n!=0; i++)
//	{
//		arr[i] = n % 10; 
//		n /= 10; //4 3 2 1  -3 -8
//	}
//	for (int i = 0; i < k; i++)
//	{
//		sum += arr[i] * pow(10, k - i - 1); //4321
//	}
//	printf("%d", sum);
//	return 0;
//}
//三角形+正方形
//int main()
//{
//	int n = 0;; scanf("%d", &n);// 4
//	int i = 0;//行
//	int j = 0;//列
//	int x = 1;
//	for (i = 1; i <= n && x<=n*n; i++)
//	{
//		for (j = 1; j <= n && x<=n*n; j++)
//		{
//			if (x < 10)
//			{
//				printf("0%d", x);
//				x++;
//			}
//			else
//			{
//				printf("%d", x);
//				x++;
//			}
//		}
//		printf("\n");
//	}
//	printf("\n");
//	x = 1;
//	for (i = 1; i <= n; i++)
//	{
//		for (int k = n - i; k > 0; k--) 
//		{
//			printf("  ");
//		}
//		for (j = 1; j < i + 1; j++)
//		{
//			if (x < 10)
//			{
//				printf("0%d", x);
//				x++;
//			}
//			else
//			{
//				printf("%d", x);
//				x++;
//			}
//		}
//		printf("\n");
//	}
//		
//	return 0;
//}
//斐波那契数列
//int main()
//{
//    double f[50];
//    int n, i;
//    f[0] = 0;
//    f[1] = 1;
//    f[2] = 1;   
//    scanf("%d", &n);
//    for (i = 3; i <= n; i++)
//        f[i] = f[i - 1] + f[i - 2];  
//    printf("%0.2lf", f[n]); 
//    return 0;
//}
//最长连号
//#define N 10000 
//int judge(int* a, int length)
//{
//	int i, j, cnt, max;
//	cnt = 1; max = 0;
//	for (i = 0; i < length; i++)
//	{
//		j = a[i + 1] - a[i]; //1 2 2 3 4 5 6 6 8 9
//		if (j == 1)
//		{
//			cnt++;
//		}
//		else
//		{
//			if (max < cnt)
//				max = cnt;
//			cnt = 1;
//		}
//
//	}
//	return max;
//}
//
//int main()
//{
//	int n, i, a[N];
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	printf("%d", judge(a, n));
//	return 0;
//}
//int main()
//{
//	int n = 0;//表示输入每个月的预算
//	int i = 0;//月份
//	int fa = 0;//每个月发的钱
//	int cun = 0;//每个月存的钱
//	for (i = 1; i <= 12; i++)
//	{
//		scanf("%d\n", &n);//290 50
//		fa = fa + 300;
//		fa = fa - n;
//		if (fa < 0)
//		{
//			printf("%d", -i);
//			return 0;
//		}
//		else
//		{
//			while (fa >= 100)
//			{
//				fa -= 100;
//				cun += 100;
//			}
//		}
//		if (i == 12)
//			printf("%.0f", 1.2 * cun + fa);
//	}
//	return 0;
//}

//数组
//学生比分
//int main() 
//{
//	int n, flag = 0;
//	scanf("%d", &n);
//	int a[1000][3];
//	for (int i = 0; i < n; i++) 
//	{ 
//		scanf("%d", &a[i][0]);
//		scanf("%d", &a[i][1]);
//		scanf("%d", &a[i][2]);
//	}
//	for (int i = 0; i < n; i++) 
//	{  
//		for (int j = i + 1; j < n; j++) 
//		{
//			int x = fabs(a[i][0] - a[j][0]);  //语文 
//			int y = fabs(a[i][1] - a[j][1]);  //数学 
//			int z = fabs(a[i][2] - a[j][2]);  //英语 
//			int s = fabs((a[i][0] + a[i][1] + a[i][2]) - (a[j][0] + a[j][1] + a[j][2]));   //总分差
//			if (x <= 5 && y <= 5 && z <= 5 && s <= 10) 
//			{
//				flag ++;
//			}
//		}
//	}
//	printf("%d", flag);
//	return 0;
//}
//工艺品制作
//#define N 25
//int main()
//{
//	int w, x, h, x1, x2, y1, y2, z1, z2, q, flag[N][N][N], i, j, k, cnt;
//	memset(flag, 0, sizeof(flag));
//	cnt = 0;
//	scanf("%d%d%d", &w, &x, &h);
//	scanf("%d", &q);
//	while (q--)
//	{
//		scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
//		for (i = x1 - 1; i < x2; i++)
//			for (j = y1 - 1; j < y2; j++)
//				for (k = z1 - 1; k < z2; k++)
//				{
//					if (flag[i][j][k] == 0)
//						flag[i][j][k] = 1;
//				}
//
//	}
//	for (i = 0; i < w; i++)
//		for (j = 0; j < x; j++)
//			for (k = 0; k < h; k++)
//			{
//				if (flag[i][j][k] == 0)
//					cnt++;
//			}
//	printf("%d", cnt);
//	return 0;
//}
//蛇形方阵
//int main( )
//{
//	int n;
//	int arr[10][10] = { 0 };scanf("%d", &n); // 4
//	int m, k, i, j;
//	int cnt = 1;
//	for (m = 0, k = n - 1; m <= k; m++, k--)		
//	{
//		for (i = m, j = m; j <= k; j++)	
//		{
//			arr[i][j] = cnt++;
//		}
//		for (i = m + 1, j = k; i <= k; i++)	
//		{
//			arr[i][j] = cnt++;
//		}
//		for (i = k, j = k - 1; j >= m; j--)		
//		{
//			arr[i][j] = cnt++;
//		}
//		for (i = k - 1, j = m; i >= m + 1; i--)		
//		{
//			arr[i][j] = cnt++;
//		}
//	}
//	for (i = 0; i < n; i++)		
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//杨辉三角
//int main()
//{
//	int arr[30][30] = { 0 };
//	int i = 0; int j = 0; int k = 0;
//	int n = 0; scanf("%d", &n);//6
//	if (n <= 20)
//	{
//		for (i = 0; i < n; i++)
//		{
//           arr[i][0] = arr[i][i] = 1; //第一个和最后一个全为1
//		}
//		for (i = 2; i < n; i++) //从下标为2开始 第三行
//		{
//			for (j = 1; j < n - 1; j++)// 5
//			{   
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j <= i; j++)
//			{
//				printf("%d ", arr[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	else
//		;
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n >= 1)
//	{
//		int* a = (int*)malloc(n * sizeof(int));
//		assert(a != NULL);
//		char c[10][5][4] = {
//			"XXX",
//			"X.X",
//			"X.X",
//			"X.X",
//			"XXX",
//
//			"..X",
//			"..X",
//			"..X",
//			"..X",
//			"..X",
//
//			"XXX",
//			"..X",
//			"XXX",
//			"X..",
//			"XXX",
//
//			"XXX",
//			"..X",
//			"XXX",
//			"..X",
//			"XXX",
//
//			"X.X",
//			"X.X",
//			"XXX",
//			"..X",
//			"..X",
//
//			"XXX",
//			"X..",
//			"XXX",
//			"..X",
//			"XXX",
//
//			"XXX",
//			"X..",
//			"XXX",
//			"X.X",
//			"XXX",
//
//			"XXX",
//			"..X",
//			"..X",
//			"..X",
//			"..X",
//
//			"XXX",
//			"X.X",
//			"XXX",
//			"X.X",
//			"XXX",
//
//			"XXX",
//			"X.X",
//			"XXX",
//			"..X",
//			"XXX",
//		};
//		for (int i = 0; i < n; i++)
//			scanf("%1d", a + i);
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				printf("%s", c[a[j]][i]);
//				if (j == n - 1)
//					printf("\n");
//				else
//					printf(".");
//			}
//		}
//		free(a);
//	}
//	else
//		;
//	return 0;
//}
//数字反转
//unsigned int reverse(unsigned int sum)
//{
//	int he = 0; int ret = sum;
//	while (ret)
//	{
//		he++;
//		ret /= 10;
//	}
//	if (sum <= 9)
//		return sum;
//	else
//		return reverse(sum / 10) + (sum % 10) * pow(10, he - 1);
//}
//int main()
//{
//	char arr[2000] = { 0 };
//	scanf("%s", arr); //5087462
//	int p1=0, p2=0, p3=0, p4=0;
//	int i = 0;
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == '.')
//			p2 = 1;
//		else if (arr[i] == '%')
//			p4 = 1;
//		else if (arr[i] == '/')
//			p3 = 1;
//		else
//			p1 = 1;
//	}
//	//整数
//	int sum = 0; int k = len;
//	if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 0)
//	{
//		for (i = 0; i < len; i++)
//		{
//			sum += (arr[i] - 48) * pow(10, k - 1);
//			k--;
//		}
//		printf("%d", reverse(sum));
//	}
//	//小数
//	int mid = 0;int sum1 = 0;int sum2 = 0;
//	
//	if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] == '.')
//				mid = i;
//		}
//		int k2 = mid;
//		for (int i = 0; i < mid; i++)
//		{
//			sum1 += (arr[i] - 48) * pow(10, k2 - 1);
//			k2--;
//		}
//		int ret1 = reverse(sum1);
//		int k20 = mid + 1;
//		for (int i = mid + 1; i < len; i++)
//		{
//			sum2 += (arr[i] - 48) * pow(10, k20 - 1);
//			k20--;
//		}
//		int ret2 = reverse(sum2);
//		printf("%d.%d", ret1, ret2);
//	}
//	//分数
//	int mid2 = 0;int sum11 = 0; int sum22 = 0;
//	if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] == '/')
//				mid2 = i;
//		}
//		int k22 = mid2;
//		for (int i = 0; i < mid2; i++)
//		{
//			sum11 += (arr[i] - 48) * pow(10, k22 - 1);
//			k22--;
//		}
//		int ret1 = reverse(sum11);
//		int k200 = mid2 + 1;
//		for (int i = mid2 + 1; i < len; i++)
//		{
//			sum22 += (arr[i] - 48) * pow(10, k200 - 1);
//			k200--;
//		}
//		int ret2 = reverse(sum22);
//		printf("%d/%d", ret1, ret2);
//	}
//	//百分数
//	//百分数并且数字部分没有小数点
//	int flag = 0; int sum111 = 0;
//	if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1)
//	{
//		for (i = 0; i < len; i++)
//		{
//			if (arr[i] == '%')
//				flag = i;
//		}
//		int l1 = flag;
//		for (i = 0; i < flag; i++)
//		{
//			sum111 += (arr[i] - 48) * pow(10, l1 - 1);
//			l1--;
//		}
//		int ret = reverse(sum111);
//		char c = '%';
//		printf("%d%c", ret,c);
//	}
//	//百分数且数字部分有小数点
//	int flag2 = 0; int flag3 = 0;  int sum1111 = 0; int sum2222 = 0;
//	if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1)
//	{
//		for (i = 0; i < len; i++)
//		{
//			if (arr[i] == '%')
//				flag2 = i; //找到%的位置
//		}
//		int l1 = flag2;
//		for (i = 0; i < len; i++)
//		{
//			if (arr[i] == '.')
//				flag3 = i;//找到.的位置
//		}
//		int l2 = flag3;
//		for (i = 0; i < flag3; i++)
//		{
//			sum1111 += (arr[i] - 48) * pow(10, l2 - 1);
//			l2--;
//		} //87.15%
//		int ret1 = reverse(sum1111);
//		int l3 = flag2 - flag3;
//		for (i = flag3 + 1; i < flag2; i++)
//		{
//			sum2222 += (arr[i] - 48) * pow(10, l3 - 1);
//			l3--;
//		}
//		int ret2 = reverse(sum2222);
//		char c = '%';
//		printf("%d.%d%c", ret1,ret2,c);
//	}
//	return 0;
//}

//字符串
//凯撒密码
//int main()
//{
//	int n = 0; scanf("%d", &n);//1
//	char arr[50] = { 0 };
//	getchar();
//	gets(arr); //qwe
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", (arr[i] - 'a' + n) % 26 + 'a');
//	}
//	return 0;
//}
//文件处理软件
//int main()
//{
//	int n = 0; char str[50] = { 0 };
//	scanf("%d\n", &n);//4
//	scanf("%s",str);//Ilove
//	int x = 0; int m = 0;
//	int k1, k2;
//	char tmp[50] = { 0 };
//	char arr[50] = { 0 };
//	char brr[50] = { 0 };
//	char crr[50] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &x);
//		if(x==1)
//		{
//			scanf("%s",arr);//Luogu
//			strcat(str, arr);
//			printf("%s\n", str); //IloveLuogu
//		}                        //0123456789
//		else if (x == 2)
//		{
//			scanf("%d %d", &k1, &k2); //5 5
//			str[k1 + k2] = '\0'; //改成\0
//			strcpy(tmp, &str[k1]); 
//			strcpy(str, tmp);
//			printf("%s\n", str); //Luogu
//		}
//		else if (x == 3)
//		{
//			scanf("%d\n", &m); //3
//			scanf("%s",brr); //guGugu
//			strcat(brr, &str[m]); //brr :guGugugu
//			str[m] = '\0';
//			strcat(str, brr);
//			printf("%s\n", str); //LuoguGGugugu
//		}
//		else if (x == 4)
//		{
//			scanf("%s", crr); //gug
//			char drr[50] = { 0 };
//			if (strstr(str, crr) == NULL)
//				printf("%d\n", -1);
//			else
//			{
//				for (int p = 0; p < strlen(str); p++)
//				{
//					if (str[p] == crr[0])
//					{
//						for (int u = 0; u < strlen(crr); u++)
//						{
//							drr[u] = str[p + u];
//						}
//						if (strcmp(drr, crr) == 0)
//						{
//							printf("%d\n", p);
//							break;
//						}
//					}
//				}
//			}
//			
//		}
//	}
//	return 0;
//}
//VK
//int main()
//{
//	char arr[5000] = { 0 };
//	int n = 0; scanf("%d\n", &n); //20
//	
//	gets(arr);  //VKKKKKKKKKVVVVVVVVVK
//	int cnt = 0; int flag = 0;
//	int len = strlen(arr);
//	if (n == 1)
//		printf("%d", 0);
//	else
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] == 'V' && arr[i + 1] == 'K')
//				cnt++;
//			//改一个
//			if (arr[i] = 'V' && arr[i + 1] != 'K' && flag == 0 && arr[i+1]!='\0')
//			{
//				arr[i + 1] = 'k';
//				flag++; cnt++;
//			}
//		}
//		printf("%d", cnt);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[5000] = { 0 };
//	int n = 0; scanf("%d", &n); //20
//	int j;
//	int max = 0;
//	scanf("%s", arr);  //VKKKKKKKKKVVVVVVVVVK
//	int cnt = 0; int flag = 0;
//	int len = strlen(arr);
//	if (n == 1)
//		printf("%d", 0);
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (arr[i] == 'V')
//				arr[i] = 'K';
//			else
//				arr[i] = 'V'; //改一个
//			for (j = 0; j < n - 1; j++)  //遍历改变后的字符串统计VK
//				if (arr[j] == 'V' && arr[j + 1] == 'K')
//					cnt++;
//			if (arr[i] == 'V')
//				arr[i] = 'K';
//			else
//				arr[i] = 'V';//改回来
//			if (max < cnt)
//				max = cnt; //找最大次数
//			cnt = 0;//清零
//
//
//
//		}
//		for (int i = 0; i < n - 1; i++) //可能不改变任何一个字符就是最大次数
//		{
//			if (arr[i] == 'V' && arr[i + 1] == 'K')
//				cnt++;
//		}
//		if (max < cnt)
//			max = cnt;
//		printf("%d", max);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//int main()
//{
//	int p1, p2, p3;
//	scanf("%d %d %d\n", &p1, &p2, &p3); // 1 2 1
//	char arr[1000] = { 0 };
//	gets(arr);//abcs-w1234-9s-4zz
//	int len = strlen(arr);
//	int i = 0;
//	printf("%c", arr[0]);
//	for (i = 1; i < len; i++)
//	{
//		if (arr[i] != '-')
//			printf("%c", arr[i]);
//		else
//		{
//			//arr[i]是-的情况下，不进行任何操作的情况
//			if (arr[i + 1] == '-' || arr[i - 1] == '-')
//			{
//				printf("-"); continue;
//			}
//			if ((arr[i + 1] >= '0' && arr[i + 1] <= '9') && (arr[i - 1] >= 65))
//			{
//				printf("-"); continue;
//			}
//			if ((arr[i - 1] >= '0' && arr[i - 1] <= '9') && (arr[i + 1] >= 65))
//			{
//				printf("-"); continue;
//			}
//			if (arr[i - 1] >= arr[i + 1]) //相同大小 或者后者比前者小 都原样输出
//			{
//				printf("%c",arr[i]); continue;
//			}
//			//后继的情况
//			else if (arr[i + 1] - arr[i - 1] == 1)
//				continue;
//
//
//			int k = p2 * (arr[i + 1] - arr[i - 1] - 1);  //d-h  deeefffgggh 增加了9个字母
//			if (p1 == 3)
//			{
//				for (int j = 1; j <= k; j++)
//				{
//					printf("*"); continue;
//				}
//			}
//			char a1 = arr[i - 1] + 1; char a2 = arr[i + 1] - 1; //e    g
//			if (p1 == 1)
//			{
//				//填充小写字母
//				if (a1 < 97 && a1 >= '9')
//				{
//					a1 += 32; a2 += 32;
//				}
//			}
//			else if (p1 == 2)
//			{
//				//填充大写字母
//				if (a1 >= 97 && a1 >= '9')
//				{
//					a1 -= 32; a2 -= 32;
//				}
//			}
//			if (p3 == 1)
//			{
//				for (a1; a1 <= a2; a1++)
//				{
//					for (int p = 1; p <= p2; p++)
//					{
//						printf("%c", a1);
//					}
//				}
//				continue;
//			}
//			else if (p3 == 2)
//			{
//				for (a2; a2 >= a1; a2--)
//				{
//					for (int p = 1; p <= p2; p++)
//					{
//						printf("%c", a2);
//					}
//				}
//				continue;
//			}
//		}
//	}
//	return 0;
//}
//
//
//垂直柱状图
//#include <iostream>
//using namespace std;
//int a[100];
//char s[100];
//int main()
//{   
//	int maxn = 0;
//	    for (int i = 1; i <= 4; i++)
//		     {
//		        gets(s);
//		        int len = strlen(s);
//		       for (int j = 0; j < len; j++)
//			         {
//			           if (s[j] >= 'A' && s[j] <= 'Z')
//				                a[s[j] - 'A' + 1]++;
//			         }
//		     }
//	    for (int i = 1; i <= 26; i++)
//		         maxn = max(maxn, a[i]);
//	     for (int t = maxn; t > 0; t--)
//		     {
//		         for (int i = 1; i <= 26; i++)
//			         {
//			             if (a[i] >= t)
//				                 cout << "*" << " ";
//			             else printf("  ");
//			         }
//		         cout << endl;
//		     }
//	     for (int i = (int)'A'; i <= (int)'Z'; i++)
//		         cout << (char)i << " ";
//	     return 0;
// }

////函数结构体
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//struct STU
//{
//	int id;
//	int score1;
//	int score2;
//	double sum;
//};
//void judge(struct STU* p, int x)
//{
//	if (p->sum >= 80 && x > 140)
//		printf("Excellent\n");
//	else
//		printf("Not excellent\n");
//}
//int main()
//{
//	struct STU s[10000] = { 0 };
//	int n = 0; scanf("%d", &n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d %d %d", &s[i].id, &s[i].score1, &s[i].score2);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int sum2 = 0;
//		s[i].sum = s[i].score1 * 0.7 + s[i].score2 * 0.3;
//		sum2 = s[i].score1 + s[i].score2; //素质和学业的总和
//		struct STU* p = &s;
//		//判断函数
//		judge(&s, sum2);
//	}
//	return 0;
//}
//struct student 
//{
//	char name[10];
//	int Chinese, math, English;
//	int sum;
//};
//
//void sort(struct student* stu1, struct student* stu2)
//{
//	if (strcmp(stu1->name, stu2->name) < 0)
//	{
//		printf("%s %s\n", stu1->name, stu2->name);
//		
//	}
//	if (strcmp(stu1->name, stu2->name) > 0)
//	{
//		printf("%s %s\n", stu2->name, stu1->name);
//	}
//}
//
//int i, j;
//
//int main()
//{
//	int n, a, b, c, d;
//	struct student stu[10000];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s %d %d %d", stu[i].name, &stu[i].Chinese, &stu[i].math, &stu[i].English);
//		stu[i].sum = stu[i].Chinese + stu[i].math + stu[i].English;
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			a = stu[i].Chinese - stu[j].Chinese;
//			b = stu[i].math - stu[j].math;
//			c = stu[i].English - stu[j].English;
//			d = stu[i].sum - stu[j].sum;
//			if (abs(a) <= 5 && abs(b) <= 5 && abs(c) <= 5 && abs(d) <= 10)
//			{
//				sort(&stu[i], &stu[j]);
//			}
//		}
//	}
//	return 0;
//}

//全排列算法dfs
//int n, a[10], mark[10] = { 0 };
//void dfs(int step) {
//	if (step > n) {
//		for (int i = 1; i <= n; i++) {
//			printf("%d", a[i]);
//			if (i != n) printf(" ");
//			else printf("\n");
//		}
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (mark[i] == 0) {
//				mark[i] = 1;
//				a[step] = i;
//				dfs(step + 1);
//				mark[i] = 0;
//			}
//		}
//	}
//}
//int main()
//{
//	n = 3;
//	dfs(1);
//	return 0;
//}
//#include<stdio.h>
////打印函数 
//void print(int A[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//}
////交换函数 
//void swap(int A[], int i, int j) {
//	int temp = A[i];
//	A[i] = A[j];
//	A[j] = temp;
//}
////全排列 从第p个到第q个进行全排列 
//void perm(int A[], int p, int q) {
//	if (p == q) {
//		print(A, q + 1);
//	}
//	else {
//		for (int i = p; i <= q; i++) {
//			swap(A, p, i);
//			perm(A, p + 1, q);
//			swap(A, p, i);
//		}
//	}
//}
//
//int main()
//{
//	int A[] = { 1,2,3 };
//	int n = 3;
//	perm(A, 0, 2);
//
//	return 0;
//
//}





