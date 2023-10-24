#include "funct.h"

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int pIndex = low;

	for (int i = low; i < high; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}

	// поменять местами `pIndex` с пивотом
	swap(arr[pIndex], arr[high]);

	// вернуть `pIndex` (индекс опорного элемента)
	return pIndex;
}