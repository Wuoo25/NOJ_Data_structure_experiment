#include<stdio.h>
#include<stdlib.h>
#define TURE 0
#define FALSE 1
typedef int KeyType;
typedef int BOOL;

typedef struct entry
{
	KeyType key;

}Entry;
typedef struct list
{
	int n;
	Entry D[400];
}List;

void Swap(Entry* D, int i, int j)
{
	Entry temp;
	if (i == j)return;
	temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}

void BubbleSort(List* list)
{
	int i, j;//i标识每趟排序范围最后一个下标，每趟排序元素下标范围是0-i
	printf("Bubble Sort:\n");
	for (i = list->n - 1; i > 0; i--)
	{
		BOOL isSwap = FALSE;//标记一趟排序中是否发生了元素交换
		for (j = 0; j < i; j++)
		{
			if (list->D[j].key > list->D[j + 1].key)
			{
				Swap(list->D, j, j + 1);
				isSwap = TURE;
			}
		}
		if (!isSwap) break;
		printf("(");
		for (int t = 0; t <list->n-1; t++)
		{
			printf("%d", list->D[t]);
			if(i-1==t)
				printf(") ");
			else
				printf(" ");
		}
		printf("%d\n", list->D[list->n-1]);
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	List list;
	list.n = n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &list.D[i].key);
	}
	printf("Source:\n");
	printf("(%d", list.D[0]);
	for (int i = 1; i <= n - 1; i++)
	{
		printf(" %d", list.D[i]);
	}
	printf(")");
	printf("\n");

	BubbleSort(&list);
	printf("Result\n");
	printf("(%d", list.D[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", list.D[i]);
	printf(")\n");

	return 0;

}