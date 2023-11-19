#include "funct.h"
void insertionsortf(int a[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }


        a[j] = value;
    }
}

int partitionf(int a[], int low, int high)
{
    int pivot = a[high];
    int pIndex = low;
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[high]);
    return pIndex;
}
int MedianOfThree(int a[], int low, int high)
{
    int mid = (high + low) / 2;
    if ((a[low] >= a[mid] and a[low] <= a[high]) or (a[low] <= a[mid] and a[low] >= a[high]))
        return low;
    if ((a[high] <= a[mid] and a[high] >= a[low]) or (a[high] >= a[mid] and a[high] <= a[low]))
        return high;
    if ((a[mid] <= a[high] and a[mid] >= a[low]) or (a[mid] >= a[high] and a[mid] <= a[low]))
        return mid;
}
int midPartition(int a[], int low, int high)
{
    int pivotIndex = MedianOfThree(a, low, high);
    swap(a[pivotIndex], a[high]);
    return partitionf(a, low, high);
}
void heapsortf(int* begin, int* end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
void introsort(int a[], int* begin, int* end, int maxdepth)
{
    if ((end - begin) < 16) {
        insertionsortf(a, begin - a, end - a);
    }
    else if (maxdepth == 0) {
        heapsortf(begin, end + 1);
    }
    else {
        int pivot = midPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}

/*#include "funct.h"
void insertionsort(int a[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = value;
    }
}

int partitionf(int a[], int low, int high)
{
    int pivot = a[high];
    int pIndex = low;
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[high]);
    return pIndex;
}
int MedianOfThree(int arr[], int low, int high)
{
    int mid = (low-high)/2;
    if ((arr[low] <= arr[high] and arr[low] >= arr[mid]) or (arr[low] <= arr[mid] and arr[low] >= arr[high]))
        return low;
    if ((arr[high] <= arr[low] and arr[high] >= arr[mid]) or (arr[high] <= arr[mid] and arr[high] >= arr[low]))
        return high;
    if ((arr[mid] <= arr[high] and arr[mid] >= arr[low]) or (arr[mid] <= arr[low] and arr[mid] >= arr[high]))
        return mid;
}
int randPartition(int a[], int low, int high)
{

    int pivotIndex = MedianOfThree(a, low, high);
    swap(a[pivotIndex], a[high]);
    return partitionf(a, low, high);
}
void heapsort(int* begin, int* end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
void introsort(int a[], int* begin, int* end, int maxdepth)
{
    if ((end - begin) < 16) {
        insertionsort(a, begin - a, end - a);
    }
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}*/