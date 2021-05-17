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
	Entry pivot = list->D[low];//pivot是分割元素
	do
	{
		do i++; while (i <= high && list->D[i].key < pivot.key);//i前进
		do j--; while (list->D[j].key > pivot.key);//j前进
		if (i < j) 
			Swap(list->D, i, j);

	} while (i < j);
	Swap(list->D, low, j);
	return j;//此时j是分割元素下标
}

void QuickSort(List* list, int low, int high)//快速排序的递归函数
{
	int k;
	if (low < high)
	{
		k = partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}

void QuickSortM(List* list)//快速排序算法的主调用函数
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