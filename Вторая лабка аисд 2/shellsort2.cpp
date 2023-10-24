#include "funct.h"

void shellsort2(int arr[], int arr1[], int len)
{
	int s = 8;
	while (len < arr1[s]) s--;
	for (s; s >= 0; s--)
	{
		int step = arr1[s];
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