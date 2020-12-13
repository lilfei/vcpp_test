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

/* 推断标识符的类型 */
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

/* 读取一下个标记到_this */
void gettoken(void) {
	char *p = _this.string;

	// 略过空白字符
	while ((*p = getchar()) == ' ');

	if (isalnum(*p)) {
		// 读入的标识符以A_Z,0-9开头
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

/* 理解所有分析过程的代码段 */
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

/* 代码分析 */
AnalysisCDeclare::AnalysisCDeclare() {
	// 将标记压入堆栈中，直到遇到标识符
	read_to_first_identifer();
	deal_with_declarator();
	cout << endl;
	return;
}

AnalysisCDeclare::~AnalysisCDeclare() {

}