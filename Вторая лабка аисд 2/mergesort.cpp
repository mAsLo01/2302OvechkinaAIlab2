#include "funct.h"

void mergesort(int arr[], int arr1[], int low, int high)
{

	if (high <= low) {
		return;
	}

	// ����� ��������
	int mid = (low + ((high - low) >> 1));

	// ���������� ��������� ������� �� ��� �������� �� ��� ���, ���� ������ ������� �� ������ <= 1,
	// ����� ���������� �� � ������������ ����� �� ������� �������

	mergesort(arr, arr1, low, mid);          // ���������/���������� ����� ��������
	mergesort(arr, arr1, mid + 1, high);     // ���������/���������� ������ ��������

	merge(arr, arr1, low, mid, high);
}
