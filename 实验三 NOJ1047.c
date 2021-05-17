#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4 
#define Duplicate 5  
typedef int Status;
typedef int ElemType;

typedef struct mGraph
{
	ElemType** a;
	int n;
	int e;
	ElemType noEdge;

}mGraph;

Status Init(mGraph* mg, int nSize, ElemType noEdgeValue)
{
	int i, j;
	mg->n = nSize;
	mg->e = 0;
	mg->noEdge = noEdgeValue;
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //生成长度为n的一维指针数组
	if (!mg->a)
		return ERROR;
	for (i = 0; i < mg->n; i++) //动态生成二维数组
	{
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j < mg->n; j++)
			mg->a[i][j] = mg->noEdge;
		mg->a[i][i] = 0;
	}
	return OK;
}

Status Insert(mGraph* mg, int u, int v, ElemType w)
{
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)
		return ERROR;
	if (mg->a[u][v] != mg->noEdge || mg->a[v][u] != mg->noEdge)
		return Duplicate;
	mg->a[u][v] = w;
	mg->a[v][u] = w;

}

Status print(mGraph* mg, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", mg->a[i][j]);
		printf("\n");
	}
}

void DFS(int start, int end, int visited[], mGraph mg)   //图的深度优先遍历
{
	printf("%d ", start);
	visited[start] = 1;

	for (int i = 0; i < end; i++)
	{
		if (visited[i] == 0 && mg.a[start][i] == 1)
			DFS(i, end, visited, mg);
	}
}
void DFSGraph(mGraph mg)
{
	int i;
	int* visited = (int*)malloc(mg.n * sizeof(int));   //动态生成标记数组visited
	for (i = 0; i < mg.n; i++)
		visited[i] = 0;                             //初始化visited数组
	for (i = 0; i < mg.n; i++)                            //逐一检查每个顶点，若未被访问，则调用DFS
		if (!visited[i])
			DFS(i, mg.n, visited, mg);
	free(visited);
}

int main()
{
	int i, x, y;
	int n, e;
	mGraph mg;


	scanf_s("%d%d", &n, &e);
	mg.n = n;
	mg.e = e;
	Init(&mg, n, 0);

	for (int i = 0; i < e; i++)
	{
		scanf_s("%d%d", &x, &y);
		Insert(&mg, x, y, 1);
	}

	print(&mg,n);
	
	DFSGraph(mg);
	printf("\n");
	return 0;

}