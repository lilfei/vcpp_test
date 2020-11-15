#include "pch.h"
#include "Test_page_89.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Test_page_89::Test_page_89()
{
	char buf[5];
	int n = 0;
	for (int i = 32; i < 100; i++) {
		n = i * i;
		_itoa_s(n, buf, 10);
		if ((buf[0] < buf[1] && buf[1] < buf[2] && buf[2] < buf[3]))
			cout << "ÕØÊÂÆû³µºÅÂëÎª: " << n << endl;
	}
}


Test_page_89::~Test_page_89()
{
}
