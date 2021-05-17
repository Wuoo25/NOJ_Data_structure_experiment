
#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef int Status;

typedef struct entry
{
	KeyType key;

}Entry;
typedef struct list
{
	int n;
	Entry D[400];
}List;

int FindMin(List list, int startIndex)
{
	int i, minIndex = startIndex;
	for (i = startIndex + 1; i < list.n; i++)
	{
		if (list.D[i].key < list.D[minIndex].key)
			minIndex = i;
	}
	return minIndex;

}

void Swap(Entry* D, int i, int j)
{
	Entry temp;
	if (i == j)return;
	temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}

void SelectSort(List* list)
{
	int minIndex, startIndex ;
	printf("Select Sort:\n");
	for (startIndex=0;startIndex < list->n - 1; startIndex++)
	{
		int k = startIndex;
		minIndex = FindMin(*list, startIndex);
		Swap(list->D, startIndex, minIndex);
		printf("(%d", list->D[0]);
		for (int t = 1; t <= startIndex; t++)
			printf(" %d", list->D[t]);
		printf(")");
		for (int t = startIndex + 1; t < list->n; t++)
			printf(" %d", list->D[t]);
		printf("\n");
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
	printf("(");
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", list.D[i]);
	}
	printf("%d)\n",list.D[n-1]);
	
	SelectSort(&list);
	printf("Result:\n");
	printf("(%d", list.D[0]);
	for (int i = 1; i < n; i++)
		printf(",%d", list.D[i]);
	printf(")\n");

	return 0;

}