#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：Create
*功能：创建链表项
*参数：SLINK *head 链表头
*返回值：（SLINK*）成功创建链表项后的链表头指针，内存不足创建失败返回NULL
*本函数调用：无
*调用本函数：SLINK *Add
	SLINK *FileRead
	SLINK *NameSearch
	SLINK *NumSearch
	SLINK *SubjSearch
***********************************/
SLINK *Create(SLINK *head, Student stu)
{
	SLINK *p = (SLINK*)malloc(sizeof(SLINK));
	if (p == NULL)
		return NULL;
	p->stu = stu;
	SLINK *p1 = head->next,	//忽略链表头
		*p2 = head;
	
	while (p1 != NULL)
	{
		if (p1->stu.num > stu.num)
		{
			p2->next = p;
			p->next = p1;
			return head;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	p2->next = p;
	p->next = NULL;
	return head;
}