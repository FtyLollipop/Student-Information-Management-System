#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*��������SubjSearch
*���ܣ����ݷ�����ѯѧ��
*������SLINK *head ����ѯ����ͷ
	int n ģʽ 1Ϊ��ѧ�ɼ� 2Ϊ���ĳɼ� 3ΪӢ��ɼ� 4Ϊ�ܳɼ�
*����ֵ����SLINK����ѯ����ѧ������ͷ��δ���ҵ�����NULL
***********************************/
SLINK *SubjSearch(SLINK *head, int n)
{
	extern SLINK *Create(SLINK *head, Student stu);
	extern float FloatInput(char *s1, char *s2, float l, float u);
	//������ѯ�������ͷ
	SLINK *head1 = (SLINK*)malloc(sizeof(SLINK));
	head1->stu.num = -1;
	head1->next = NULL;
	float l = 0,	//��ѯ����
		u = 0;		//��ѯ����

	system("cls");
	switch (n)
	{
	case 1:
		printf("*************��ѯѧ����Ϣ(������ѧ�ɼ�)*************\n\n");
		l = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		u = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		do	//���ƥ�䲢��������
		{
			if (head->stu.ma >= l
				&& head->stu.ma <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 2:
		printf("*************��ѯѧ����Ϣ(�������ĳɼ�)*************\n\n");
		l = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		u = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		do	//���ƥ�䲢��������
		{
			if (head->stu.ch >= l
				&& head->stu.ch <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 3:
		printf("*************��ѯѧ����Ϣ(����Ӣ��ɼ�)*************\n\n");
		l = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		u = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~1000��ʵ��!", 0, 1000);
		do	//���ƥ�䲢��������
		{
			if (head->stu.en >= l
				&& head->stu.en <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	case 4:
		printf("**************��ѯѧ����Ϣ(�����ܳɼ�)**************\n\n");
		l = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~3000��ʵ��!", 0, 3000);
		u = FloatInput("�ɼ���ѯ���ޣ�", "ֻ��Ϊ0~3000��ʵ��!", 0, 3000);
		do	//���ƥ�䲢��������
		{
			if (head->stu.ma + head->stu.ch + head->stu.en >= l
				&& head->stu.ma + head->stu.ch + head->stu.en <= u)
				head1 = Create(head1, head->stu);
			head = head->next;
		} while (head != NULL);
		break;
	}
	if (head1->next == NULL)
		return NULL;
	else
		return head1;
}