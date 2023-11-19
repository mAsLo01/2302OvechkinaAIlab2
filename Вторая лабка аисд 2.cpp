#include "funct.h"
#include "time.h"
#include <chrono>
void main()
{

	setlocale(LC_ALL, "Russian");
	int len = 0, s = 0, k = 0;
	fstream f("10000.txt", ios::in);
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
		//len = 30000;
		f.close();
		fstream f1("10000.txt", ios::in);
		int* arr = new int[len];
		//int* arr1 = new int[len];
		for (s = 0; s < len; s++)
		{
			//arr[s] =s;
			f1 >> arr[s];
			//arr[s] =len -s;5
			//arr1[s] = arr[s];
		}
		/*for (s = len - 1; s >= 0; s--)
		4
			cout << arr[s]<< ' ';
		}*/
		


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
		//cin >> k;
		k = 5;
		//cout << len;
		
		if (k == 1)
		{
			auto begin = std::chrono::steady_clock::now();
			selection(len, arr);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 2)
		{
			auto begin = std::chrono::steady_clock::now();
			insertion(len, arr);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 3)
		{
			auto begin = std::chrono::steady_clock::now();
			bubble(len, arr);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 4)
		{
			int* arr1 = new int[len];
			for (s = 0; s < len; s++)
			{
				//arr[s] =s;
				arr1[s] = arr[s];
			}
			auto begin = std::chrono::steady_clock::now();
			mergesort(arr, arr1, 0, len - 1);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 5)
		{
			auto begin = std::chrono::steady_clock::now();
			quicksort(arr, 0, len - 1);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 6) {
			auto begin = std::chrono::steady_clock::now();
			shellsort1(arr, len);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
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
			auto begin = std::chrono::steady_clock::now();
			shellsort2(arr, arr2, len);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 8) {
			auto begin = std::chrono::steady_clock::now();
			shellsort3(arr, len);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 9) {
			auto begin = std::chrono::steady_clock::now();
			heapsort(arr, len);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 10) {
			int min_run;
			auto begin = std::chrono::steady_clock::now();
			min_run = GetMinrun(len);
			//timsort1(arr, min_run, len);
			//timsort(arr, len);
			stack* top;
			timsortf(arr, min_run, len, &top);
			auto end = chrono::steady_clock::now();

			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
		}
		if (k == 11)
		{
			int maxdepth = log(len) * 2;
			int y = 0; 
			auto begin = std::chrono::steady_clock::now();
			introsort(arr, arr, arr + len - 1, maxdepth);
			auto end = chrono::steady_clock::now();
			
			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			std::cout << "The time: " << elapsed_ms.count() << " ns\n";
			
			//introsort(arr, arr, arr + len - 1, maxdepth);
			//introsort(maxdepth, arr, len);
		}
		
			for (s = 0; s < len; s++)
			{
				//cout << arr[s] << ' ';
			}
		
		delete[] arr;
	}

}