#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SLink.h"

/***********************************
*��������NameSearch
*���ܣ�����������ѯѧ��
*������SLINK *head ����ѯ����ͷ
*����ֵ����SLINK����ѯ����ѧ������ͷ��δ���ҵ�����NULL
*���������ã�SLINK *Create
*���ñ�������int main
***********************************/
SLINK *NameSearch(SLINK *head)
{
	extern SLINK *Create(SLINK *head, Student stu);
	//������ѯ�������ͷ
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;
	//����ѯ��������ʼ��Ϊ��
	char name[13];
	memset(name, 0, sizeof(name));

	system("cls");
	printf("***************��ѯѧ����Ϣ(��������)***************\n\n");
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		printf("�����ѯ������");
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
		printf("����������������12���ַ�(6������)!\n");
	}

	do	//���ƥ�䲢��������
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