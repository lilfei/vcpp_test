#include "../pch.h"
#include <iostream>
#include <setjmp.h>

jmp_buf buf;

using namespace std;

/*
setjmp longjmp ���������ʵ�� try catch
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
	// ���´��벻�ᱻִ��
	cout << "you`ll never see this, because i longjmp`d" << endl;
}

JumpTest::~JumpTest() {

}