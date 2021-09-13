#include "Practice_5.h"
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

Practice_5::Practice_5() {

#if 0
	Express();
	TextIn4();
	CcTypes();
#endif
	OutFile();

}

/* <<����� �� �Ƚ���������ȼ��ߣ�����Ҫ��() */
int Practice_5::Express() {

	int x;

	cout << "The expression x = 100 has the value ";
	cout << (x = 100) << endl;
	cout << "Now x = " << x << endl;
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;

	cout.setf(ios_base::boolalpha); // ����cout��ǣ��ý����ʾΪ true/false
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;

	return 0;
}

/* win��Ctrl+Z���Enterʵ��EOF */
int Practice_5::TextIn4() {
	int ch;
	int count = 0;
	while ((ch = cin.get()) != EOF) {
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read.\n";
	return 0;
}

/*
	�ַ�������cctype
*/
int Practice_5::CcTypes() {

	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";

	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (ch != '@') {
		if (isalpha(ch)) {
			chars++;
		}
		else if (isspace(ch)) {
			whitespace++;
		}
		else if (isdigit(ch)) {
			digits++;
		}
		else if (ispunct(ch)) {
			punct++;
		}
		else {
			others++;
		}
		cin.get(ch);
	}

	cout << chars << " letters, "
		<< whitespace << " whitespace, "
		<< digits << " digits, "
		<< punct << " punctunations, "
		<< others << " others.\n";

	return 0;
}

/* 
	��Ҫʹ��fstreamͷ�ļ�
	ʹ�÷�����cout����һ��
*/
int Practice_5::OutFile() {

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");
	
	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the origianl asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	outFile.close();

	return 0;
}

Practice_5::~Practice_5() {

}