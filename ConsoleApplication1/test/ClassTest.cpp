#include "../pch.h"
#include <iostream>
#include <memory>

using namespace std;

int ClassTest::totalParticipants = 333;

// 程序构造开始
ClassTest::ClassTest(int players):players(players)
{
	totalParticipants += players;
	cout << players << " ClassTest haha " << totalParticipants << "。" << endl;
};

// 程序构造结束
ClassTest::~ClassTest()
{
	totalParticipants -= players;
	cout << players << " ClassTest haha finished " << totalParticipants << "。" << endl;
}