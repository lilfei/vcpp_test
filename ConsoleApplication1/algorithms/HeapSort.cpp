#include "pch.h"
#include "HeapSort.h"

#include <iostream>

using namespace std;

HeapSort::HeapSort()
{
	int arr[10] = {23,17,14,6,13,10,1,5,7,12};
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += i;
	}
	cout << sum << endl;
}

HeapSort::~HeapSort()
{
}

