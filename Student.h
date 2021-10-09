#include<stdio.h>
typedef struct
{
	char name[8];
	int age;
}stu;
void OutputData(stu e)
{
	printf("%8s", e.name);
	printf("%4d", e.age);
}
void InputData(stu& e)
{
	printf("\n请输入姓名：");
	scanf_s("\n%s", &e.name,8);
	printf("\n请输入年龄：");
	scanf_s("%d", &e.age);
}
