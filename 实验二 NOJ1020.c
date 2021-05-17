#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 100
#define true 1
#define false 0
typedef int BOOL;
typedef char ElementType;

typedef struct btnode
{
	ElementType element;
	struct btnode* lChild;
	struct btnode* rChild;
}BTNode;	

typedef struct binarytree
{
	BTNode* root;
}BinaryTree;

typedef BTNode* ElemTypeQueue;
typedef struct queue
{
	int front;
	int rear;
	int maxSize;
	ElemTypeQueue* element;
}Queue;

BTNode* NewNode(ElementType x, BTNode* ln, BTNode* rn)
{
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));

	p->element = x;
	p->lChild = ln;
	p->rChild = rn;

	return p;
}

BOOL Root(BinaryTree* bt, ElementType* x)
{
	if (bt->root)
	{
		x = &bt->root->element;

		return true;
	}
	else
		return false;
}

void Creat(Queue *Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element= (ElemTypeQueue*)malloc(sizeof(ElemTypeQueue) * mSize);
	Q->front = Q->rear = 0;
}

BOOL IsFull(Queue *Q)
{
	return(Q->rear + 1) % Q->maxSize == Q->front;
}

BOOL EnQueue(Queue* Q, ElemTypeQueue x)
{
	if (IsFull(Q))
		return false;
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return true;
}

BOOL IsEmpty(Queue *Q)
{
	return Q->front == Q->rear;
}

BOOL Front(Queue *Q, ElemTypeQueue *x)
{
	if (IsEmpty(Q))
		return false;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return true;
}

BOOL DeQueue(Queue *Q)
{
	if (IsEmpty(Q))
		return false;
	Q->front = (Q->front + 1) % Q->maxSize;
	return true;
}

void Destroy(Queue *Q)
{
	Q->maxSize = 0;
	free(Q->element);
	Q->front = Q->rear = -1;
}

void Clear(BTNode* t)
{
	if (!t)
		return;
	Clear(t->lChild);
	Clear(t->rChild);
	free(t);
}

void TreeClear(BinaryTree* bt)
{
	Clear(bt->root);
}

BTNode* PreCreateBT(BTNode* t)
{
	char ch;
	do
	{
		scanf_s("%c",&ch);
	} while (ch == ' ');
	if (ch == '#')
		   t = NULL;
    else
	{
		 t = (BTNode*)malloc(sizeof(BTNode));
	     t->element = ch;
	     t->lChild = PreCreateBT(t->lChild);
	     t->rChild = PreCreateBT(t->rChild);
	}
	return t;
}

void PreMakeTree(BinaryTree* bt)
{
	bt->root = PreCreateBT(bt->root);
}

void LevelOrderTree(BinaryTree* tree)
{
	if (!tree->root)
		return;
	Queue Q;
	Creat(&Q, QUEUESIZE);
	BTNode* p = tree->root;
	EnQueue(&Q, p);
	while (!IsEmpty(&Q))
	{
		Front(&Q, &p);
		DeQueue(&Q);
		printf("%c ", p->element);
		if (p->lChild)
			EnQueue(&Q, p->lChild);
		if (p->rChild)
			EnQueue(&Q, p->rChild);
	}
	Destroy(&Q);
}

int main()
{
	BinaryTree t;

	PreMakeTree(&t);
	printf("LevelOrder: ");
	LevelOrderTree(&t);
	TreeClear(&t);
	return 0;
}

