#include "Practice_8.h"
#include <iostream>

using namespace std;

Practice_8::Practice_8() {

#if 0	
	Inline();
	Swaps();
#endif

	FunTemp();
}

#pragma region 内联函数
/*
	使用inline关键字
	内联函数不能递归(需要看编译器是否实现)
*/
inline double square(double x) {
	return x * x;
}

int Practice_8::Inline() {

	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);

	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squared = " << square(c++) << "\n";
	cout << "Now c = " << c << "\n";

	return 0;
}
#pragma endregion

#pragma region 引用
void swapr(int & a, int & b);
void swapp(int * p, int * q);
void swapv(int a, int b);

/* 引用，指针 */
int Practice_8::Swaps() {

	int wallet1 = 300;
	int wallet2 = 500;

	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	return 0;
}

void swapr(int & a, int & b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void swapp(int * p, int * q) {
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

// 不可用
void swapv(int a, int b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}
#pragma endregion

#pragma region 函数模板

#pragma region 模板1
template <typename T>
void Swap(T &a, T &b);

int Practice_8::FunTemp() {

	int i = 10;
	int j = 20;

	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;

	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x, y);
	cout << "Now x, y = " << x << ", " << y << ".\n";

	return 0;
}
template <typename T>

void Swap(T &a, T &b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}
#pragma endregion

#pragma region 模板2

template <typename T>  //template A
void ShowArray(T arr[], int n);

template <typename T>   // template B
void ShowArray(T * arr[], int n);

struct debts {
	char name[50];
	double amount;
};

int Practice_8::TempTempOver() {

	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] = {
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};
	double * pd[3];

	for (int i = 0; i < 3; i++) {
		pd[i] = &mr_E[i].amount;
	}
	cout << "Listing Mr.E~s counts of things:\n";
	ShowArray(things, 6);
	cout << "Listing Mr.E~s debts:\n";
	ShowArray(pd, 3);

	return 0;
}

template <typename T>
void ShowArray(T arr[], int n) {
	cout << "template A\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n) {
	cout << "template B\n";
	for (int i = 0; i < n; i++) {
		cout << *arr[i] << ' ';
	}
	cout << endl;
}

#pragma endregion

#pragma endregion



Practice_8::~Practice_8() {

}