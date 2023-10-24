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

	// �������� ������� `pIndex` � �������
	swap(arr[pIndex], arr[high]);

	// ������� `pIndex` (������ �������� ��������)
	return pIndex;
}