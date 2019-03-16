#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：NumSearch
*功能：根据学号查询学生
*参数：SLINK *head 待查询链表头
*返回值：（SLINK）查询到的学生链表头，未查找到返回NULL
*本函数调用：SLINK *Create
	int IntInput
*调用本函数：int main
***********************************/
SLINK *NumSearch(SLINK *head)
{
	extern SLINK *Create(SLINK *head, Student stu);
	extern int IntInput(char *s1, char *s2, int l, int u);
	//创建查询结果链表头
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;

	system("cls");
	printf("***************查询学生信息(根据学号)***************\n\n");

	int l = IntInput("输入学号查询下限：", "只能为0~99999的整数!", 0, 99999),
		u = IntInput("输入学号查询上限：", "只能为0~99999的整数!", 0, 99999);

	do	//检查匹配并建立链表
	{
		if (head->stu.num >= l
			&& head->stu.num <= u)
			head1 = Create(head1, head->stu);
		head = head->next;
	} while (head != NULL && head->stu.num <= u);

	if (head1->next == NULL)
		return NULL;
	else
		return head1;
}