#include "funct.h"

void selection(int len, int arr[])
{
	int s = 0, min = 0, i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&(arr[i]), &(arr[min]));
		}
	}
}