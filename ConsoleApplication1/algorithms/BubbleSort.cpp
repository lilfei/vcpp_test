#include "pch.h"
#include "BubbleSort.h"

#include <iostream>

using namespace std;

// ð������
BubbleSort::BubbleSort()
{
	int i = 0, j = 0, p = 0, a[7];
	memset(a, 0, sizeof(a)); // ���������ʼ��
	for (i = 1; i <= 6; i++) {
		cout << "�������������� a[" << i << "] = ";
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

	// ��ӡ���
	for (i = 1; i <= 6; i++) {
		cout << a[i] << endl;
	}
}


BubbleSort::~BubbleSort()
{
}
