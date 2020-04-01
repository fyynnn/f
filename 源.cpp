#include <stdlib.h>
#include<stdio.h>

int getmax(int* len, int n)
{
	int sum = 0, max = 0;
	if (len == NULL || n < 0)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		sum = sum + len[i];

		if (sum < len[i])
		{
			sum = len[i];
		}

		if (sum > max)
		{
			max = sum;
		}

	}
	return max;
}

int main()
{
	int len[100];
	int n, max;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &len[i]);
	}
	max = getmax(len, n);
	printf("%d", max);
	return 0;
}
