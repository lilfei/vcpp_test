#include "../pch.h"
#include "Test_6_11.h"
#include <iostream>

using namespace std;

Test_6_11::Test_6_11()
{
	char shuzi[] = "987654321";
	char *p = &shuzi[8];
	do
	{
		cout << *p;
		p--;
	} while (p>=shuzi);
	cout << endl;
}


Test_6_11::~Test_6_11()
{
}
