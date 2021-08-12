#include "../pch.h"
#include <iostream>

using namespace std;

/*
归并排序
*/
MergeSort::MergeSort() {
	int arr[20] = { 32,25,345,567,34,123,435,36,58,769,456,796,576,67,4634,436,60,7867,463,346 };
	
	// 迭代实现
	//merge_sort(arr, 20);

	// 递归实现
	int reg[20];
	merge_sort_recursive(arr, reg, 0, 19);

	// 打印结果
	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

//递归实现
void MergeSort::merge_sort_recursive(int arr[], int reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

//迭代实现
void MergeSort::merge_sort(int arr[], int len) {
	int* a = arr;
	int* b = (int*)malloc(len * sizeof(int));
	int seg, start;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

int MergeSort::min(int x, int y) {
	return x < y ? x : y;
}

MergeSort::~MergeSort() {

}