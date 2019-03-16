#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：SubjSearch
*功能：根据分数查询学生
*参数：SLINK *head 待查询链表头
	int n 模式 1为数学成绩 2为语文成绩 3为英语成绩 4为总成绩
*返回值：（SLINK）查询到的学生链表头，未查找到返回NULL
***********************************/
SLINK *SubjSearch(SLINK *head, int n)
{
	extern SLINK *Create(SLINK *head, Student stu);
	extern float FloatInput(char *s1, char *s2, float l, float u);
	//创建查询结果链表头
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;
	float l = 0,	//查询下限
		u = 0;		//查询上限

	system("cls");
	switch (n)
	{
	case 1:
		printf("*************查询学生信息(根据数学成绩)*************\n\n");
		l = FloatInput("成绩查询下限：", "只能为0~1000的实数!", 0, 1000);
		u = FloatInput("成绩查询上限：", "只能为0~1000的实数!", 0, 1000);
		do	//检查匹配并建立链表
		{
			if (head->stu.ma >= l
				&& head->stu.ma <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 2:
		printf("*************查询学生信息(根据语文成绩)*************\n\n");
		l = FloatInput("成绩查询下限：", "只能为0~1000的实数!", 0, 1000);
		u = FloatInput("成绩查询上限：", "只能为0~1000的实数!", 0, 1000);
		do	//检查匹配并建立链表
		{
			if (head->stu.ch >= l
				&& head->stu.ch <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 3:
		printf("*************查询学生信息(根据英语成绩)*************\n\n");
		l = FloatInput("成绩查询下限：", "只能为0~1000的实数!", 0, 1000);
		u = FloatInput("成绩查询上限：", "只能为0~1000的实数!", 0, 1000);
		do	//检查匹配并建立链表
		{
			if (head->stu.en >= l
				&& head->stu.en <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 4:
		printf("**************查询学生信息(根据总成绩)**************\n\n");
		l = FloatInput("成绩查询下限：", "只能为0~3000的实数!", 0, 3000);
		u = FloatInput("成绩查询上限：", "只能为0~3000的实数!", 0, 3000);
		do	//检查匹配并建立链表
		{
			if (head->stu.ma + head->stu.ch + head->stu.en >= l
				&& head->stu.ma + head->stu.ch + head->stu.en <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	}
	if (head1->next == NULL)
		return NULL;
	else
		return head1;
}