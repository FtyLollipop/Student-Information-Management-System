#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*��������Edit
*���ܣ��޸�ѧ����Ϣ
*������SLINK *head ����ͷ
*����ֵ����SLINK*���ɹ��޸ĺ������ͷָ�룬�ڴ治�㴴��ʧ�ܷ���NULL
*���������ã�int IntInput
	float FloatInput
	void PrintInfo
*���ñ�������int main
***********************************/
SLINK *Edit(SLINK *head)
{
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern float FloatInput(char *s1, char *s2, float l, float u);
	extern void PrintInfo(SLINK *head, int n);

	Student stu;
	SLINK *p = head->next,	//��������ͷ
	//�������޸�������ͷ
		*p1 = (SLINK*)malloc(sizeof(SLINK));
	p1->stu.num = -1;
	p1->next = NULL;
	int num = 0;

	system("cls");
	printf("***************�޸�ѧ����Ϣ(����ѧ��)***************\n\n");
	num = IntInput("����Ҫ�޸ĵ�ѧ��ѧ�ţ�", "ֻ��Ϊ0~99999������!", 0, 99999);

	if (p == NULL)	//������Ϊ����ֱ�ӷ���NULL
		return NULL;
	do
	{
		if (p->stu.num == num)
		{
			//�������޸�������
			p1->next = (SLINK*)malloc(sizeof(SLINK));
			(p1->next)->stu = p->stu;
			(p1->next)->next = NULL;
			PrintInfo(p1, 2);	//��ӡ���޸�������
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
			stu.num = num;

			printf("ȷ���޸���\n1)��\n0)��\n");
			char ch = -1;
			while (1)
			{
				if ((ch = _getch()) == '1')
				{
					p->stu = stu;
					printf("�޸ĳɹ�!\n");
					return head;
				}
				else if (ch == '0')
				{
					printf("�޸���ȡ��!\n");
					return head;
				}
			}
		}
		p = p->next;
	} while (p != NULL);
	return NULL;
}