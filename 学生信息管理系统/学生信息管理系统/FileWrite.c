#include<stdio.h>
#include"SLink.h"

/***********************************
*函数名：FileWrite
*功能：写入数据文件
*参数：SLINK *head 链表头
*返回值：（int）成功写入返回0，失败返回-1
*本函数调用：无
*调用本函数：int main
***********************************/
int FileWrite(SLINK *head)
{
	FILE *fp;
	SLINK *p = head->next;	//忽略链表头

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