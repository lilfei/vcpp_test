#include "Practice_9.h"
#include <iostream>
#include <new>

#include "practice_9/namesp.h"

using namespace std;

/*
	头文件包含在<>中，C++编译器在存储标准头文件的主机系统文件中查找
	头文件包含在""中，则先查找当前工作目录或源代码目录，然后去标准目录中查找

*/
Practice_9::Practice_9() {
#if 0
	NewPlace();
#endif

	NamesSp();

}

#pragma region 定位new运算符
/*
	需要使用new头文件
	常规new要使用delete释放内存
	pd2,pd4使用new (buffer)指定的内存为静态内存，所以不能使用delete
*/
int Practice_9::NewPlace() {

	const int BUF = 512;
	const int N = 5;
	char buffer[BUF];

	double *pd1, *pd2;
	int i;

	cout << "Calling new and placement new:\n";
	pd1 = new double[N];			// use heap
	pd2 = new (buffer) double[N];	// use buffer array
	for (i = 0; i < N; i++) {
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Memory addresses:\n" << " heap: " << pd1 << " static: " << (void *)buffer << endl;
	cout << "Memory contents: \n";
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
		
	double *pd3, *pd4;
	cout << "\nCalling new and placement new a second time:\n";
	pd3 = new double[N];			// find new address
	pd4 = new (buffer) double[N];	// overwrite old data
	for (i = 0; i < N; i++) {
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	}
	cout << "Memory contents: \n";
	for (i = 0; i < N; i++) {
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new a third time:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++) {
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	}
	cout << "Memory contents: \n";
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;

	return 0;
}
#pragma endregion

#pragma region 命名空间
/*
	作用域解析运算符 ::
*/

void other(void);
void another(void);

int Practice_9::NamesSp() {

	using debts::Debt;
	using debts::showDebt;
	Debt golf = {
		{"Benny","Goatsniff"},
		120.0
	};
	showDebt(golf);
	other();
	another();

	return 0;
}

void other(void) {
	using namespace debts;
	Person dg = { "Doodles","Glister" };
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++) {
		getDebt(zippy[i]);
	}
	for (i = 0; i < 3; i++) {
		showDebt(zippy[i]);
	}
	cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
	return;
}

void another(void) {
	using pers::Person;
	Person collector = { "Milo","Rightshift" };
	pers::showPerson(collector);
	cout << endl;
}

#pragma endregion


Practice_9::~Practice_9() {

}