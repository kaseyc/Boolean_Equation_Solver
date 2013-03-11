#include <iostream>
#include <string>
#include <ctype.h>
#include "postfix.h"

using namespace std;

int main()
{
	string equation;
	int leftParen = 0, rightParen = 0;
	string variables = "";
	string valid_operators = "()!+*^";
	cout << "Enter your equation: ";
	cin >> equation;

	//Makes sure that the equation is valid: contains only variables (letters) and valid operators and checks that
	for (unsigned int i = 0; i < equation.length(); i++)
	{
		if (isalpha(equation[i]) && variables.find(equation[i]) == string::npos)
			variables += equation[i];

		else if (!isalpha(equation[i]) && valid_operators.find(equation[i]) == string::npos)
		{
			error("Equations must contain only alphabetic variables and operators");
		}
	}

	string postfix = infixToPostfix(equation);
	cout << "Your equation is: " << equation << endl;
	cout << "Your postfix espression is: " << postfix << endl;
	cout << "Your variables are: " << variables << endl;

	map<char, bool> test;
	test['a'] = 1;
	test['b'] = 1;
	test['c'] = 0;
	test['d'] = 0;

	cout << evaluateExpression(postfix, test) << endl;
	return 0;
}