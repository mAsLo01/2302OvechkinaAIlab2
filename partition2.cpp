#include "funct.h"

int partition2(int arr[], int low, int high)
{
	int support_element = arr[high];
	int s_eIndex = 0;
	int mid = high / 2;
	if (arr[low] > arr[high])
	{
		if (arr[mid] < arr[high])
			s_eIndex = high;
		else
		{
			if (arr[low] > arr[mid])
				s_eIndex = mid;
			else
				s_eIndex = low;
		}
	}
	else
	{
		if (arr[mid] < arr[low])
			s_eIndex = low;
		else
		{
			if (arr[high] > arr[mid])
				s_eIndex = mid;
			else
				s_eIndex = high;
		}

	}


	for (int i = low; i < high; i++)
	{
		if (arr[i] <= support_element)
		{
			swap(arr[i], arr[s_eIndex]);
			s_eIndex++;
		}
	}

	// поменять местами `pIndex` с пивотом
	swap(arr[s_eIndex], arr[high]);

	// вернуть `pIndex` (индекс опорного элемента)
	return s_eIndex;
}