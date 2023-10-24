#include "funct.h"

void insertion(int len, int heap[])
{
	int s = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j > 0 && (heap[j - 1] > heap[j]); j--)
		{
			swap(heap[j - 1], heap[j]);
		}
	}

}