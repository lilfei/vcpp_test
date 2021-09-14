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



Practice_8::~Practice_8() {

}