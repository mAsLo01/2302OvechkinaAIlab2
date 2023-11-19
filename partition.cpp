#include "funct.h"

int partition(int arr[], int l, int r)
{
	int support_element = arr[r];
	int s_eIndex = l;

	for (int i = l; i < r; i++)
	{
		if (arr[i] <= support_element)
		{
			swap(arr[i], arr[s_eIndex]);
			s_eIndex++;
		}
	}

	swap(arr[s_eIndex], arr[r]);

	return s_eIndex;
}