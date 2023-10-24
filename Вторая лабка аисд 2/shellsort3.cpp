#include "funct.h"

void shellsort3(int arr[], int len)
{
	int i = 0;
	int n = len;
	while (n > 1)
	{
		n = n / 2;
		i++;
	}
	for (i; i >= 0; i--)
	{
		int step = pow(2, i) - 1;
		for (int k = step; k < len; k++)
		{
			int temp = arr[k];
			int j;
			for (j = k; j >= step and arr[j - step] > temp; j -= step)
				arr[j] = arr[j - step];
			arr[j] = temp;
		}
	}
}