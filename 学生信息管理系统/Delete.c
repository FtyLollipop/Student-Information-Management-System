#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*��������Delete
*���ܣ���ѧ��ɾ��������
*������SLink *head ����ͷ
	int num Ҫɾ����ѧ��
*����ֵ����SLINK*���ɹ�ɾ��������������ͷָ�룬δ�ҵ�����NULL
*���������ã���
*���ñ�������SLINK *Remove
***********************************/
SLINK *Delete(SLINK *head, int num)
{
	SLINK *p1 = head->next,	//��������ͷ
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