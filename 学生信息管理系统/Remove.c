#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*函数名：Remove
*功能：删除链表项
*参数：SLINK *head 链表头
*返回值：（SLINK*）成功删除链表项的头指针，未查找到返回NULL
*本函数调用：int IntInput
	SLINK *Delete
*调用本函数：int main
***********************************/
SLINK *Remove(SLINK *head)
{
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern SLINK *Delete(SLINK *head, int num);
	extern void PrintInfo(SLINK *head, int n);

	SLINK *p = head->next,	//忽略链表头
		*p1 = (SLINK*)malloc(sizeof(SLINK));	//创建待删除项链表头
	p1->stu.num = -1;
	p1->next = NULL;
	int num = 0;	//待删除学号

	system("cls");
	printf("***************删除学生信息(根据学号)***************\n\n");
	num = IntInput("输入要删除的学号：", "只能输入0~99999的整数!", 0, 99999);

	if (p == NULL)	//若数据为空则直接返回NULL
		return NULL;
	do
	{
		if (p->stu.num == num)
		{
			//建立待删除信息链表并打印
			p1->next = (SLINK*)malloc(sizeof(SLINK));
			(p1->next)->stu = p->stu;
			(p1->next)->next = NULL;
			PrintInfo(p1, 2);


			printf("确认删除吗？\n1)是\n0)否\n");
			char ch = -1;
			while (1)
			{
				if ((ch = _getch()) == '1')
				{
					if ((head = Delete(head, num)) != NULL)
					{
						printf("删除成功!\n");
						return head;
					}
					else
						return NULL;
				}
				else if (ch == '0')
				{
					printf("删除已取消!\n");
					return head;
				}
			}
		}
		p = p->next;
	} while (p != NULL);
	return NULL;
}