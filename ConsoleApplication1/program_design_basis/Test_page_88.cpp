#include "../pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Test_page_88::Test_page_88()
{
	int n = 1089;
	char buf[5];
	_itoa_s(n, buf, 10); // ��λ�ֽ���λ��n
	cout << "��buf�е����ִ�Ϊ" << buf << endl;
	cout << "��buf�е���ֵ����ASCII�룩Ϊ"
		<< (int)buf[0] << ", "
		<< (int)buf[1] << ", "
		<< (int)buf[2] << ", "
		<< (int)buf[3] << endl;
}


Test_page_88::~Test_page_88()
{
}
