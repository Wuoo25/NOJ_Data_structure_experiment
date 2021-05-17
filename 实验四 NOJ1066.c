#include<stdio.h>

typedef int KeyType;

typedef struct entry
{
	KeyType key;

}Entry;
typedef struct maxheap   //最大堆结构体
{
	int n;
	Entry D[100000];
}MaxHeap;


void Swap(Entry* D, int i, int j)
{
	Entry temp;

	temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}


void AdjustDown(KeyType heap[], int r, int j)
{
	int child = 2 * r + 1;
	int tmp = heap[r];
	while (child <= j)
	{
		if (child < j && heap[child] < heap[child + 1])
			child++;
		if (tmp >= heap[child]) break;
		heap[(child - 1) / 2] = heap[child];
		child = 2 * child + 1;
	}
	heap[(child - 1) / 2] = tmp;
}


void HeapSort(MaxHeap* hp,int n)
{
	int i;
	Entry temp;
	for (i = (n-2)/2;i >= 0;i--)
		AdjustDown(hp->D, i, hp->n - 1);
	for (i = hp->n - 1; i > 0; i--)    //指向当前堆顶元素
	{
		Swap(hp->D, 0, i);     //交换堆底与堆顶元素
		AdjustDown(hp->D,0,i-1);
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	MaxHeap hp;
	hp.n = n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &hp.D[i].key);
	}

	HeapSort(&hp,n);

	for (int i = 0; i < n; i++)
		printf("%d ", hp.D[i]);
	printf("\n");

	return 0;

}