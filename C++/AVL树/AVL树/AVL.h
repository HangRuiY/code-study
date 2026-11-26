#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct AVLTree
{
	int data;
	struct AVLTree* left;
	struct AVLTree* right;
	int height;
}AT;
AT* MakeEmpty(AT* T);
AT* Find(int x,AT* T);
AT* FindMin(AT* T);
AT* FindMax(AT* T);
AT* Insert(int x,AT* T);
int Height(AT* T);
AT* SingleLeft(AT* k2);
AT* SingleRight(AT* k2);
AT* DoubleLeft(AT* k3);
AT* DoubleRight(AT* k3);
void TPrint(AT* p);
