#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include<windows.h>

int n;//��Ŀ����
int max;//�����
int symbol;//�����
int  if_decimal; //�Ƿ���С��
int if_parenthese;//�Ƿ�������
int if_file;//�Ƿ������ļ�
FILE *r;
void integerAnswer(int y[])       //���������
{
	int i;
	if (if_file == 2)      //������ļ�
	{
		fprintf(r, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r,"(%d) %d\n", i, y[i]);
		}
	}
	else         //�������Ļ
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %d\n", i, y[i]);
		}
	}
}

void  decimalsAnswer(double y[])     //С�������
{
	int i;
	if (if_file == 1)
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %.2f\n", i, y[i]);
		}
	}
	else
	{
		fprintf(r, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %.2f\n", i, y[i]);
		}
	}
}
void integer()  //������������
{
	int i;
	int a, b;//���������
	int x[1000];//��
	char c;//����
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;    //�������ȡ
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
	integerAnswer(x);   //��ȡ��
}

void  decimals()  //С������������
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00;   //�漴С����ȡ
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
	decimalsAnswer(x);   //��ȡ��
}
void  mixInteger()  //������㣨������
{
	int i;
	int a, b, c;//�����
	int x[1000];//��
	char d, e;//����
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		c = rand() % max;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (if_parenthese == 1)   //������
			{
				x[i] = a - b * c;
			}
			else             //������
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
			if (if_parenthese == 1)//������
			{
				x[i] = a + b / c;
			}
			else//������
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
		if (if_file == 1)   //�������Ļ
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
		else //������ļ�
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
	integerAnswer(x);   //��ȡ��
}

void mixDecimals()  //������㣨С����
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
			if (if_parenthese == 1)   //������
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
	decimalsAnswer(x);   //��ȡ��
}

int main()
{
	printf("\n\n\t**************��ӭ����Сѧ������������ϰ��*******************\n\n");
	printf("1.��������Ŀ������");
	scanf_s("%d", &n);
	printf("\n2.��ѡ�����㷽����1���ӷ� 2������ 3���˷� 4������ 5��������㣩��");
	scanf_s("%d", &symbol);
	printf("\n3.���������������ʮ���ڡ������ڵȣ���");
	scanf_s("%d", &max);
	printf("\n4.�Ƿ���С����1����   2���У�ps:���У����������λС����");
	scanf_s("%d", &if_decimal);
	printf("\n5.�Ƿ������ţ�1����   2���У�ps����ѡ����������ʱѡ������ѡ��ѡ1���� ��");
	scanf_s("%d", &if_parenthese);
	printf("\n6.�����ʽ��1����ʾ����Ļ   2��������ļ��� ��");
	scanf_s("%d", &if_file);
	if (if_file == 2)
	{
		printf("\n��������������.txt�ļ�~");
	}
	r = fopen("��������.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (if_decimal == 1)
		{
			integer();  //����������
		}
		else
		{
			decimals();  //��С������
		}
	}
	else
	{
		if (if_decimal == 1)
		{
			mixInteger();  //�����������
		}

		else
		{
			mixDecimals();  //���С������
		}
	}
	fclose(r);
	printf("\n�Ƿ������������иó���?   (1����   2���˳�)\n");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		system("cls");  //��������������
		main();
	}
}
