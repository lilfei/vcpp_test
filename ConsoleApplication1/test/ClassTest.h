// ������ͷ�ļ�
#pragma once
class ClassTest
{
	int players;
	static int totalParticipants;
public:
	ClassTest(int players);
	~ClassTest();
	static int getPraticPants() {
		return totalParticipants;
	}
};
