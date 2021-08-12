#include "../pch.h"
#include <iostream>
#include <setjmp.h>

jmp_buf buf;

using namespace std;

/*
setjmp longjmp 可以另类的实现 try catch
*/
JumpTest::JumpTest() {
	if (setjmp(buf)) {
		cout << "back in main" << endl;	
	}
	else {
		cout << "first time through" << endl;
		banana();
	}
}

void JumpTest::banana()
{	
	cout << "in banana() " << endl;
	longjmp(buf, 1);
	// 以下代码不会被执行
	cout << "you`ll never see this, because i longjmp`d" << endl;
}

JumpTest::~JumpTest() {

}