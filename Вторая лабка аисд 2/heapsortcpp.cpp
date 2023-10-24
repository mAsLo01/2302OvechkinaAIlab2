#include "funct.h"

void heapsort(int arr[], int len)
{// Построение кучи (перегруппируем массив)
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = len - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
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