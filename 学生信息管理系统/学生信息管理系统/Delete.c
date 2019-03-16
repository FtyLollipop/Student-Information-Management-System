#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：Delete
*功能：按学号删除链表项
*参数：SLink *head 链表头
	int num 要删除的学号
*返回值：（SLINK*）成功删除链表项后的链表头指针，未找到返回NULL
*本函数调用：无
*调用本函数：SLINK *Remove
***********************************/
SLINK *Delete(SLINK *head, int num)
{
	SLINK *p1 = head->next,	//忽略链表头
		*p2 = head;
	do
	{
		if (p1->stu.num == num)
		{
			p2->next = p1->next;
			free(p1);
			return head;
		}
		p1 = p1->next;
		p2 = p2->next;
	} while (p1 != NULL&&p1->stu.num<=num);
	return NULL;
}