#include "funct.h"

void heapsort(int arr[], int len)
{// ���������� ���� (�������������� ������)
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = len - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);

		// �������� ��������� heapify �� ����������� ����
		heapify(arr, i, 0);
	}/*
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);
	for (int i = len - 1; i > 0; i--)
	{

		swap(arr[0], arr[i]);
		for (int s = 0; s < i; s++)
		{
			//cout << arr[s] << ' ';
		}
		//cout << '\n';
		if (i != 1)
			heapify(arr, i, 0);
	}*/
}