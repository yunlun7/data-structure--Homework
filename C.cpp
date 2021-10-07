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
	printf("����ɹ���\n������Ϊ��");
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
	printf("ɾ���ɹ���\n������Ϊ��");
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
		printf("1.��������\n2.ɾ������\n3.��������\n4.�˳�\n");
		printf("===============��ѡ��");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			int q, w;
			printf("-----------��ѡ������λ�ú�Ԫ�أ�\n");
			scanf_s("%d%d", &q, &w);
			ListInsert(L,q,w);
			break;
		case 2:
			int r, t;
			printf("----------������Ҫɾ��λ�ã�\n");
			scanf_s("%d", &r);
			ListDelete(L, r);
			break;
		case 3:
			printf("----------��ǰ���Ա�Ϊ��\n");
			DispList(L);
			break;
		default:
			printf("�˳��ɹ���\n");
			free(L);
			break;
		}
	}

}