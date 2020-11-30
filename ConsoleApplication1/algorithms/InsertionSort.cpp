#include "pch.h"
#include "InsertionSort.h"

#include <iostream>

using namespace std;

InsertionSort::InsertionSort() {
	int arr[20] = { 32,25,345,567,34,123,435,36,58,769,456,796,576,67,4634,436,60,7867,463,346 };
	insertion_sort(arr, 20);
	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void InsertionSort::insertion_sort(int arr[], int len) {
	int i, j, temp;
	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

InsertionSort::~InsertionSort() {

}

