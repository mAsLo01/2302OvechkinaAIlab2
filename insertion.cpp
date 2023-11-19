#include "funct.h"

void insertion(int len, int arr[])
{
	int s = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j > 0 && (arr[j - 1] > arr[j]); j--)
		{
			swap(arr[j - 1], arr[j]);
		}
	}

}