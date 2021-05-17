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

//n1��n2�����������г��ȣ�low�ǵ�һ�������е�һ��Ԫ���±�
void Merge(List* list, Entry* temp, int low, int n1, int n2)
{
	int i = low, j = low + n1;//i��j��ʼʱ�ֱ�ָ���������еĵ�һ��Ԫ��
	while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
	{
		if (list->D[i].key <= list->D[j].key)
			*temp++ = list->D[i++];
		else *temp++ = list->D[j++];
	}
	while (i <= low + n1 - 1)
		*temp++ = list->D[i++];//ʣ��Ԫ��ֱ�Ӹ��Ƶ�temp
	while(j<=low+n1+n2-1)
		*temp++ = list->D[j++];//ʣ��Ԫ��ֱ�Ӹ��Ƶ�temp
}

void MergeSort(List* list)
{
	Entry temp[10000];
	int low, n1, n2, i, size = 1;
	while(size < list->n)
	{
		low = 0;//low��һ�Դ��ϲ������е�һ�����еĵ�һ��Ԫ���±�
		while (low + size < list->n) //���ٴ���������������Ҫ�ϲ�
		{
			n1 = size;
			if (low + size * 2 < list->n)
				n2 = size;//����ڶ������г���
			else
				n2 = list->n - low - size;
			Merge(list, temp + low, low, n1, n2);
			low += n1 + n2;  //ȷ����һ�Դ��ϲ����еĵ�һ���еĵ�һ��Ԫ���±�
		}
		for (i = 0; i < low; i++)
			list->D[i] = temp[i];  //����һ�˺ϲ����
		size *= 2;  //�����г��ȷ���
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