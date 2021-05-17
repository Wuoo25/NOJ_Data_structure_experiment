#include <stdio.h>
#include <stdlib.h>
int Find1(int zx[], int n, int x)
{
	int i = 0;
	while (i < n)
	{
		if (x ==zx[i])
			break;
		i++;
	}
	return i;
}
int Find2(char zfx[], int n, char x)
{
	int i = 0;
	while (i < n)
	{
		if (x == zfx[i])
			break;
		i++;
	}
	return i;
}
int Find3(double sx[], int n, double x)
{
	int i = 0;
	while (i < n)
	{
		if (x == sx[i])
			break;
		i++;
	}
	return i;
}
void Delete1(int zx[], int i,int l)
{
	int j;
	
	for (j = i + 1; j < l; j++)
		zx[j-1]=zx[j];
	l--;
	
	for (i = l-1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%d ",zx[i]);
	}
	printf("\n");
}
void Delete2(char zfx[], int i, int l)
{
	int j;

	for (j = i + 1; j < l; j++)
		zfx[j - 1] = zfx[j];
	l--;

	for (i = l-1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%c ", zfx[i]);
		
	}
	printf("\n");
}
void Delete3(double sx[], int i, int l)
{
	int j;

	for (j = i + 1; j < l; j++)
		sx[j - 1] = sx[j];
	l--;

	for (i = l - 1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%g ", sx[i]);

	}
	printf("\n");
}

void Output1(int zx[], int l)
{
	int i;
	
	for (i = l- 1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%d ", zx[i]);
	}
	printf("\n");
}
void Output2(char zfx[], int l)
{
	int i;
	
	for (i = l - 1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%c ", zfx[i]);
	}
	printf("\n");
}
void Output3(double sx[], int l)
{
	int i;

	for (i = l - 1; i >= 0; i--)
	{
		if (!l)
			printf("\n");
		printf("%g ", sx[i]);
	}
	printf("\n");
}

void main()

{
	int L1, L2, L3;
	int d1;
	printf("请按照以下顺序输入：元素数目n（0<n≤1000）\n元素数值\n待删除的元素:\n");
	
	scanf_s("%d",&L1);
	int i1,j1;
	int* zx;
	zx = (int*)malloc(L1 * sizeof(int));
	for (i1 = 0; i1 < L1; i1++)
	{
		scanf_s("%d ", &j1);
		zx[i1] = j1;
	}
	Output1(zx,L1);
	scanf_s("%d", &d1);
	int e1=Find1(zx, L1, d1);
	Delete1(zx,e1,L1);
	free(zx);

	
	scanf_s("%d", &L2);
	char d2;
	int i2;
	char s[1000];
	char *zfx = (char*)malloc(L2 * sizeof(char));
	for (i2 = 0; i2 < L2; i2++)
	{
		scanf_s("%s",s,300);
		zfx[i2] = s[0];
	}
	scanf_s("%s",s,300);
	d2 = s[0];
	int e2= Find2(zfx, L2, d2);
	Output2(zfx, L2);
	Delete2(zfx,e2,L2);
	free(zfx);
	
	
	scanf_s("%d", &L3);
	double d3,j3;
	int i3;
	double* sx = (double*)malloc(L3 * sizeof(double));
	for (i3 = 0; i3 < L3; i3++)
	{
		scanf_s("%lf", &j3);
		sx[i3] =j3;
	}
	scanf_s("%lf", &d3);
	int e3 = Find3(sx, L3, d3);
	Output3(sx, L3);
	Delete3(sx, e3, L3);
	free(sx);

}
