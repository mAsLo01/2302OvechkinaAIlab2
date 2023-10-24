#include "funct.h"

void bubble(int len, int heap[])
{
	int vsp = 0;
	while (vsp != 3)
	{
		vsp = 3;
		for (int i = 1; i < len; i++)
		{
			if (heap[i] < heap[i - 1])
			{
				vsp = 0;
				swap(&(heap[i]), &(heap[i - 1]));
			}
		}
	}
}