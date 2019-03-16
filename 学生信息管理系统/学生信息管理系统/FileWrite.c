#include<stdio.h>
#include"SLink.h"

/***********************************
*��������FileWrite
*���ܣ�д�������ļ�
*������SLINK *head ����ͷ
*����ֵ����int���ɹ�д�뷵��0��ʧ�ܷ���-1
*���������ã���
*���ñ�������int main
***********************************/
int FileWrite(SLINK *head)
{
	FILE *fp;
	SLINK *p = head->next;	//��������ͷ

	if ((fp = fopen("StudentInfo.dat", "w")) == NULL || head == NULL)
		return -1;
	if (p == NULL)
	{
		fprintf(fp, "");
		return 0;
	}
	do
	{
		fprintf(fp, "%d %s %s %d %.2f %.2f %.2f\n",
			p->stu.num,
			p->stu.name,
			p->stu.sex,
			p->stu.age,
			p->stu.ma,
			p->stu.ch,
			p->stu.en);
		p = p->next;
	} while (p != NULL);
	fclose(fp);
	return 0;
}