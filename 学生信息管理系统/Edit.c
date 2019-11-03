#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"SLink.h"

/***********************************
*函数名：Edit
*功能：修改学生信息
*参数：SLINK *head 链表头
*返回值：（SLINK*）成功修改后的链表头指针，内存不足创建失败返回NULL
*本函数调用：int IntInput
	float FloatInput
	void PrintInfo
*调用本函数：int main
***********************************/
SLINK *Edit(SLINK *head)
{
	extern int IntInput(char *s1, char *s2, int l, int u);
	extern float FloatInput(char *s1, char *s2, float l, float u);
	extern void PrintInfo(SLINK *head, int n);

	Student stu;
	SLINK *p = head->next,	//忽略链表头
	//创建待修改项链表头
		*p1 = (SLINK*)malloc(sizeof(SLINK));
	p1->stu.num = -1;
	p1->next = NULL;
	int num = 0;

	system("cls");
	printf("***************修改学生信息(根据学号)***************\n\n");
	num = IntInput("输入要修改的学生学号：", "只能为0~99999的整数!", 0, 99999);

	if (p == NULL)	//若数据为空则直接返回NULL
		return NULL;
	do
	{
		if (p->stu.num == num)
		{
			//创建待修改链表项
			p1->next = (SLINK*)malloc(sizeof(SLINK));
			(p1->next)->stu = p->stu;
			(p1->next)->next = NULL;
			PrintInfo(p1, 2);	//打印待修改链表项
			while (1)
			{
				int isCorrect = 0;
				char ch = 0;
				memset(stu.name, 0, sizeof(stu.name));
				printf("输入姓名：");
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
				printf("输入过长，最多输入12个字符(6个汉字)!\n");
			}
			while (1)
			{
				int isCorrect = 0;
				char ch = 0;
				memset(stu.sex, 0, sizeof(stu.sex));
				printf("输入性别：");
				for (int i = 0; i < 3; i++)
				{
					if ((ch = getchar()) == '\n')
						if (stu.sex[0] == -60 && stu.sex[1] == -48 ||
							stu.sex[0] == -59 && stu.sex[1] == -82)	//输入是否是“男”或“女”
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
				printf("只能输入男或女!\n");
			}
			stu.age = IntInput("输入年龄：", "只能输入1~100之间的整数!", 1, 100);
			stu.ma = FloatInput("数学成绩：", "只能输入0~1000之间的实数!", 0, 1000);
			stu.ch = FloatInput("语文成绩：", "只能输入0~1000之间的实数!", 0, 1000);
			stu.en = FloatInput("英语成绩：", "只能输入0~1000之间的实数!", 0, 1000);
			stu.num = num;

			printf("确认修改吗？\n1)是\n0)否\n");
			char ch = -1;
			while (1)
			{
				if ((ch = _getch()) == '1')
				{
					p->stu = stu;
					printf("修改成功!\n");
					return head;
				}
				else if (ch == '0')
				{
					printf("修改已取消!\n");
					return head;
				}
			}
		}
		p = p->next;
	} while (p != NULL);
	return NULL;
}