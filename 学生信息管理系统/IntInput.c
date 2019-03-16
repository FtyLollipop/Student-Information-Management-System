#include<stdio.h>

/***********************************
*函数名：IntInput
*功能：用于根据指定提示使用户输入一个规定范围的非负整数
*参数：char *s1 用于提示用户输入的字符串
	char *s2 用于用户输入错误时的提示字符串
	int l 数字的下限
	int u 数字的上限
*返回值：（int）用户成功输入的整数
*本函数调用：无
*调用本函数：SLINK *Add
	SLINK *Edit
	SLINK *NumSearch
	SLINK *Remove
***********************************/
int IntInput(char *s1, char *s2, int l, int u)
{
	int x = 0,
		isFst=1;	//是否是第一个字符
	char xIn = 0;	//当前读取字符

	while (1)
	{
		printf("%s", s1);
		for (int i = 0; i < 12; i++)
		{
			xIn = getchar();

			if (isFst == 1)
			{
				if (xIn == '\n')
					break;	//输入不合法
				isFst = 0;
			}
			if (xIn >= '0'&&xIn <= '9')	//是否是数字
				x = x * 10 + (int)xIn - 48;
			else if (xIn == '\n')		//是否是回车
			{
				if (x < l || x > u)	//最后数字是否在规定范围内
					break;	//输入不合法
				return x;
			}
			else
				break;	//输入不合法
		}
		printf("%s\n", s2);
		//重置输入状态
		rewind(stdin);
		x = 0;
		isFst = 1;
	}
}