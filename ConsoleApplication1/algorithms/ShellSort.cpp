#include "pch.h"
#include "ShellSort.h"

#include <iostream>

using namespace std;

ShellSort::ShellSort() {
	int arr[20] = { 32,25,345,567,34,123,435,36,58,769,456,796,576,67,4634,436,60,7867,463,346 };
	shell_sort(arr, 20);
	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void ShellSort::shell_sort(int arr[], int len) {
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap = gap >> 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
}

ShellSort::~ShellSort() {

}