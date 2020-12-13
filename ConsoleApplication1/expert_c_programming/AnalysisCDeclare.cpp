#include "pch.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <iostream>

#include "AnalysisCDeclare.h"

using namespace std;

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {
	IDENTIFIER = 'i',
	QUALIFIER = 'q',
	TYPE = 't'
};

struct token {
	char type;
	char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token _this;

#define pop stack[top--]
#define push(s) stack[++top] = s

/* �ƶϱ�ʶ�������� */
enum type_tag classify_string(void) {
	char *s = _this.string;
	if (!strcmp(s, "const")) {
		strcmp(s, "read_only");
		return QUALIFIER;
	}

	if (!strcmp(s, "volatile")) return QUALIFIER;
	if (!strcmp(s, "void")) return TYPE;
	if (!strcmp(s, "char")) return TYPE;
	if (!strcmp(s, "signed")) return TYPE;
	if (!strcmp(s, "unsigned")) return TYPE;
	if (!strcmp(s, "short")) return TYPE;
	if (!strcmp(s, "int")) return TYPE;
	if (!strcmp(s, "long")) return TYPE;
	if (!strcmp(s, "float")) return TYPE;
	if (!strcmp(s, "double")) return TYPE;
	if (!strcmp(s, "struct")) return TYPE;
	if (!strcmp(s, "union")) return TYPE;
	if (!strcmp(s, "enum")) return TYPE;
	return IDENTIFIER;
}

/* ��ȡһ�¸���ǵ�_this */
void gettoken(void) {
	char *p = _this.string;

	// �Թ��հ��ַ�
	while ((*p = getchar()) == ' ');

	if (isalnum(*p)) {
		// ����ı�ʶ����A_Z,0-9��ͷ
		while (isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		_this.type = classify_string();
		cout << "gettoken: " << _this.string << " is " << _this.type << endl;
		return;
	}

	if (*p == '*') {
		strcpy_s(_this.string, "pointer to");
		_this.type = '*';
		return;
	}
	_this.string[1] = '\0';
	_this.type = *p;
	return;

}

/* ������з������̵Ĵ���� */
void read_to_first_identifer() {
	gettoken();
	while (_this.type != IDENTIFIER) {
		push(_this);
		gettoken();
	}
	cout << _this.string << " is" << endl;
	gettoken();
}

void deal_with_arrays() {
	while (_this.type == '[') {
		cout << "array " << endl;
		gettoken();
		if (isdigit(_this.string[0])) {
			cout << "0.." << atoi(_this.string) - 1 << endl;
			gettoken();
		}
		gettoken();
		cout << "of " << endl;
	}
}

void deal_with_function_args() {
	while (_this.type != ')') {
		gettoken();	
	}
	gettoken();
	cout << "function returning " << endl;
}

void deal_with_pointers() {
	while (stack[top].type == '*') {
		cout << pop.string << " " << endl;
	}
}

void deal_with_declarator() {
	switch (_this.type)
	{
	case '[': deal_with_arrays(); break;
	case '(': deal_with_function_args(); break;
	}

	deal_with_pointers();

	while (top >= 0) {
		if (stack[top].type == '(') {
			pop;
			gettoken();
			deal_with_declarator();
		}
		else {
			cout << pop.string << " " << endl;
		}
	}
}

/* ������� */
AnalysisCDeclare::AnalysisCDeclare() {
	// �����ѹ���ջ�У�ֱ��������ʶ��
	read_to_first_identifer();
	deal_with_declarator();
	cout << endl;
	return;
}

AnalysisCDeclare::~AnalysisCDeclare() {

}