#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*��������NumSearch
*���ܣ�����ѧ�Ų�ѯѧ��
*������SLINK *head ����ѯ����ͷ
*����ֵ����SLINK����ѯ����ѧ������ͷ��δ���ҵ�����NULL
*���������ã�SLINK *Create
	int IntInput
*���ñ�������int main
***********************************/
SLINK *NumSearch(SLINK *head)
{
	extern SLINK *Create(SLINK *head, Student stu);
	extern int IntInput(char *s1, char *s2, int l, int u);
	//������ѯ�������ͷ
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;

	system("cls");
	printf("***************��ѯѧ����Ϣ(����ѧ��)***************\n\n");

	int l = IntInput("����ѧ�Ų�ѯ���ޣ�", "ֻ��Ϊ0~99999������!", 0, 99999),
		u = IntInput("����ѧ�Ų�ѯ���ޣ�", "ֻ��Ϊ0~99999������!", 0, 99999);

	do	//���ƥ�䲢��������
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