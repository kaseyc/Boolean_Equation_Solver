#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using namespace std;

void error(string message)
{
	cerr << "Error: " << message << endl;
	exit(1);
}

int precedence(char c)
{
	int precedence;
	switch (c)
	{
	case '(':
		precedence = 1;
		break;
	case '+':
		precedence = 2;
		break;
	case '^':
		precedence = 3;
		break;
	case '*':
		precedence = 4;
		break;
	case '!':
		precedence = 5;
		break;
	default:
		precedence = -1;
		break;
	}

	return precedence;
}
#endif