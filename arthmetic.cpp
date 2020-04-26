#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include<windows.h>

int n;//题目数量
int max;//最大数
int symbol;//运算符
int  if_decimal; //是否是小数
int if_parenthese;//是否是括号
int if_file;//是否生成文件
FILE *r;
void integerAnswer(int y[])       //整数运算答案
{
	int i;
	if (if_file == 2)      //输出到文件
	{
		fprintf(r, "\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r,"(%d) %d\n", i, y[i]);
		}
	}
	else         //输出到屏幕
	{
		printf("\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %d\n", i, y[i]);
		}
	}
}

void  decimalsAnswer(double y[])     //小数运算答案
{
	int i;
	if (if_file == 1)
	{
		printf("\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %.2f\n", i, y[i]);
		}
	}
	else
	{
		fprintf(r, "\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %.2f\n", i, y[i]);
		}
	}
}
void integer()  //整数四则运算
{
	int i;
	int a, b;//两个随机数
	int x[1000];//答案
	char c;//符号
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;    //随机数获取
		b = rand() % max;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % max;
			}
			x[i] = a / b;
		}
		if (if_file == 1)
		{
			printf("(%d) %d%c%d=\n", i, a, c, b);
		}
		else
		{
			fprintf(r, "(%d) %d%c%d=\n", i, a, c, b);
		}
	}
	integerAnswer(x);   //获取答案
}

void  decimals()  //小数的四则运算
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00;   //随即小数获取
		b = rand() % (max * 100) / 100.00;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			x[i] = a / b;
		}
		if (if_file == 1)
		{
			printf("(%d) %.2f%c%.2f=\n", i, a, c, b);
		}
		else
		{
			fprintf(r, "(%d) %.2f%c%.2f=\n", i, a, c, b);
		}
	}
	decimalsAnswer(x);   //获取答案
}
void  mixInteger()  //混合运算（整数）
{
	int i;
	int a, b, c;//随机数
	int x[1000];//答案
	char d, e;//符号
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		c = rand() % max;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (if_parenthese == 1)   //无括号
			{
				x[i] = a - b * c;
			}
			else             //有括号
			{
				x[i] = (a - b) * c;
			}
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (if_parenthese == 1)//有括号
			{
				x[i] = a + b / c;
			}
			else//无括号
			{
				x[i] = (a + b) / c;
			}
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (if_parenthese == 1)
			{
				x[i] = a - b / c;
			}
			else
			{
				x[i] = (a - b) / c;
			}
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (if_parenthese == 1)
			{
				x[i] = a + b * c;
			}
			else
			{
				x[i] = (a + b) * c;
			}
		}
		if (if_file == 1)   //输出到屏幕
		{
			if (if_parenthese == 1)
			{
				printf("(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			}
			else
			{
				printf("(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
			}
		}
		else //输出到文件
		{
			if (if_parenthese == 1)
			{
				fprintf(r, "(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			}
			else
			{
				fprintf(r, "(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
			}
		}
	}
	integerAnswer(x);   //获取答案
}

void mixDecimals()  //混合运算（小数）
{
	int i;
	double x[1000], a, b, c;
	char d, e;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00 + 1;
		b = rand() % (max * 100) / 100.00 + 1;
		c = rand() % (max * 100) / 100.00 + 1;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (if_parenthese == 1)   //有括号
			{
				x[i] = a - b * c;
			}
			else
			{
				x[i] = (a - b) * c;
			}
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (b == 0)
			{
				c = rand() % (max * 100) / 100.00 + 1;
			}
			if (if_parenthese == 1)
			{
				x[i] = a + b / c;
			}
			else
			{
				x[i] = (a + b) / c;
			}
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			if (if_parenthese == 1)
			{
				x[i] = a - b / c;
			}
			else
			{
				x[i] = (a - b) / c;
			}
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (if_parenthese == 1)
			{
				x[i] = a + b * c;
			}
			else
			{
				x[i] = (a + b) * c;
			}
		}
		if (if_file == 1)
		{
			if (if_parenthese == 1)
			{
				printf("(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			}
			else
			{
				printf("(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
			}
		}
		else
		{
			if (if_parenthese == 1)
			{
				fprintf(r, "(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			}
			else
			{
				fprintf(r, "(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
			}
		}
	}
	decimalsAnswer(x);   //获取答案
}

int main()
{
	printf("\n\n\t**************欢迎进入小学生四则运算练习题*******************\n\n");
	printf("1.请输入题目个数：");
	scanf_s("%d", &n);
	printf("\n2.请选择运算方法（1、加法 2、减法 3、乘法 4、除法 5、混合运算）：");
	scanf_s("%d", &symbol);
	printf("\n3.请输入最大数（如十以内、百以内等）：");
	scanf_s("%d", &max);
	printf("\n4.是否有小数（1、无   2、有）ps:若有，结果保留两位小数：");
	scanf_s("%d", &if_decimal);
	printf("\n5.是否有括号（1、无   2、有）ps：此选项仅混合运算时选择，其他选项选1即可 ：");
	scanf_s("%d", &if_parenthese);
	printf("\n6.输出方式（1、显示在屏幕   2、输出到文件） ：");
	scanf_s("%d", &if_file);
	if (if_file == 2)
	{
		printf("\n已生成四则运算.txt文件~");
	}
	r = fopen("四则运算.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (if_decimal == 1)
		{
			integer();  //简单整数运算
		}
		else
		{
			decimals();  //简单小数运算
		}
	}
	else
	{
		if (if_decimal == 1)
		{
			mixInteger();  //混合整数运算
		}

		else
		{
			mixDecimals();  //混合小数运算
		}
	}
	fclose(r);
	printf("\n是否重新运行运行该程序?   (1、是   2、退出)\n");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		system("cls");  //清屏，重新运行
		main();
	}
}
