#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node//����ṹ��
{
	int data;
	struct node* next; //�ṹ��ָ��
};
typedef struct node NODE; //ȡ����NODE
NODE* create(int n) //�Զ��崴������ĺ���
{
	int i, a;
	NODE *head = NULL; 
	NODE *p1 = NULL;
	NODE *p2 = NULL;
	printf("Please input all:");
	for (i = n; i > 0; --i)
	{
		p1 = (NODE*)malloc(sizeof(NODE)); //����ռ�
		scanf_s("%d ", &a);
		if (!p1)
		{
			printf("�����ڴ�ʧ��!\n");
			system("pause");
			exit(1);
		}
		p1->data = a; //��������ֵ
		if (NULL == head)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1; //ָ�����ָ��
			p2 = p1;
		}
		p2->next = NULL;
		return head;	//����ͷ���
	}
}
int main()
{
	int n;
	NODE* p;
	printf("Please input the number of nodes that you want to create:");
	scanf_s("%d", &n);	//����������ĸ���
	p = create(n);	//���ô����������ѽ���������ȥ
	printf("Result:\n");
	while (p)	//ͨ��ѭ�������������
	{
		printf("%d  ", p->data);
		p = p->next;	//ָ����һ�����
	}
	printf("\n");
	return 0;
}
//struct Header	//ͷ�ڵ�
//{
//	int length;	//��¼�����С
//	struct Node* next;//ָ���һ���ڵ��ָ��
//};
//struct Node //��ͨ�ڵ�
//{
//	int data; //������
//	struct Node* next;//ָ����һ���ڵ��ָ��
//};

