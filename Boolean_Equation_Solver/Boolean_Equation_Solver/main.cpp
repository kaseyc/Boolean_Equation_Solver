#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include "postfix.h"

using namespace std;

void error(string message); //Defined in utilities.h
void increment(map<char, bool> &variables);
void outputTable(string equation, map<char, bool> variables);

int main()
{
	string equation;
	int leftParen = 0, rightParen = 0;
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

	cout << endl << endl;

	outputTable(postfix, variables);

	return 0;
}

void increment(map<char, bool> &variables)
{
	//Increments the map as if the values formed a binary number
	//For example [(a,0),(b,1),(c,1)] becomes [(a,1),(b,0),(c,0)]
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

void outputTable(string equation, map<char, bool> variables)
{
	int numValues = pow(2.0, (int) variables.size()); //There are 2^n numbers in an n digit binary number (0-2^n -1)

	//Prints the table header
	map<char, bool>::iterator i;
	for (i = variables.begin(); i != variables.end(); i++)
	{
		printf("|  %c  ", i->first);
	}
	printf("|  %s  |\n", "Value");
	
	int tableWidth = 6*variables.size()+11;
	for(unsigned int i = 0; i < tableWidth; i++)
	{
		if (i%6 == 0 && i <= 6*variables.size())
			cout << "+";
		else if (i == tableWidth-1)
			cout << "+";
		else
			cout << "-";
	}
	cout << endl;

	//Prints the values
	for (unsigned int i = 0; i < numValues; i++)
	{
		map<char, bool>::iterator j;
		for (j = variables.begin(); j != variables.end(); j++)
		{
			printf("|  %d  ",j->second);
		}
		printf("|    %d    |\n", evaluateExpression(equation,variables));

		increment(variables);
	}
	
}