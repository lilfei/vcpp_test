#include "../pch.h"
#include <iostream>
#include <memory>

using namespace std;

int ClassTest::totalParticipants = 333;

// �����쿪ʼ
ClassTest::ClassTest(int players):players(players)
{
	totalParticipants += players;
	cout << players << " ClassTest haha " << totalParticipants << "��" << endl;
};

// ���������
ClassTest::~ClassTest()
{
	totalParticipants -= players;
	cout << players << " ClassTest haha finished " << totalParticipants << "��" << endl;
}