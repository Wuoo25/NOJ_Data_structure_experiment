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

//n1和n2是两个子序列长度，low是第一个子序列第一个元素下标
void Merge(List* list, Entry* temp, int low, int n1, int n2)
{
	int i = low, j = low + n1;//i，j初始时分别指向两个序列的第一个元素
	while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
	{
		if (list->D[i].key <= list->D[j].key)
			*temp++ = list->D[i++];
		else *temp++ = list->D[j++];
	}
	while (i <= low + n1 - 1)
		*temp++ = list->D[i++];//剩余元素直接复制到temp
	while(j<=low+n1+n2-1)
		*temp++ = list->D[j++];//剩余元素直接复制到temp
}

void MergeSort(List* list)
{
	Entry temp[10000];
	int low, n1, n2, i, size = 1;
	while(size < list->n)
	{
		low = 0;//low是一对待合并序列中第一个序列的第一个元素下标
		while (low + size < list->n) //至少存在两个子序列需要合并
		{
			n1 = size;
			if (low + size * 2 < list->n)
				n2 = size;//计算第二个序列长度
			else
				n2 = list->n - low - size;
			Merge(list, temp + low, low, n1, n2);
			low += n1 + n2;  //确定下一对待合并序列的第一序列的第一个元素下标
		}
		for (i = 0; i < low; i++)
			list->D[i] = temp[i];  //复制一趟合并结果
		size *= 2;  //子序列长度翻倍
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

	MergeSort(&list);

	for (int i = 0; i < n; i++)
		printf("%d ", list.D[i]);
	printf("\n");

	return 0;

}