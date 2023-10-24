#include "funct.h"

void quicksort(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}

	int pivot = partition(arr, low, high);

	// повторяем подмассив, содержащий элементы, меньшие опорной точки
	quicksort(arr, low, pivot - 1);

	// повторяем подмассив, содержащий элементы, превышающие точку опоры
	quicksort(arr, pivot + 1, high);

}