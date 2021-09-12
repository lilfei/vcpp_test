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
	使用new分配内存，如果内存不足，则返回0，即空指针
	使用delete释放内存(对空指针有效),使用方法如下:
	int * ps = new int;
	...
	delete ps;

	数组同理:
	int * psome = new int [10];
	...
	delete [] psome;

	使用 new 和 delete 应遵守以下规则：
	1、不能使用 delete 释放不是 new 分配的内存
	2、不能使用 delete 释放同一块内存两次
	3、如果使用 new []为数组分配内存，应使用 delete []释放内存
	4、如果使用 new 为实体分配内存，应使用 delete (没有方括号)来释放
	5、可以对空指针使用delete

	C++内存管理方式为3种：
	1、自动存储：通常遵循后进先出(LIFO)
	2、静态存储：static或函数外定义
	3、动态存储：new、delete，管理一个内存池(自由存储空间free store或堆heap)，
		内存池和静态变量、自动变量的内存是分开的，

	使用vector,array要配合命名空间stds使用,即using namespace std
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

/* 使用new创建动态数组 */
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

/* new创建动态结构体 */
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

/* 数组、vector、array的使用比较 */
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