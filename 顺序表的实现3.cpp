#include<stdio.h>
#include<malloc.h>
#include"Student.h"
#define MAX 50
typedef stu  ElemType;
//typedef char ElemType;
typedef struct {
	ElemType data[MAX];
	int length;
}SqList;
void CreatList(SqList *& L, ElemType a[], int n){
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
void DispList(SqList * L){
	for (int i = 0; i < L->length; i++)
	{
		OutputData(L->data[i]);
	}
	printf("\n");
}
bool ListInsert(SqList*& L, int i, ElemType e){
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	i--;
	for (j = L->length ; j > i; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[i] = e;
	L->length++;
	printf("����ɹ���\n������Ϊ��");
	DispList(L);
	return true;
}
bool ListDelete(SqList*& L,int i,ElemType e){
	int j;
	if (i<1 || i>L->length + 1)
	{
		return false;
	}
	i--;
	for (j = i; j < L->length ; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	printf("ɾ���ɹ���\n������Ϊ��");
	DispList(L);
	return true;
}
int main(){
	SqList *L;
	int n, b;
	ElemType c;
	ElemType a[2] = { {"jim",18},{"tom",20} };
	CreatList(L, a, 2);
	while (1){
		printf("===============\n");
		printf("1.��������\n2.ɾ������\n3.��������\n4.�˳�\n");
		printf("===============��ѡ��");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			printf("-----------��ѡ������λ�ú�Ԫ�أ�\n");
			scanf_s("%d", &b);
			InputData(c);
			ListInsert(L,b,c);
			break;
		case 2:
			printf("----------������Ҫɾ��λ�ú�Ԫ�أ�\n");
			scanf_s("\n%d", &b);
			InputData(c);
			ListDelete(L, b,c);
			break;
		case 3:
			printf("----------��ǰ���Ա�Ϊ��");
			DispList(L);
			break;
		default:
			printf("�˳��ɹ���\n");
			free(L);
			break;
		}
	}

}