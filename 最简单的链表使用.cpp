#include<stdio.h>
struct Student
{
	int age;
	int num;
	/*char name[10];*/
	struct Student* next;
};
typedef struct Student NODE;
int main()
{
	NODE* head, * p;//创建头结点、和普通结点
	Student a, b, c;
	a.age = 10; a.num = 1010; /*a.name = {"lili"};*/
	b.age = 11; b.num = 1011;
	c.age = 12; c.num = 1012;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;//第一个值赋值给头指针，一次将下一个值赋值给上一个结点，最后一个结点赋值为空
	p = head;
	while (p)
	{
		printf("%3d  %2d", p->age,p->num);
		p = p->next;//指向下一个结点
	}
}

