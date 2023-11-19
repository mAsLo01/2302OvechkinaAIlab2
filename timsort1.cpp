/*#include "funct.h"
struct steck
{
	int elem[106];
	int l;
};

void insertion(int arr[], int startrun, int len, int minrun, int lenlen)
{
	for (int i = startrun + len - 1; i < startrun + minrun && i < lenlen; i++)
	{
		for (int j = i; j > startrun - 1 && (arr[j - 1] > arr[j]); j--)
		{
			swap(arr[j - 1], arr[j]);
		}
	}

}
void reverse(int arr[], int start_run1, int run1)
{
	int mid = run1 / 2, temp = 0, vsp = start_run1 + mid + 1;
	for (int i = start_run1 - 1; i < start_run1 + mid - 1; i++)
	{
		temp = arr[i];
		arr[i] = arr[vsp];
		arr[vsp] = temp;
		vsp--;

	}
}
void mergestack(int count, stack<steck> stk, int arr[], int len)
{
	int i = 0, j = 0, k = 0,  flag = 0;;
	
	steck o;
	o.l = 0;
	while (count != 1)
	{
		steck g = stk.top();
		stk.pop();
		int* arr1 = new int[g.l + stk.top().l];
		while (i < g.l + stk.top().l)
		{
			if (g.elem[j] > stk.top().elem[k])
			{
				o.elem[i] = stk.top().elem[k];
				k++;
				if (k > stk.top().l)
				{
					flag = 1;
					
					break;
				}
				o.l++;
			}
			else
			{
				o.elem[i] = g.elem[j];
				j++;
				if (j > g.l)
				{
					flag = 2;
					break;
				}
				o.l++;
			}
			i++;
		}
		if (flag == 1)
			for (int u = 0; u < g.l-1; u++)
			{
				o.elem[i] = g.elem[u];
				i++;
				o.l++;
			}
		if (flag == 2)
			for (int u = 0; u < stk.top().l; u++)
			{
				o.elem[i] = stk.top().elem[u];
				i++;o.l++;
			}
		count--;
		cout << g.l + stk.top().l << '\n';
	}
	
	while (!stk.empty())
		stk.pop();

	for (i = 0; i < len; i++)
		arr[i] = o.elem[i];

}
void timsort1(int arr[], int minrun, int len)
{
	stack<steck> stk;
	int i = 1, run = 1, t = 0, run1 = 1, u = 0, start_run1 = 0; int runstart = 0, flag = 0, count = 0, vsp = 0;
	if (arr[i - 1] < arr[i])
		flag = 1;
	else
		flag = 0;
	while (i <= len)
	{

		if (arr[i - 1] < arr[i])
		{

			run++;
		}
		else
		{
			if (flag == 0) {
				start_run1 = i;
				while (arr[i - 1] > arr[i] and i <= len)
				{
					run1++;
					i++;
				}
				reverse(arr, start_run1, run1);
				if (run1 < minrun)
				{
					insertion(arr, start_run1, run1, minrun, len);
					i++;
					if (count == 0)
					{
						steck f;
						f.l = run1;
						for (t = start_run1; t < start_run1 + run1; t++)
						{
							f.elem[u] = arr[t];
							u++;
						}
						u = 0;
						stk.push(f);
						count++;
					}
					else
					{
						if (stk.top().l < run1)
						{
							steck c = stk.top();
							stk.pop();
							steck f;
							f.l = run1;
							for (t = start_run1; t < start_run1 + run1; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);
							stk.push(c);

						}
						else
						{
							steck f;
							f.l = run1;
							for (t = start_run1; t < start_run1 + run1; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);

						}
						count++;
					}
					i++;
					run = 1;
					runstart = i;
					
				}
				else
				{
					if (count == 0)
					{
						steck f;
						f.l = run1;
						for (t = start_run1; t < start_run1 + run1; t++)
						{
							f.elem[u] = arr[t];
							u++;
						}
						u = 0;
						stk.push(f);
						count++;
					}
					else
					{
						if (stk.top().l < run1)
						{
							steck c = stk.top();
							stk.pop();
							steck f;
							f.l = run1;
							for (t = start_run1; t < start_run1 + run1; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);
							stk.push(c);

						}
						else
						{
							steck f;
							f.l = run1;
							for (t = start_run1; t < start_run1 + run1; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);

						}
						count++;
					}
					i++;
					run = 1;
					runstart = i;
				}
				flag = 1;
			}
			else {
				if (run < minrun)
				{
					//if (runstart+minrun<=len)
					insertion(arr, runstart, run, minrun, len);
					


					run = minrun;
					//i++;
					if (count == 0)
					{
						steck f;
						f.l = run;
						for (t = runstart; t < runstart + minrun; t++)
						{
							f.elem[u] = arr[t];
							u++;
						}
						u = 0;
						stk.push(f);
						count++;
					}
					else
					{
						if (stk.top().l < run)
						{
							steck c = stk.top();
							stk.pop();
							steck f;
							f.l = run;
							for (t = runstart; t < runstart + run; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);
							stk.push(c);

						}
						else
						{
							steck f;
							f.l = run;
							for (t = runstart; t < runstart + run; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);

						}
						count++;
					}
					i = runstart+run;
					run = 1;
					runstart = i+1;
				}
				else {
					if (count == 0)
					{
						steck f;
						f.l = run;
						for (t = runstart; t < runstart + run; t++)
						{
							f.elem[u] = arr[t];
							u++;
						}
						u = 0;
						stk.push(f);
						count++;
					}
					else
					{
						if (stk.top().l < run1)
						{
							steck c = stk.top();
							stk.pop();
							steck f;
							f.l = run1;
							for (t = runstart; t < runstart + run; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);
							stk.push(c);
						}
						else
						{
							steck f;
							f.l = run1;
							for (t = runstart; t < runstart + run; t++)
							{
								f.elem[u] = arr[t];
								u++;
							}
							u = 0;
							stk.push(f);

						}
						count++;
					}
					int* arr1 = new int[run];
					delete[] arr1;
					run = 1;
				}
			}

		}
		i++;
	}
	if (count!=0)
	mergestack(count, stk, arr, len);

}*/