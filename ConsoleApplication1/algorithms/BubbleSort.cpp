#include "pch.h"
#include "BubbleSort.h"

#include <iostream>

using namespace std;

// 冒泡排序
BubbleSort::BubbleSort()
{
	int i = 0, j = 0, p = 0, a[7];
	memset(a, 0, sizeof(a)); // 整型数组初始化
	for (i = 1; i <= 6; i++) {
		cout << "请输入待排序的数 a[" << i << "] = ";
		cin >> a[i];
	}

	cout << endl;

	for (j = 1; j <= 5; j++) {
		for (i = 1; i <= 6 - j; i++) {
			if (a[i] < a[i + 1]) {
				p = a[i];
				a[i] = a[i + 1];
				a[i + 1] = p;
			}
		}
	}

	// 打印结果
	for (i = 1; i <= 6; i++) {
		cout << a[i] << endl;
	}
}


BubbleSort::~BubbleSort()
{
}
