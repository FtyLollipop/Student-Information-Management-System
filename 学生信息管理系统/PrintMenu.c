#include<stdio.h>
#include<stdlib.h>
#include"SLink.h"

/***********************************
*函数名：PrintMenu
*功能：打印菜单
*参数：int n 模式，1为打印主菜单，2为打印子菜单
	SLINK *head 链表头
*本函数调用：无
*调用本函数：int main
***********************************/
void PrintMenu(int n, SLINK *head)
{
	int count = 0;	//链表项总个数

	do
	{
		count++;
		head = head->next;
	} while (head != NULL);
	count--;
	system("cls");
	switch (n)
	{
	case 1:
		printf("**************欢迎使用学生信息管理系统**************\n");
		printf("*            (当前共有学生个数：%-5d)             *\n", count);
		printf("*          -----------------------------           *\n");
		printf("*          |    开发者：FtyLollipop    |           *\n");
		printf("*          -----------------------------           *\n");
		printf("*                                                  *\n");
		printf("*          1)添加学生信息                          *\n");
		printf("*          2)删除学生信息(根据学号)                *\n");
		printf("*          3)修改学生信息(根据学号)                *\n");
		printf("*          4)查询学生信息                          *\n");
		printf("*          5)显示所有学生信息以及统计信息          *\n");
		printf("*          0)退出软件                              *\n");
		printf("*                                                  *\n");
		printf("****************************************************\n");
		break;
	case 2:
		printf("********************查询学生信息********************\n");
		printf("*            (当前共有学生个数：%-5d)             *\n", count);
		printf("*                                                  *\n");
		printf("*          1)根据学号查询                          *\n");
		printf("*          2)根据姓名查询                          *\n");
		printf("*          3)根据数学成绩查询                      *\n");
		printf("*          4)根据语文成绩查询                      *\n");
		printf("*          5)根据英语成绩查询                      *\n");
		printf("*          6)根据总成绩查询                        *\n");
		printf("*          0)返回主菜单                            *\n");
		printf("*                                                  *\n");
		printf("****************************************************\n");
		break;
	}
}