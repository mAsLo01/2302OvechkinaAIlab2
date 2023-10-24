#include "funct.h"

void mergesort(int arr[], int arr1[], int low, int high)
{

	if (high <= low) {
		return;
	}

	// найти середину
	int mid = (low + ((high - low) >> 1));

	// рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
	// затем объединяем их и возвращаемся вверх по цепочке вызовов

	mergesort(arr, arr1, low, mid);          // разделить/объединить левую половину
	mergesort(arr, arr1, mid + 1, high);     // разделить/объединить правую половину

	merge(arr, arr1, low, mid, high);
}
