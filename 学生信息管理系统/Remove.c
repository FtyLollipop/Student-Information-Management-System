#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*��������Remove
*���ܣ�ɾ��������
*������SLINK *head ����ͷ
*����ֵ����SLINK*���ɹ�ɾ���������ͷָ�룬δ���ҵ�����NULL
*���������ã�int IntInput
	SLINK *Delete
*���ñ�������int main
***********************************/
SLINK *Remove(SLINK *head)
{
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern SLINK *Delete(SLINK *head, int num);
	extern void PrintInfo(SLINK *head, int n);

	SLINK *p = head->next,	//��������ͷ
		*p1 = (SLINK*)malloc(sizeof(SLINK));	//������ɾ��������ͷ
	p1->stu.num = -1;
	p1->next = NULL;
	int num = 0;	//��ɾ��ѧ��

	system("cls");
	printf("***************ɾ��ѧ����Ϣ(����ѧ��)***************\n\n");
	num = IntInput("����Ҫɾ����ѧ�ţ�", "ֻ������0~99999������!", 0, 99999);

	if (p == NULL)	//������Ϊ����ֱ�ӷ���NULL
		return NULL;
	do
	{
		if (p->stu.num == num)
		{
			//������ɾ����Ϣ������ӡ
			p1->next = (SLINK*)malloc(sizeof(SLINK));
			(p1->next)->stu = p->stu;
			(p1->next)->next = NULL;
			PrintInfo(p1, 2);


			printf("ȷ��ɾ����\n1)��\n0)��\n");
			char ch = -1;
			while (1)
			{
				if ((ch = _getch()) == '1')
				{
					if ((head = Delete(head, num)) != NULL)
					{
						printf("ɾ���ɹ�!\n");
						return head;
					}
					else
						return NULL;
				}
				else if (ch == '0')
				{
					printf("ɾ����ȡ��!\n");
					return head;
				}
			}
		}
		p = p->next;
	} while (p != NULL);
	return NULL;
}