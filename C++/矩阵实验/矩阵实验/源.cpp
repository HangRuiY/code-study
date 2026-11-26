#include "三元组.h"
int map[1010][1010];
int main()
{
	//非零元的输入，以及A,B矩阵的构造
	int r1, c1, n1,r2,c2,n2;
	int v1,v2;
	Matrix A,B;
	int R1, C1,R2,C2;
	cout << "请输入A,B矩阵的行列以及非零元个数:" << endl;
	cin >> R1 >> C1 >> n1 >> R2 >> C2 >> n2;
	A.r = R1; A.c = C1;
	A.num = n1;
	cout << "请输入A矩阵的三元组:" << endl;
	for (int i = 1; i <= n1; i++)
	{
		cin >> r1 >> c1 >> v1;
		A.data[i].row = r1;
		A.data[i].col = c1;
		A.data[i].value = v1;
	}
	B.r = R2; B.c = C2;
	B.num = n2;
	cout << "请输入B矩阵的三元组:" << endl;
	for (int i = 1; i <= n2; i++)
	{
		cin >> r2 >> c2 >> v2;
		B.data[i].row = r2;
		B.data[i].col = c2;
		B.data[i].value = v2;
	}
	//矩阵相加
	M_Add(A, B);
	//矩阵相减
	M_Sup(A, B);
	//矩阵相乘
	M_Mul(A, B);
}