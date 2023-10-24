#include "funct.h"
#include "time.h"
void main()
{

	setlocale(LC_ALL, "Russian");
	int len = 0, s = 0, k = 0;
	fstream f("in.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Файл не открывается";
	}
	else
	{
		while (!f.eof())
		{
			f >> s;
			len++;
		}
		f.close();
		fstream f1("in.txt", ios::in);
		int* arr = new int[len];
		//int* arr1 = new int[len];
		for (s = 0; s < len; s++)
		{
			//arr[s] =s;
			f1 >> arr[s];
			//arr1[s] = arr[s];
		}
		


		cout << "Выберите сортировку:\n";
		cout << "1.Сортировка выбором\n";
		cout << "2.Сортировка вставками\n";
		cout << "3.Сортировка пузырьком\n";
		cout << "4.Сортировка слиянием\n";
		cout << "5.Быстрая сортировка\n";
		cout << "6.Сортировка Шелла классическая\n";
		cout << "7.Сортировка Шелла с выбором длины промежутков Марцина Циура\n";
		cout << "8.Сортировка Шелла с выбором длины промежутков Хиббарда\n";
		cout << "9.Пирамидальная сортировка\n";
		cout << "10.Сортировка timsort\n";
		cout << "11.Сортировка Introsort\n";
		cin >> k;
		if (k == 1)
		{
			clock_t start, end;

			start = clock();
			selection(len, arr);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in ";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 2)
		{
			clock_t start, end;

			start = clock();
			insertion(len, arr);
			end = clock();
			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout<< setprecision(50)<< c << '\n';

		}
		if (k == 3)
		{
			clock_t start, end;

			start = clock();
			bubble(len, arr);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(30) << c << '\n';
		}
		if (k == 4)
		{
			int* arr1 = new int[len];
			for (s = 0; s < len; s++)
			{
				//arr[s] =s;
				arr1[s] = arr[s];
			}
			clock_t start, end;

			start = clock();
			mergesort(arr, arr1, 0, len - 1);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
			delete[] arr1;
		}
		if (k == 5)
		{
			clock_t start, end;

			start = clock();
			quicksort(arr, 0, len - 1);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 6) {
			clock_t start, end;

			start = clock();
			shellsort1(arr, 100);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 7) {
			int arr2[9];
			arr2[0] = 1;
			arr2[1] = 4;
			arr2[2] = 10;
			arr2[3] = 23;
			arr2[4] = 57;
			arr2[5] = 132;
			arr2[6] = 301;
			arr2[7] = 701;
			arr2[8] = 1750;
			clock_t start, end;

			start = clock();
			shellsort2(arr, arr2, 100);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 8) {
			clock_t start, end;
			start = clock();
			shellsort3(arr, 100);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 9) {
			clock_t start, end;
			start = clock();
			heapsort(arr, len);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 10) {
			int min_run;
			clock_t start, end;
			start = clock();
			min_run = GetMinrun(37);
			timsort1(arr, min_run, len);
			timsort(arr, len);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		if (k == 11)
		{
			int maxdepth = log(len) * 2;
			clock_t start, end;
			start = clock();
			introsort(arr, arr, arr + len - 1, maxdepth);
			end = clock();

			double c = ((double)end - start) / ((double)CLOCKS_PER_SEC);

			cout << "The above code block was executed in";
			cout << setprecision(20) << c << '\n';
		}
		for (s = 0; s < len; s++)
		{
			cout << arr[s] << ' ';
		}
		delete[] arr;
	}

}