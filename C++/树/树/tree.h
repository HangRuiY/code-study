#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}T;
T* MakeEmpty(T* p);
T* Find(int x, T* p);
T* FindMin(T* p); 
T* FindMax(T* p);
T* TInsert(int x, T* p);
T* TDelete(int x, T* p);
void TPrint(T* p);