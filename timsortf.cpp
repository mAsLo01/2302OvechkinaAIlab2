#include "funct.h"

void insertiont(int arr[], int startrun, int len, int minrun, int lenlen)
{
	for (int i = startrun + len - 1; i < startrun + minrun - 1 && i < lenlen; i++)
	{
		for (int j = i; j > startrun - 1 && (arr[j - 1] > arr[j]); j--)
		{
			swap(arr[j - 1], arr[j]);
		}
	}

}

void reverset(int arr[], int start_run1, int run1)
{
	int mid = run1 / 2, temp = 0, vsp = start_run1 + run1 - 2;
	for (int i = start_run1 - 1; i < start_run1 + mid - 1; i++)
	{
		temp = arr[i];
		arr[i] = arr[vsp];
		arr[vsp] = temp;
		vsp--;

	}
}

void mergestackt(steck f, steck s, int len, int lenf, int lens, int arr[], stack** tmb)
{
	int i = 0, j = 0, k = 0, flag = 0, tmp = 0, vsp = 0;
	if (f.beg > s.beg)
		i = s.beg;
	else
		i = f.beg;
	(*tmb)->a.beg = i;
	(*tmb)->a.l = s.l + f.l;
	while (i < i + f.l + s.l - 1)
	{
		if (arr[f.beg + j] > arr[s.beg + k])
		{
			tmp = arr[s.beg + k];
			vsp = f.beg + f.l - 1;//?
			while (vsp != f.beg + j - 1)
			{
				arr[vsp] = arr[vsp] + 1;
				vsp--;
			}
			arr[f.beg + j] = tmp;
			k++;
			if (k == lens)
			{
				i++;
				flag = 1;
				break;
			}
		}
		else
		{
			tmp = arr[f.beg + j];
			vsp = s.beg + s.l - 1;
			while (vsp != s.beg + k - 1)
			{
				arr[vsp] = arr[vsp] + 1;
				vsp--;
			}
			arr[s.beg + k] = tmp;
			j++;
			if (j == lenf)
			{
				i++;
				flag = 2;
				break;
			}
		}
		i++;
	}
}
void addstackt(int count, int len, int run, int runstart, int arr[], stack** top)
{
	int t = 0, u = 0, ind = 0;
	steck f;
	f.beg = runstart - 1;
	f.l = run;
	if (count == 0 or (*top)->a.l >= run)
	{
		stack* tmp = new stack;
		if (count == 0)
		{
			tmp->index = 0;
			tmp->prev = NULL;
		}
		else
		{
			tmp->index = (*top)->index + 1;
			tmp->prev = *top;
		}
		tmp->a = f;
		*top = tmp;
	}
	else
	{
		while ((*top)->a.l < run)
		{
			steck t;
			t = (*top)->a;
			if ((*top)->prev == NULL)
			{
				stack* tmp = new stack;
				tmp->index = 0;
				mergestackt(t, f, run + t.l, t.l, run, arr, &tmp);
				tmp->prev = NULL;
				*top = tmp;
				run += t.l;
			}
			else
			{
				*top = (*top)->prev;
				if (!((*top)->prev == NULL) and t.l + run > (*top)->a.l)
				{
					if (run > (*top)->a.l)
					{
						steck c = (*top)->a;
						*top = (*top)->prev;
						stack* tmp = new stack;
						tmp->a = f;
						tmp->index = (*top)->index + 1;
						tmp->prev = *top;
						*top = tmp;
						run = c.l + t.l;
						stack* tmb = new stack;
						tmb->index = (*top)->index + 1;
						mergestackt(c, t, run, c.l, t.l, arr, &tmb);
						tmb->prev = *top;
						*top = tmb;

					}
					else
					{
						stack* tmp = new stack;
						mergestackt(t, f, run + t.l, t.l, run, arr, &tmp);
						tmp->index = (*top)->index + 1;
						tmp->prev = *top;
						*top = tmp;
						//מבתוהטםÿול עמן ט t
						run += t.l;
					}

				}
				else
				{
					stack* tmb = new stack;
					mergestackt(f, t, run + t.l, run, t.l, arr, &tmb);
					tmb->index = (*top)->index + 1;
					tmb->prev = *top;
					*top = tmb;
					run += t.l;
				}
			}
		}
	}
}
void mergemerge(int* arr, int left, int lenl, int right, int lenr) {
	int* f = new int[lenl];
	int* s = new int[lenr];

	int i = 0, j = 0, index = left;

	for (i = 0; i < lenl; i++) f[i] = arr[left + i];
	for (j = 0; j < lenr; j++) s[j] = arr[right + j];

	i = j = 0;

	while (i < lenl && j < lenr) {
		if (f[i] > s[j]) {
			arr[index] = s[j++];
		}
		else {
			arr[index] = f[i++];
		}
		index++;
	}

	while (i < lenl) arr[index++] = f[i++];
	while (j < lenr) arr[index++] = s[j++];

	delete[] f;
	delete[] s;
}


int globalmerge(stack** top, int len, int arr[])
{
	int  flag = 0, i = 0, j = 0, k = 0, tmp = 0, vsp = 0;
	steck t;
	while (i != len)
	{
		i = 0;
		j = 0;
		k = 0;
		steck f;
		f = (*top)->a;//!!!
		*top = (*top)->prev;
		/*if ((*top)->prev==NULL)
		{
			stack* tmp = new stack;
			tmp->a = f;
			tmp->index = (*top)->index+1;
			tmp->prev = *top;
			*top = tmp;
			return 0;
		}*/
		steck s;
		s = (*top)->a;
		t.l = s.l + f.l;
		if (s.beg > f.beg)
			t.beg = f.beg;
		else
			t.beg = s.beg;
		*top = (*top)->prev;
		while (j < s.l and k < f.l)
		{
			if (arr[f.beg + j] > arr[s.beg + k])
			{
				while (arr[f.beg + j] > arr[s.beg + k])
				{
					k++;
				}
				tmp = arr[f.beg + j];
				vsp = s.beg + s.l - 1 + j;
				while (vsp != s.beg + k - 1)
				{
					arr[vsp + 1] = arr[vsp];
					vsp--;
				}
				arr[vsp + 1] = tmp;
				j++;
			}
			else
			{
				while (arr[s.beg + k] > arr[f.beg + j])
				{
					j++;
				}
				int* arr1 = new int[j];
				for (int o = 0; o < j; o++)
				{
					arr1[o] = arr[f.beg + o + k];
				}
				vsp = s.beg + k + s.l - 1;
				while (vsp >= s.beg + k)
				{
					arr[vsp + j] = arr[vsp];
					vsp--;
				}
				for (int o = 0; o < j; o++)
				{
					arr[s.beg + o + k] = arr1[o];
				}
				k++;
				delete[] arr1;
			}
		}
		/*while (i < len)
		{
			if (arr[f.beg + j] > arr[s.beg + k])
			{

				tmp = arr[f.beg + j];
				vsp = s.beg + s.l - 1;//?
				while (vsp != s.beg + j - 1)
				{
					arr[vsp+1] = arr[vsp];
					vsp--;
				}
				arr[s.beg + k+1] = tmp;
				k+=2;
				if (k == s.l)
				{
					i++;
					flag = 1;
					break;
				}
			}
			else
			{
				tmp = arr[s.beg + k];
				vsp = f.beg + f.l - 1;
				while (vsp != f.beg + k - 1)
				{
					arr[vsp+1] = arr[vsp];
					vsp--;
				}
				arr[f.beg + j+1] = tmp;
				j+=2;
				if (j == f.l)
				{
					i++;
					flag = 2;
					break;
				}
			}
			i++;
		}*/
		/*if (flag == 1)
		{
			while (j != f.l)
			{
				t.elem[i] = f.elem[j]; j++; i++;
			}
		}
		if (flag == 2)
		{
			while (k != s.l)
			{
				t.elem[i] = s.elem[k]; k++; i++;
			}
		}*/
		stack* tmb = new stack;
		tmb->a = t;
		if (*top != NULL)
		{
			tmb->index = (*top)->index + 1;
			tmb->prev = *top;
		}
		else
		{
			tmb->index = 0;
			tmb->prev = NULL;
		}
		*top = tmb;
		i = s.l + f.l;
	}
	return 0;
}
void timsortf(int arr[], int minrun, int len, stack** top)
{

	int i = 1, run = 1, t = 0, run1 = 1, u = 0, start_run1 = 0; int runstart = 0, flag = 0, count = 0, vsp = 0;
	while (i < len)
	{
		if (arr[i - 1] < arr[i])
			flag = 1;
		else
			flag = 0;
		if (flag == 0)
		{

			start_run1 = i;
			while (arr[i - 1] > arr[i] and i < len)
			{
				run1++;
				i++;
			}
			reverset(arr, start_run1, run1);
			if (run1 < minrun)
			{
				insertiont(arr, start_run1, run1, minrun, len);
				if (start_run1 + minrun < len)
					run1 = minrun;
				else
					run1 = len - start_run1 + 1;
				//i = start_run1 + run1;
			}
			i = start_run1 + run1;
			addstackt(count, len, run1, start_run1, arr, top);
			count++;
			run1 = 1;
		}
		else
		{

			runstart = i;
			while (arr[i - 1] < arr[i] and i < len)
			{
				run++;
				i++;
			}
			if (run < minrun)
			{
				insertiont(arr, runstart, run, minrun, len);
				if (runstart + minrun < len)
					run = minrun;
				else
					run = len - runstart + 1;
				//i = runstart + run;
			}
			i = runstart + run;
			addstackt(count, len, run, runstart, arr, top);
			count++;
			run = 1;
		}
	}
	if (i == len)
		addstackt(count, len, 1, i, arr, top);
	stack* f, * s;
	while (*top)
	{
		f = *top;
		s = (*top)->prev;
		if (!s) break;
		mergemerge(arr, s->a.beg, s->a.l, f->a.beg, f->a.l);
		s->a.l += f->a.l;
		delete f;
		*top = s;
	}/*
	if ((*top)->prev != NULL)
		globalmerge(top, len, arr);
	stack* tmpp = *top;
	while (tmpp)
	{
		*top = (*top)->prev;
		delete tmpp;
		tmpp = *top;
	}
	for (int s = 0; s < len; s++)
	{
		cout << arr[s] << ' ';
	}*/
}