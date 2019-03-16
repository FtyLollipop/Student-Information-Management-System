#include<stdio.h>
#include<math.h>

/***********************************
*函数名：FloatInput
*功能：根据指定提示使用户输入一个规定范围的非负实数
*参数：char *s1 用于提示用户输入的字符串
	char *s2 用于用户输入错误时的提示字符串
	float l 数字的下限
	float u 数字的上限
*返回值：（float）用户成功输入的实数
*本函数调用：无
*调用本函数：SLINK *Add
	SLINK *Edit
	SLINK *SubjSearch
***********************************/
float FloatInput(char *s1,char *s2, float l, float u)
{
	float x = 0;
	int isInt = 1,	//是否是整数部分
		isFst = 1;	//是否是第一个字符
	char xIn = 0;	//当前读取字符

	while (1)
	{
		printf("%s", s1);
		for (int i = 0; i < 12; i++)
		{
			xIn = getchar();

			if (isFst == 1)
			{
				if (xIn == '.'||xIn=='\n')
					break;	//输入不合法
				isFst = 0;
			}
			if (xIn >= '0'&&xIn <= '9' &&isInt == 1)		//是否是数字且为整数
				x = x * 10 + (int)xIn - 48;
			else if (xIn >= '0'&&xIn <= '9' &&isInt != 1)	//是否是数字且为小数部分
				x += ((int)xIn - 48)*pow(10, isInt);
			else if (xIn == '.')	//是否为小数点
				if (isInt != 1)	//是否已经是小数部分
					break;	//输入不合法
				else
					isInt = 0;
			else if (xIn == '\n')							//是否是回车
			{
				if (x < l || x > u)	//最后数字是否在规定范围内
					break;	//输入不合法
				return x;
			}
			else
				break;	//输入不合法
			if (isInt != 1)
				isInt--;
		}
		printf("%s\n", s2);
		//重置输入状态
		rewind(stdin);
		x = 0;
		isInt = 1;
		isFst = 1;
	}
}