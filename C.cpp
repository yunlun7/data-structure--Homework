#include<stdio.h>
#include<malloc.h>
#define MAX 10
typedef int ElemType;
typedef struct {
	ElemType data[MAX];
	int length;
}SqList;
void CreatList(SqList *& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	if (L != NULL)
	{
	for (;i<n;i++)
	{
		L->data[i] = a[i];
		k++;
	}
	L->length = k;
	}
}
void DispList(SqList * L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	i--;
	for (j = L->length-1; j >= i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	printf("插入成功！\n现数据为：");
	DispList(L);
	return true;
}
bool ListDelete(SqList *&L,int i)
{
	int j;
	if (i<1 || i>L->length + 1);
		return false;
	i--;
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	printf("删除成功！\n现数据为：");
	DispList(L);
	return true;
}
int main()
{
	SqList *L;
	int n;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	CreatList(L, a, 10);
	while (1)
	{
		printf("===============\n");
		printf("1.插入数据\n2.删除数据\n3.查找数据\n4.退出\n");
		printf("===============请选择：");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			int q, w;
			printf("-----------请选择插入的位置和元素：\n");
			scanf_s("%d%d", &q, &w);
			ListInsert(L,q,w);
			break;
		case 2:
			int r, t;
			printf("----------请输入要删除位置：\n");
			scanf_s("%d", &r);
			ListDelete(L, r);
			break;
		case 3:
			printf("----------当前线性表为：\n");
			DispList(L);
			break;
		default:
			printf("退出成功！\n");
			free(L);
			break;
		}
	}

}