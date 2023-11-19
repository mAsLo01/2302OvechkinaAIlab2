#include "funct.h"

void timsort(int arr[], int len)
{
	int min = arr[0];
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
	}
	arr[index] = arr[0];
	arr[0] = min;
	int mid = 1;
	for (int i = 1; i < len; i++)
	{
		int j = i;
		while (j >= mid && arr[j] < arr[j - mid])
		{
			int temp = arr[j];
			arr[j] = arr[j - mid];
			arr[j - mid] = temp;
			j--;
		}

		// Update the size of sorted part 
		if (i == 2 * mid - 1)
			mid = 2 * mid;

	}
}
