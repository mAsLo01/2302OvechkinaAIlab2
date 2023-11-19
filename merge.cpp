#include "funct.h"

void merge(int arr[], int arr1[], int low, int mid, int high)
{
	int i = low, j = low, k = mid + 1;


	while (j <= mid && k <= high)
	{
		if (arr[j] <= arr[k]) {
			arr1[i++] = arr[j++];
		}
		else {
			arr1[i++] = arr[k++];
		}
	}

	while (j <= mid) {
		arr1[i++] = arr[j++];
	}

	for (int j = low; j <= high; j++) {
		arr[j] = arr1[j];
	}
}