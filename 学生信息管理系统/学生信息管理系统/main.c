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

	char cmd = -1;	//�û�ѡ���ѡ��
	//��������ͷ
	SLINK *head = (SLINK*)malloc(sizeof(SLINK)),
		*p = NULL;
	head->stu.num = -1;
	head->next = NULL;
	//��ȡ�����ļ�
	p = FileRead(head);
	if (p != NULL)
		head = p;

	PrintMenu(1, head);
	do
	{
		cmd = _getch();	//��ȡ���˵��û���������
		switch (cmd)
		{
		case '1':	//���ѧ����Ϣ
			p = Add(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("�ڴ治�㣬���ʧ��!\n");
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '2':	//ɾ��ѧ����Ϣ
			p = Remove(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("δ���ҵ�!\n");
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '3':	//�޸�ѧ����Ϣ
			p = Edit(head);
			if (p != NULL)
			{
				head = p;
				FileWrite(head);
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			else
			{
				printf("δ���ҵ�!\n");
				printf("��������������˵�...");
				_getch();
				PrintMenu(1, head);
			}
			break;
		case '4':	//��ѯѧ����Ϣ
			PrintMenu(2, head);
			do
			{
				cmd = _getch();	//��ȡ�����˵��û�����
				switch (cmd)
				{
				case '1':p = NumSearch(head); break;		//��ѧ�Ų�ѯ
				case '2':p = NameSearch(head); break;		//��������ѯ
				case '3':p = SubjSearch(head, 1); break;	//����ѧ�ɼ���ѯ
				case '4':p = SubjSearch(head, 2); break;	//�����ĳɼ���ѯ
				case '5':p = SubjSearch(head, 3); break;	//��Ӣ��ɼ���ѯ
				case '6':p = SubjSearch(head, 4); break;	//���ܳɼ���ѯ
				}
				if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || cmd == '6')
				{
					if (p != NULL)
					{
						PrintInfo(p,2);
						printf("����������ز˵�...");
						_getch();
						PrintMenu(2, head);
					}
					else
					{
						printf("δ���ҵ�!\n");
						printf("����������ز˵�...");
						_getch();
						PrintMenu(2,head);
					}
				}
			} while (cmd != '0');	//�˳������˵�
			cmd = -1;
			PrintMenu(1, head);
			break;
		case '5':	//��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ
			PrintInfo(head, 1);
			printf("����������ز˵�...");
			_getch();
			PrintMenu(1, head);
			break;
		}
	} while (cmd != '0');	//�˳����
	return 0;
}