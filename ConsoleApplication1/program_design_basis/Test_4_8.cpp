#include "pch.h"
#include "Test_4_8.h"
#include <iostream>

using namespace std;

Test_4_8::Test_4_8()
{
	int cc1, cc2, cc3, cc4, cc5, cc6;
	int A, B, C, D, E, F;
	for (int i = 0; i < 64; i++) {
		A = (i & 32) >> 5;
		B = (i & 16) >> 4;
		C = (i & 8) >> 3;
		D = (i & 4) >> 2;
		E = (i & 2) >> 1;
		F = i & 1;

		cc1 = A || B;
		cc2 = !(A && D);
		cc3 = (A && E) || (A && F) || (E && F);
		cc4 = (B && C) || (!B && !C);
		cc5 = (C && !D) || (D && !C);
		cc6 = D || (!D && !E);

		if (cc1 + cc2 + cc3 + cc4 + cc5 + cc6 == 6) {
			cout << "\n A: " << (A == 0 ? "不是" : "是");
			cout << "\n B: " << (B == 0 ? "不是" : "是");
			cout << "\n C: " << (C == 0 ? "不是" : "是");
			cout << "\n D: " << (D == 0 ? "不是" : "是");
			cout << "\n E: " << (E == 0 ? "不是" : "是");
			cout << "\n F: " << (F == 0 ? "不是" : "是");
		}
	}
}


Test_4_8::~Test_4_8()
{
}
