#include "funct.h"

void bubble(int len, int arr[])
{
	int vsp = 0;
	while (vsp != 3)
	{
		vsp = 3;
		for (int i = 1; i < len; i++)
		{
			if (arr[i] < arr[i - 1])
			{
				vsp = 0;
				swap(&(arr[i]), &(arr[i - 1]));
			}
		}
	}
}