#include "funct.h"

void mergesort(int arr[], int arr1[], int l, int r)
{

	if (r <= l) {
		return;
	}

	// найти середину
	int mid = (l + ((r - l) >> 1));


	mergesort(arr, arr1, l, mid);          
	mergesort(arr, arr1, mid + 1, r);     

	merge(arr, arr1, l, mid, r);
}
