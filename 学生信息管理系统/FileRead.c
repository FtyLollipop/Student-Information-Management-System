#include<stdio.h>
#include"SLink.h"

/***********************************
*��������FileRead
*���ܣ���ȡ�����ļ�
*������SLINK *head ����ͷ
*����ֵ����SLINK*���ɹ���ȡ�������ͷָ�룬��ȡʧ�ܷ���NULL
*���������ã���
*���ñ�������int main
***********************************/
SLINK *FileRead(SLINK *head)
{
	extern  SLINK *Create(SLINK *head, Student stu);

	Student stu;	//��ȡ�ĵ���ѧ��
	SLINK *p1,
		*p2;
	FILE *fp;

	if ((fp = fopen("StudentInfo.dat", "r")) == NULL)
		return NULL;
	while (1)
	{
		if (7 > fscanf(fp, "%d%s%s%d%f%f%f",
			&stu.num,
			&stu.name,
			&stu.sex,
			&stu.age,
			&stu.ma,
			&stu.ch,
			&stu.en))
			break;
		if (Create(head, stu) == NULL)
			return NULL;
	}
	fclose(fp);
	return head;
}