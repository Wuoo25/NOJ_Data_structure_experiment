#include<stdio.h>

typedef int KeyType;

typedef struct entry
{
	KeyType key;

}Entry;
typedef struct list
{
	int n;
	Entry D[400];
}List;

void InsertSort(List* list)
{
	int i, j;
	Entry insertitem;
	printf("Insert Sort:\n");
	for (i = 1; i < list->n; i++)
	{
		insertitem = list->D[i];
		for (j = i - 1; j >= 0; j--)
		{
			//不断将有序序列元素向后移动，为待插入元素空出位置
			if (insertitem.key < list->D[j].key)
				list->D[j + 1] = list->D[j];
			else break;
		}
		list->D[j + 1] = insertitem;

		printf("(%d", list->D[0]);
		for (int t = 1; t <= i; t++)
			printf(" %d", list->D[t]);
		printf(")");
		for (int t = i+1; t < list->n; t++)
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
	printf("(%d)",list.D[0]);
	for (int i = 1; i <=n - 1; i++)
	{
		printf(" %d", list.D[i]);
	}
	printf("\n");

	InsertSort(&list);
	printf("Result:\n");
	printf("(%d", list.D[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", list.D[i]);
	printf(")\n");

	return 0;

}