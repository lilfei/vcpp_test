#include "pch.h"
#include "QuickSort.h"

#include <iostream>
#include <assert.h>

using namespace std;

/*
有问题
*/
QuickSort::QuickSort() 
{
	int arr[20] = { 32,25,345,567,34,123,435,36,58,769,456,796,576,67,4634,436,60,7867,463,346};
	
	// 迭代实现
	//quick_sort(arr, 20);

	// 递归实现
	quick_sort_recursive(arr, 0, 19);

	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

//迭代实现
typedef struct _Range {
	int start, end;
} Range;

Range new_Range(int s, int e) {
	Range r;
	r.start = s;
	r.end = e;
	return r;
}

void QuickSort::swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void QuickSort::quick_sort(int arr[], int len) {
	if (len <= 0)
		return;

	// 结构体数组动太长度定义使用new
	Range *r = new Range[len];
	int p = 0;
	r[p++] = new_Range(0, len - 1);
	while (p) {
		Range range = r[--p];
		if (range.start >= range.end)
			continue;
		int mid = arr[(range.start + range.end) / 2];
		int left = range.start, right = range.end;
		do
		{
			while (arr[left] < mid) ++left;
			while (arr[right] > mid) --right;

			if (left <= right)
			{
				swap(&arr[left], &arr[right]);
				left++; right--;
			}
		} while (left <= right);

		if (range.start < right) r[p++] = new_Range(range.start, right);
		if (range.end > left) r[p++] = new_Range(left, range.end);
	}
}

// 递归实现
void QuickSort::quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
	if (left)
		quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

QuickSort::~QuickSort() {

}