#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node//定义结构体
{
	int data;
	struct node* next; //结构体指针
};
typedef struct node NODE; //取别名NODE
NODE* create(int n) //自定义创建链表的函数
{
	int i, a;
	NODE *head = NULL; 
	NODE *p1 = NULL;
	NODE *p2 = NULL;
	printf("Please input all:");
	for (i = n; i > 0; --i)
	{
		p1 = (NODE*)malloc(sizeof(NODE)); //分配空间
		scanf_s("%d ", &a);
		if (!p1)
		{
			printf("分配内存失败!\n");
			system("pause");
			exit(1);
		}
		p1->data = a; //给数据域赋值
		if (NULL == head)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1; //指定后继指针
			p2 = p1;
		}
		p2->next = NULL;
		return head;	//返回头结点
	}
}
int main()
{
	int n;
	NODE* p;
	printf("Please input the number of nodes that you want to create:");
	scanf_s("%d", &n);	//输入链表结点的个数
	p = create(n);	//调用创建函数，把结点个数传进去
	printf("Result:\n");
	while (p)	//通过循环输出链表内容
	{
		printf("%d  ", p->data);
		p = p->next;	//指向下一个结点
	}
	printf("\n");
	return 0;
}
//struct Header	//头节点
//{
//	int length;	//记录链表大小
//	struct Node* next;//指针第一个节点的指针
//};
//struct Node //普通节点
//{
//	int data; //数据域
//	struct Node* next;//指向下一个节点的指针
//};

