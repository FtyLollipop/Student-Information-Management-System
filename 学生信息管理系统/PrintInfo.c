#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：PrintInfo
*功能：格式化打印链表数据
*参数：SLINK *head 链表头
	int n 模式，1为打印全部学生数据以及统计数据，2为打印部分学生数据
*本函数调用：无
*调用本函数：int main
	SLINK *Edit
	SLINK *Remove
***********************************/
void PrintInfo(SLINK *head, int n)
{
	SLINK *p = head->next;
	int count = 0;	//链表项总个数
	float maSum = 0,	//数学总成绩
		chSum = 0,	//语文总成绩
		enSum = 0;	//英语总成绩

	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	if (n == 1)
	{
		system("cls");
		printf("********************全部信息统计********************\n\n");
		if (count == 0)
		{
			printf("无记录!\n");
			return;
		}
		printf("共有%d条记录。\n", count);
		p = head->next;
		do
		{
			maSum += p->stu.ma;
			chSum += p->stu.ch;
			enSum += p->stu.en;
			p = p->next;
		} while (p != NULL);
		printf("---------------------------------------------------------\n");
		printf(" 数学平均成绩 | 语文平均成绩 | 英语平均成绩 | 总平均成绩 \n");
		printf("--------------+--------------+--------------+------------\n");
		printf(" %-13.2f| %-13.2f| %-13.2f| %-13.2f\n", maSum / count, chSum / count, enSum / count, (maSum + chSum + enSum) / 3 / count);
		printf("---------------------------------------------------------\n");
	}
	else if (n == 2)
		printf("共查找到%d条记录。\n", count);
	printf("----------------------------------------------------------------------------\n");
	printf(" 学号  | 姓名         | 性别 | 年龄 | 数学    | 语文    | 英语    | 总成绩  \n");
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