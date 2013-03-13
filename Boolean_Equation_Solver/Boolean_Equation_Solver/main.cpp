#include <iostream>
#include <string>
#include <ctype.h>
#include "postfix.h"

using namespace std;

void increment(map<char, bool> &variables);

int main()
{
	string equation;
	int leftParen = 0, rightParen = 0, numValues = 0;
	map<char, bool> variables;
	string valid_operators = "()!+*^";
	cout << "Enter your equation: ";
	cin >> equation;

	//Makes sure that the equation is valid: contains only variables (letters) and valid operators and adds variables to the map as they are found
	//All variables are assigned 0, so the map is initialized to the value 0
	for (unsigned int i = 0; i < equation.length(); i++)
	{
		if (isalpha(equation[i]))
		{
			variables[equation[i]] = 0;
		}

		else if (valid_operators.find(equation[i]) == string::npos)
		{
			error("Equations must contain only alphabetic variables and operators");
		}
	}

	string postfix = infixToPostfix(equation);

	numValues = pow(2.0, (int) variables.size()); //There are 2^n numbers in an n digit binary number (0-2^n -1)

	cout << "Your equation is: " << equation << endl;
	cout << "Your postfix expression is: " << postfix << endl;

	for (int i = 0; i < numValues; i++)
	{
		map<char, bool>::iterator j;
		for (j = variables.begin(); j != variables.end(); j++)
			cout << j->second;

		cout << endl;
		increment(variables);
	}

	return 0;
}

void increment(map<char, bool> &variables)
{
	map<char, bool>::reverse_iterator i; 
	for (i = variables.rbegin(); i != variables.rend(); i++)
	{
		if (i->second == 0)
		{
			i->second = 1;
			return;
		}

		else
		{
			i->second = 0;
		}
	}
	cout << endl;
	return;
}