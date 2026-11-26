#include <iostream>
using namespace std;
#include <stack>
#include <queue>
typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode* next;
}ArcNode;
typedef struct VertexNode
{
	char vexdata;
	ArcNode* head;
}VertexNode;
typedef struct
{
	VertexNode vertex[20];
	int vexnum; int arcnum;
}AdjList;
int main()
{

}