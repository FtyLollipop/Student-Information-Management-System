#include<stdio.h>
#include"SLink.h"

/***********************************
*函数名：FileRead
*功能：读取数据文件
*参数：SLINK *head 链表头
*返回值：（SLINK*）成功读取后的链表头指针，读取失败返回NULL
*本函数调用：无
*调用本函数：int main
***********************************/
SLINK *FileRead(SLINK *head)
{
	extern  SLINK *Create(SLINK *head, Student stu);

	Student stu;	//读取的单个学生
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