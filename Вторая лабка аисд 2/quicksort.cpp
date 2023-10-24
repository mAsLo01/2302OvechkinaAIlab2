#include "funct.h"

void quicksort(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}

	int pivot = partition(arr, low, high);

	// ��������� ���������, ���������� ��������, ������� ������� �����
	quicksort(arr, low, pivot - 1);

	// ��������� ���������, ���������� ��������, ����������� ����� �����
	quicksort(arr, pivot + 1, high);

}