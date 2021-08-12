#include "../pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Test_page_88::Test_page_88()
{
	int n = 1089;
	char buf[5];
	_itoa_s(n, buf, 10); // 按位分解四位数n
	cout << "看buf中的数字串为" << buf << endl;
	cout << "看buf中的数值（即ASCII码）为"
		<< (int)buf[0] << ", "
		<< (int)buf[1] << ", "
		<< (int)buf[2] << ", "
		<< (int)buf[3] << endl;
}


Test_page_88::~Test_page_88()
{
}
