#include "../pch.h"
#include "Test_6_8.h"
#include <iostream>

using namespace std;

Test_6_8::Test_6_8()
{
	int a[5] = { 0,1,2,3,4 };
	int *p1 = NULL, *p2 = NULL;
	p1 = &a[1];
	p2 = &a[2];
	cout << a[1] << " , " << a[2] << "\n";
	cout << *p1 << " , " << *p2 << "\n";
}


Test_6_8::~Test_6_8()
{
}
