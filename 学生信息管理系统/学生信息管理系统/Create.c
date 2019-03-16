#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*��������Create
*���ܣ�����������
*������SLINK *head ����ͷ
*����ֵ����SLINK*���ɹ�����������������ͷָ�룬�ڴ治�㴴��ʧ�ܷ���NULL
*���������ã���
*���ñ�������SLINK *Add
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
	SLINK *p1 = head->next,	//��������ͷ
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