#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*函数名：Add
*功能：添加新学生
*参数：SLINK *head 链表头
*返回值：（SLINK*）成功添加链表项后的链表头指针，内存不足添加失败返回NULL
*本函数调用：float FloatInput
	int IntInput
	SLINK *Create
*调用本函数：int main
***********************************/
SLINK *Add(SLINK *head)
{
	extern float FloatInput(char *s1, char *s2, float l, float u);
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern SLINK *Create(SLINK *head, Student stu);

	Student stu;	//待添加学生信息

	system("cls");
	printf("********************添加学生信息********************\n\n");
	while (1)
	{
		SLINK *p = head->next;
		int isCorrect = 1;
		stu.num = IntInput("输入学号：", "只能输入0~99999的整数!", 0, 99999);
		if (p != NULL)	//判断输入的学号是否已存在
			do
			{
				if (p->stu.num == stu.num)
				{
					printf("学号为%d的学生已存在!\n", stu.num);
					isCorrect = 0;
					break;
				}
				p = p->next;
			} while (p != NULL && p->stu.num <= stu.num);
		else
			break;
		if (isCorrect == 1)
			break;
	}
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		memset(stu.name, 0, sizeof(stu.name));
		printf("输入姓名：");
		for (int i = 0; i < 13; i++)
		{
			if ((ch = getchar()) == '\n')
			{
				isCorrect = 1;
				break;
			}
			else
				stu.name[i] = ch;
		}
		rewind(stdin);
		if (isCorrect == 1)
			break;
		printf("输入过长，最多输入12个字符(6个汉字)!\n");
	}
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		memset(stu.sex, 0, sizeof(stu.sex));
		printf("输入性别：");
		for (int i = 0; i < 3; i++)
		{
			if ((ch = getchar()) == '\n')
				if (stu.sex[0] == -60 && stu.sex[1] == -48 ||
					stu.sex[0] == -59 && stu.sex[1] == -82)	//输入是否是“男”或“女”
				{
					isCorrect = 1;
					break;
				}
				else
					break;
			else
				stu.sex[i] = ch;
		}
		rewind(stdin);
		if (isCorrect == 1)
			break;
		printf("只能输入男或女!\n");
	}
	stu.age = IntInput("输入年龄：", "只能输入1~100之间的整数!", 1, 100);
	stu.ma = FloatInput("数学成绩：", "只能输入0~1000之间的实数!", 0, 1000);
	stu.ch = FloatInput("语文成绩：", "只能输入0~1000之间的实数!", 0, 1000);
	stu.en = FloatInput("英语成绩：", "只能输入0~1000之间的实数!", 0, 1000);

	printf("确认添加吗？\n1)是\n0)否\n");
	char ch = -1;
	while (1)
	{
		if ((ch = _getch()) == '1')
			if ((head = Create(head, stu)) != NULL)
			{
				printf("添加成功!\n");
				return head;
			}
			else
				return NULL;
		else if (ch == '0')
		{
			printf("添加已取消!\n");
			return head;
		}
	}
}