#include "funct.h"

void quicksort(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}

	int support_element = partition(arr, low, high);

	quicksort(arr, low, support_element - 1);
	quicksort(arr, support_element + 1, high);

}