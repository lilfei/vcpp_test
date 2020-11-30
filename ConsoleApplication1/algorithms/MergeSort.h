#pragma once
class MergeSort
{
public:
	MergeSort();
	void merge_sort(int arr[], int len);
	void merge_sort_recursive(int arr[], int reg[], int start, int end);
	int min(int x, int y);
	~MergeSort();
};

