#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdio>
#include <map>
using namespace std;

class Expression
{
public:
	Expression(string infixEquation, string operators);

	void outputTable();

private:
	string postfixEquation;
	string validOperators;
	map<char, bool> variables;

	void increment(map<char, bool> &variables);
};

#endif