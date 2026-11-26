#include <iostream>
using namespace std;
#include <stdio.h>

#define MAXSIZE 1000
typedef struct
{
	int row, col;
	int value;
}Three;
typedef struct
{
	Three data[MAXSIZE + 1];
	int r, c, num;
}Matrix;
void M_Add(Matrix A, Matrix B);
void M_Sup(Matrix A, Matrix B);
void M_Mul(Matrix A, Matrix B);