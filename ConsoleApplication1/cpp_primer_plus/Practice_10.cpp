#include "Practice_10.h"

#include "practice_10/Stock.h"

#include <iostream>

/*
面向对象编程(OOP)
1、重要特性:
	① 抽象
	② 封装和数据隐藏
	③ 多态
	④ 继承
	⑤ 代码的可重用性
2、访问控制
	public
	private
	protected

抽象数据类型(ADT)


操作符的区别：
	箭头(->)：左边必须为指针
	点号(. )：左边必须为实体

*/

using namespace std;

Practice_10::Practice_10() {

#if 0
	
#endif

	UseStock();

}

int Practice_10::UseStock() {

	const int STKS = 4;

	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout << "Stock holding:\n";
	int st;
	for (st = 0; st < STKS; st++) {
		stocks[st].show();
	}
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++) {
		top = &top->topval(stocks[st]);
	}
	
	cout << "\nMost valuable holding:\n";
	top->show();

	return 0;
}

Practice_10::~Practice_10() {

}