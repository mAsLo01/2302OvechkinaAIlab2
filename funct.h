#pragma once
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include "stack.h"
using namespace std;
void swap(int* a, int* b);
void bubble(int len, int heap[]);
void selection(int len, int heap[]);
void merge(int arr[], int arr1[], int low, int mid, int high);
void mergesort(int arr[], int arr1[], int low, int high);
void insertion(int len, int heap[]);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void shellsort1(int arr[], int len);
void shellsort2(int arr[], int arr1[], int len);
void shellsort3(int arr[], int len);
void heapify(int arr[], int len, int i);
void heapsort(int arr[], int len);
void timsortf(int arr[], int minrun, int len, stack** top);
int GetMinrun(int len);
//int introsort(int maxdepth, int arr[], int len);
void introsort(int arr[], int* begin, int* end, int maxdepth);
//void introsort(int arr[], int* begin, int* end);