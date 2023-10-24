#include "funct.h"
void insertionsort1(int a[], int low, int high)
{
	// start from the second element in the subarray
	// (the element at index `low` is already sorted)
	for (int i = low + 1; i <= high; i++)
	{
		int value = a[i];
		int j = i;

		// find index `j` within the sorted subset a[0�i-1]
		// where element a[i] belongs
		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}

		// Note that the subarray `a[j�i-1]` is shifted to
		// the right by one position, i.e., `a[j+1�i]`

		a[j] = value;
	}
}

// Function to partition the array using Lomuto partition scheme
int partition1(int a[], int low, int high)
{
	// Pick the rightmost element as a pivot from the array
	int pivot = a[high];

	// elements less than the pivot will be pushed to the left of `pIndex`
	// elements more than the pivot will be pushed to the right of `pIndex`
	// equal elements can go either way
	int pIndex = low;

	// each time we find an element less than or equal to the pivot, `pIndex`
	// is incremented, and that element would be placed before the pivot.
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	// swap `pIndex` with pivot
	swap(a[pIndex], a[high]);

	// return `pIndex` (index of the pivot element)
	return pIndex;
}

// Quicksort randomized partition to rearrange elements across pivot
int randPartition(int a[], int low, int high)
{
	// choose a random index between `[low, high]`
	int pivotIndex = rand() % (high - low + 1) + low;

	// swap the end element with the element present at a random index
	swap(a[pivotIndex], a[high]);

	// call the partition procedure
	return partition(a, low, high);
}

// Function to perform heapsort on the given range of elements
void heapsort1(int* begin, int* end)
{
	make_heap(begin, end);
	sort_heap(begin, end);
}

// Function to perform introsort on the given array
void introsort(int a[], int* begin, int* end, int maxdepth)
{
	// perform insertion sort if partition size is 16 or smaller
	if ((end - begin) < 16) {
		insertionsort1(a, begin - a, end - a);
	}
	// perform heapsort if the maximum depth is 0
	else if (maxdepth == 0) {
		heapsort1(begin, end + 1);
	}
	else {
		// otherwise, perform Quicksort
		int pivot = randPartition(a, begin - a, end - a);
		introsort(a, begin, a + pivot - 1, maxdepth - 1);
		introsort(a, a + pivot + 1, end, maxdepth - 1);
	}
}
