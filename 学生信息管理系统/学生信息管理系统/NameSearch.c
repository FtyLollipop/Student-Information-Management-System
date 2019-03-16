#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SLink.h"

/***********************************
*函数名：NameSearch
*功能：根据姓名查询学生
*参数：SLINK *head 待查询链表头
*返回值：（SLINK）查询到的学生链表头，未查找到返回NULL
*本函数调用：SLINK *Create
*调用本函数：int main
***********************************/
SLINK *NameSearch(SLINK *head)
{
	extern SLINK *Create(SLINK *head, Student stu);
	//创建查询结果链表头
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;
	//待查询姓名，初始化为空
	char name[13];
	memset(name, 0, sizeof(name));

	system("cls");
	printf("***************查询学生信息(根据姓名)***************\n\n");
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		printf("输入查询姓名：");
		for (int i = 0; i < 13; i++)
		{
			if ((ch = getchar()) == '\n')
			{
				isCorrect = 1;
				break;
			}
			else
				name[i] = ch;
		}
		rewind(stdin);
		printf("输入过长，最多输入12个字符(6个汉字)!\n");
	}

	do	//检查匹配并建立链表
	{
		if (strcmp(head->stu.name,name)==0)
			head1 = Create(head1, head->stu);
		head = head->next;
	} while (head != NULL);

	if (head1->next == NULL)
		return NULL;
	else
		return head1;
}