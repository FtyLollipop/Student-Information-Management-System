#include<stdio.h>
#include<math.h>

/***********************************
*��������FloatInput
*���ܣ�����ָ����ʾʹ�û�����һ���涨��Χ�ķǸ�ʵ��
*������char *s1 ������ʾ�û�������ַ���
	char *s2 �����û��������ʱ����ʾ�ַ���
	float l ���ֵ�����
	float u ���ֵ�����
*����ֵ����float���û��ɹ������ʵ��
*���������ã���
*���ñ�������SLINK *Add
	SLINK *Edit
	SLINK *SubjSearch
***********************************/
float FloatInput(char *s1,char *s2, float l, float u)
{
	float x = 0;
	int isInt = 1,	//�Ƿ�����������
		isFst = 1;	//�Ƿ��ǵ�һ���ַ�
	char xIn = 0;	//��ǰ��ȡ�ַ�

	while (1)
	{
		printf("%s", s1);
		for (int i = 0; i < 12; i++)
		{
			xIn = getchar();

			if (isFst == 1)
			{
				if (xIn == '.'||xIn=='\n')
					break;	//���벻�Ϸ�
				isFst = 0;
			}
			if (xIn >= '0'&&xIn <= '9' &&isInt == 1)		//�Ƿ���������Ϊ����
				x = x * 10 + (int)xIn - 48;
			else if (xIn >= '0'&&xIn <= '9' &&isInt != 1)	//�Ƿ���������ΪС������
				x += ((int)xIn - 48)*pow(10, isInt);
			else if (xIn == '.')	//�Ƿ�ΪС����
				if (isInt != 1)	//�Ƿ��Ѿ���С������
					break;	//���벻�Ϸ�
				else
					isInt = 0;
			else if (xIn == '\n')							//�Ƿ��ǻس�
			{
				if (x < l || x > u)	//��������Ƿ��ڹ涨��Χ��
					break;	//���벻�Ϸ�
				return x;
			}
			else
				break;	//���벻�Ϸ�
			if (isInt != 1)
				isInt--;
		}
		printf("%s\n", s2);
		//��������״̬
		rewind(stdin);
		x = 0;
		isInt = 1;
		isFst = 1;
	}
}