#include "../pch.h"
#include <iostream>
#include "EnumTest.h"

using namespace std;

namespace ScopedEnumConversions
{
	enum class Suit { Diamonds, Hearts, Clubs, Spades };

	void AttemptConversions()
	{
		Suit hand;
		
		// hand = Clubs; // error C2065: 'Clubs' : undeclared identifier
		hand = Suit::Clubs; //Correct.
		int account_num = 135692;
		
		// hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'
		hand = static_cast<Suit>(account_num); // OK, but probably a bug!!!

		// account_num = Suit::Hearts; // error C2440: '=' : cannot convert from 'Suit' to 'int'
		account_num = static_cast<int>(Suit::Hearts); // OK
	}

	// below is test
	//enum class byte : unsigned char { };

	//enum class E : int { };
	//E e1{ 0 };
	//E e2 = E{ 0 };

	//struct X
	//{
	//	E e{ 0 };
	//	X() : e{ 0 } { }
	//};

	//E* p = new E{ 0 };

	//void f(E e) {};

}

struct Days
{
	const static int Sat = 1;
	const static int Sun = 2;
	const static int Mon = 3;
	const static int Tue = 4;
	const static int Wed = 5;
	const static int Thu = 6;
	const static int Fri = 7;
};

struct Planets
{
	const static int Moon = 0;
	const static int Earth = 1;
	const static int Sun = 1;
};

EnumTest::EnumTest()
{	
}

EnumTest::~EnumTest()
{
}
