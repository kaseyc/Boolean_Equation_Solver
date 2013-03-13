#ifndef POSTFIX_H
#define POSTFIX_H

#include <string>
#include <map>

using namespace std;

//Converts an infix string to a postfix string
string infixToPostfix(string infixString);

//Takes an equation in postfix notation and a map of variables to values, and returns the result of the expression
//evaluated for that set of values
int evaluateExpression(string postfixString, map<char, bool> &values);

#endif