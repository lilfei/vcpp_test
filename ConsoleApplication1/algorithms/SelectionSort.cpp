#include "pch.h"
#include "SelectionSort.h"

#include <iostream>

using namespace std;

SelectionSort::SelectionSort() {
	int arr[20] = { 32,25,345,567,34,123,435,36,58,769,456,796,576,67,4634,436,60,7867,463,346 };
	selection_sort(arr, 20);
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void SelectionSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort::selection_sort(int arr[], int len)
{
	int i, j;

	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

SelectionSort::~SelectionSort() {

}