#include "funct.h"

void heapify(int arr[], int len, int i)
{
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < len && arr[l] > arr[largest])
		largest = l;
	if (r < len && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, len, largest);
	}
}
	/*int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (r < len) {
		if (l <= len and arr[l] > arr[largest] and arr[l] > arr[r])
			largest = l;
		if (r <= len and arr[r] > arr[largest] and arr[r] > arr[l])
			largest = r;
	}
	else
		if (l<len and arr[l]>arr[largest])
			largest = l;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, len, largest);
	}*/
