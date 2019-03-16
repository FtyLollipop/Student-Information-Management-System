#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"SLink.h"

int main()
{
	extern SLINK *Add(SLINK *head);
	extern SLINK *Edit(SLINK *head);
	extern SLINK *FileRead(SLINK *head);
	extern int FileWrite(SLINK *head);
	extern void MenuPrint(int n, SLINK *head);
	extern SLINK *NameSearch(SLINK *head);
	extern SLINK *NumSearch(SLINK *head);
	extern void PrintInfo(SLINK *head, int n);
	extern void PrintMenu(int n, SLINK *head);
	extern SLINK *Remove(SLINK *head);
	extern SLINK *SubjSearch(SLINK *head, int n);

	char cmd = -1;	//用户选择的选项
	//建立链表头
	SLINK *head = (SLINK*)malloc(sizeof(SLINK)),
		*p = NULL;
	head->stu.num = -1;
	head->next = NULL;
	//读取数据文件
	p = FileRead(head);
	if (p != NULL)
		head = p;

	PrintMenu(1, head);
	do
	{
		cmd = _getch();	//读取主菜单用户键盘输入
		switch (cmd)
		{
		case '1':	//添加学生信息
			p = Add(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("内存不足，添加失败!\n");
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '2':	//删除学生信息
			p = Remove(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("未查找到!\n");
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '3':	//修改学生信息
			p = Edit(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("未查找到!\n");
				printf("按任意键返回主菜单...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '4':	//查询学生信息
			PrintMenu(2, head);
			do
			{
				cmd = _getch();	//读取二级菜单用户输入
				switch (cmd)
				{
				case '1':p = NumSearch(head); break;		//按学号查询
				case '2':p = NameSearch(head); break;		//按姓名查询
				case '3':p = SubjSearch(head, 1); break;	//按数学成绩查询
				case '4':p = SubjSearch(head, 2); break;	//按语文成绩查询
				case '5':p = SubjSearch(head, 3); break;	//按英语成绩查询
				case '6':p = SubjSearch(head, 4); break;	//按总成绩查询
				}
				if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || cmd == '6')
				{
					if (p != NULL)
					{
						PrintInfo(p,2);
						printf("按任意键返回菜单...");
						_getch();
						PrintMenu(2, head);
					}
					else
					{
						printf("未查找到!\n");
						printf("按任意键返回菜单...");
						_getch();
						PrintMenu(2,head);
					}
				}
			} while (cmd != '0');	//退出二级菜单
			cmd = -1;
			PrintMenu(1, head);
			break;
		case '5':	//显示所有学生信息以及统计信息
			PrintInfo(head, 1);
			printf("按任意键返回菜单...");
			_getch();
			PrintMenu(1, head);
			break;
		}
	} while (cmd != '0');	//退出软件
	return 0;
}