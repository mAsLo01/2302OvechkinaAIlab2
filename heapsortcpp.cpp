#include "funct.h"

void heapsort(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);
	for (int i = len - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}