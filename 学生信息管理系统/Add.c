#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*��������Add
*���ܣ������ѧ��
*������SLINK *head ����ͷ
*����ֵ����SLINK*���ɹ����������������ͷָ�룬�ڴ治�����ʧ�ܷ���NULL
*���������ã�float FloatInput
	int IntInput
	SLINK *Create
*���ñ�������int main
***********************************/
SLINK *Add(SLINK *head)
{
	extern float FloatInput(char *s1, char *s2, float l, float u);
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern SLINK *Create(SLINK *head, Student stu);

	Student stu;	//�����ѧ����Ϣ

	system("cls");
	printf("********************���ѧ����Ϣ********************\n\n");
	while (1)
	{
		SLINK *p = head->next;
		int isCorrect = 1;
		stu.num = IntInput("����ѧ�ţ�", "ֻ������0~99999������!", 0, 99999);
		if (p != NULL)	//�ж������ѧ���Ƿ��Ѵ���
			do
			{
				if (p->stu.num == stu.num)
				{
					printf("ѧ��Ϊ%d��ѧ���Ѵ���!\n", stu.num);
					isCorrect = 0;
					break;
				}
				p = p->next;
			} while (p != NULL && p->stu.num <= stu.num);
		else
			break;
		if (isCorrect == 1)
			break;
	}
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		memset(stu.name, 0, sizeof(stu.name));
		printf("����������");
		for (int i = 0; i < 13; i++)
		{
			if ((ch = getchar()) == '\n')
			{
				isCorrect = 1;
				break;
			}
			else
				stu.name[i] = ch;
		}
		rewind(stdin);
		if (isCorrect == 1)
			break;
		printf("����������������12���ַ�(6������)!\n");
	}
	while (1)
	{
		int isCorrect = 0;
		char ch = 0;
		memset(stu.sex, 0, sizeof(stu.sex));
		printf("�����Ա�");
		for (int i = 0; i < 3; i++)
		{
			if ((ch = getchar()) == '\n')
				if (stu.sex[0] == -60 && stu.sex[1] == -48 ||
					stu.sex[0] == -59 && stu.sex[1] == -82)	//�����Ƿ��ǡ��С���Ů��
				{
					isCorrect = 1;
					break;
				}
				else
					break;
			else
				stu.sex[i] = ch;
		}
		rewind(stdin);
		if (isCorrect == 1)
			break;
		printf("ֻ�������л�Ů!\n");
	}
	stu.age = IntInput("�������䣺", "ֻ������1~100֮�������!", 1, 100);
	stu.ma = FloatInput("��ѧ�ɼ���", "ֻ������0~1000֮���ʵ��!", 0, 1000);
	stu.ch = FloatInput("���ĳɼ���", "ֻ������0~1000֮���ʵ��!", 0, 1000);
	stu.en = FloatInput("Ӣ��ɼ���", "ֻ������0~1000֮���ʵ��!", 0, 1000);

	printf("ȷ�������\n1)��\n0)��\n");
	char ch = -1;
	while (1)
	{
		if ((ch = _getch()) == '1')
			if ((head = Create(head, stu)) != NULL)
			{
				printf("��ӳɹ�!\n");
				return head;
			}
			else
				return NULL;
		else if (ch == '0')
		{
			printf("�����ȡ��!\n");
			return head;
		}
	}
}