#include "funct.h"

void shellsort1(int arr[], int len)
{
	for (int step = len / 2; step > 0; step /= 2)
	{
		for (int i = step; i < len; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= step and arr[j - step] > temp; j -= step)
				arr[j] = arr[j - step];
			arr[j] = temp;
		}
	}
}