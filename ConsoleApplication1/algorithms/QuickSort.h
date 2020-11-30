#pragma once
class QuickSort
{
public:
	QuickSort();
	void swap(int *x, int *y);
	void quick_sort(int arr[], const int len);

	void quick_sort_recursive(int arr[], int start, int end);
	~QuickSort();
};

