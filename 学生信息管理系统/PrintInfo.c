#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*��������PrintInfo
*���ܣ���ʽ����ӡ��������
*������SLINK *head ����ͷ
	int n ģʽ��1Ϊ��ӡȫ��ѧ�������Լ�ͳ�����ݣ�2Ϊ��ӡ����ѧ������
*���������ã���
*���ñ�������int main
	SLINK *Edit
	SLINK *Remove
***********************************/
void PrintInfo(SLINK *head, int n)
{
	SLINK *p = head->next;
	int count = 0;	//�������ܸ���
	float maSum = 0,	//��ѧ�ܳɼ�
		chSum = 0,	//�����ܳɼ�
		enSum = 0;	//Ӣ���ܳɼ�

	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	if (n == 1)
	{
		system("cls");
		printf("********************ȫ����Ϣͳ��********************\n\n");
		if (count == 0)
		{
			printf("�޼�¼!\n");
			return;
		}
		printf("����%d����¼��\n", count);
		p = head->next;
		do
		{
			maSum += p->stu.ma;
			chSum += p->stu.ch;
			enSum += p->stu.en;
			p = p->next;
		} while (p != NULL);
		printf("---------------------------------------------------------\n");
		printf(" ��ѧƽ���ɼ� | ����ƽ���ɼ� | Ӣ��ƽ���ɼ� | ��ƽ���ɼ� \n");
		printf("--------------+--------------+--------------+------------\n");
		printf(" %-13.2f| %-13.2f| %-13.2f| %-13.2f\n", maSum / count, chSum / count, enSum / count, (maSum + chSum + enSum) / 3 / count);
		printf("---------------------------------------------------------\n");
	}
	else if (n == 2)
		printf("�����ҵ�%d����¼��\n", count);
	printf("----------------------------------------------------------------------------\n");
	printf(" ѧ��  | ����         | �Ա� | ���� | ��ѧ    | ����    | Ӣ��    | �ܳɼ�  \n");
	printf("-------+--------------+------+------+---------+---------+---------+---------\n");
	head = head->next;
	do
	{
		printf(" %-5d | %-12s | %s   | %-3d  | %-7.2f | %-7.2f | %-7.2f | %-7.2f \n",
			head->stu.num,
			head->stu.name,
			head->stu.sex,
			head->stu.age,
			head->stu.ma,
			head->stu.ch,
			head->stu.en,
			head->stu.ma + head->stu.ch + head->stu.en);
		head = head->next;
	} while (head != NULL);
	printf("----------------------------------------------------------------------------\n");
}