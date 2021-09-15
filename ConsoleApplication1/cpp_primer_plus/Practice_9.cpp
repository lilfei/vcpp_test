#include "Practice_9.h"
#include <iostream>
#include <new>

#include "practice_9/namesp.h"

using namespace std;

/*
	ͷ�ļ�������<>�У�C++�������ڴ洢��׼ͷ�ļ�������ϵͳ�ļ��в���
	ͷ�ļ�������""�У����Ȳ��ҵ�ǰ����Ŀ¼��Դ����Ŀ¼��Ȼ��ȥ��׼Ŀ¼�в���

*/
Practice_9::Practice_9() {
#if 0
	NewPlace();
#endif

	NamesSp();

}

#pragma region ��λnew�����
/*
	��Ҫʹ��newͷ�ļ�
	����newҪʹ��delete�ͷ��ڴ�
	pd2,pd4ʹ��new (buffer)ָ�����ڴ�Ϊ��̬�ڴ棬���Բ���ʹ��delete
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

#pragma region �����ռ�
/*
	�������������� ::
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