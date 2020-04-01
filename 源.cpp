#include <stdlib.h>
#include<stdio.h>

int getmax(int* arr, int n)
{
	int sum = 0, max = 0;
	if (arr == NULL || n < 0)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];

		if (sum < arr[i])
		{
			sum = arr[i];
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
	int arr[100];
	int n, max;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	max = getmax(arr, n);
	printf("%d", max);
	return 0;
}
