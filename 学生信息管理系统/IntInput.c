#include<stdio.h>

/***********************************
*��������IntInput
*���ܣ����ڸ���ָ����ʾʹ�û�����һ���涨��Χ�ķǸ�����
*������char *s1 ������ʾ�û�������ַ���
	char *s2 �����û��������ʱ����ʾ�ַ���
	int l ���ֵ�����
	int u ���ֵ�����
*����ֵ����int���û��ɹ����������
*���������ã���
*���ñ�������SLINK *Add
	SLINK *Edit
	SLINK *NumSearch
	SLINK *Remove
***********************************/
int IntInput(char *s1, char *s2, int l, int u)
{
	int x = 0,
		isFst=1;	//�Ƿ��ǵ�һ���ַ�
	char xIn = 0;	//��ǰ��ȡ�ַ�

	while (1)
	{
		printf("%s", s1);
		for (int i = 0; i < 12; i++)
		{
			xIn = getchar();

			if (isFst == 1)
			{
				if (xIn == '\n')
					break;	//���벻�Ϸ�
				isFst = 0;
			}
			if (xIn >= '0'&&xIn <= '9')	//�Ƿ�������
				x = x * 10 + (int)xIn - 48;
			else if (xIn == '\n')		//�Ƿ��ǻس�
			{
				if (x < l || x > u)	//��������Ƿ��ڹ涨��Χ��
					break;	//���벻�Ϸ�
				return x;
			}
			else
				break;	//���벻�Ϸ�
		}
		printf("%s\n", s2);
		//��������״̬
		rewind(stdin);
		x = 0;
		isFst = 1;
	}
}