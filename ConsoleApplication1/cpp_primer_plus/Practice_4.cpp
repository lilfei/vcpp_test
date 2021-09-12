#include "Practice_4.h"
#include <iostream>
#include <vector>  // STL C++98
#include <array>   // C++11

using namespace std;

struct inflatable {
	char name[20];
	float volume;
	double price;
};

/*
	ʹ��new�����ڴ棬����ڴ治�㣬�򷵻�0������ָ��
	ʹ��delete�ͷ��ڴ�(�Կ�ָ����Ч),ʹ�÷�������:
	int * ps = new int;
	...
	delete ps;

	����ͬ��:
	int * psome = new int [10];
	...
	delete [] psome;

	ʹ�� new �� delete Ӧ�������¹���
	1������ʹ�� delete �ͷŲ��� new ������ڴ�
	2������ʹ�� delete �ͷ�ͬһ���ڴ�����
	3�����ʹ�� new []Ϊ��������ڴ棬Ӧʹ�� delete []�ͷ��ڴ�
	4�����ʹ�� new Ϊʵ������ڴ棬Ӧʹ�� delete (û�з�����)���ͷ�
	5�����ԶԿ�ָ��ʹ��delete

	C++�ڴ����ʽΪ3�֣�
	1���Զ��洢��ͨ����ѭ����ȳ�(LIFO)
	2����̬�洢��static�����ⶨ��
	3����̬�洢��new��delete������һ���ڴ��(���ɴ洢�ռ�free store���heap)��
		�ڴ�غ;�̬�������Զ��������ڴ��Ƿֿ��ģ�

	ʹ��vector,arrayҪ��������ռ�stdsʹ��,��using namespace std
*/
Practice_4::Practice_4() {
#if 0
	int nights = 1001;
	int * pt = new int;
	*pt = 1001;

	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;

	double * pd = new double;
	*pd = 100000001.0;
	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;

	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;

	cout << "size of pd = " << sizeof(pd);
	cout << ": size of *pd = " << sizeof(*pd) << endl;

	ArrayNew();
	StructNew();
#endif
	Choices();

}

/* ʹ��new������̬���� */
int Practice_4::ArrayNew() {
	double * p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p1[1] is " << p3[1] << ".\n";
	p3 = p3 + 1;
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 - 1;
	delete[] p3;
	return 0;
}

/* new������̬�ṹ�� */
int Practice_4::StructNew() {

	inflatable * ps = new inflatable;

	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);

	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume;

	cout << "Enter price: $";
	cin >> ps->price;

	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << " cubic feet \n";
	cout << "Price: $" << ps->price << endl;

	delete ps;

	return 0;
}

/* ���顢vector��array��ʹ�ñȽ� */
int Practice_4::Choices() {

	// C original C++
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };\

	// C++ STL
	vector<double> a2(4);
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	// C++11
	array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4> a4;

	a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	return 0;
}

Practice_4::~Practice_4() {

}