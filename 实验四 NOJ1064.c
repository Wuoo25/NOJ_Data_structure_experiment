#include<stdio.h>

typedef int KeyType;

typedef struct entry
{
	KeyType key;

}Entry;
typedef struct list
{
	int n;
	Entry D[100000];
}List;

void Swap(Entry* D, int i, int j)
{
	Entry temp;

	temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}

int partition(List* list, int low, int high)
{
	int i = low, j = high + 1;
	Entry pivot = list->D[low];//pivot�Ƿָ�Ԫ��
	do
	{
		do i++; while (i <= high && list->D[i].key < pivot.key);//iǰ��
		do j--; while (list->D[j].key > pivot.key);//jǰ��
		if (i < j) 
			Swap(list->D, i, j);

	} while (i < j);
	Swap(list->D, low, j);
	return j;//��ʱj�Ƿָ�Ԫ���±�
}

void QuickSort(List* list, int low, int high)//��������ĵݹ麯��
{
	int k;
	if (low < high)
	{
		k = partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}

void QuickSortM(List* list)//���������㷨�������ú���
{
	QuickSort(list, 0, list->n - 1);
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

	QuickSortM(&list);

	for (int i = 0; i < n; i++)
		printf("%d ", list.D[i]);
	printf("\n");

	return 0;

}