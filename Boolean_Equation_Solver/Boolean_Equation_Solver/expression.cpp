#include <cctype>
#include <iostream>
#include "expression.h"
#include "postfix.h"

void error(string message);

Expression::Expression(string infixEquation, string operators)
{
	validOperators = operators;

	//Makes sure that the equation is valid: contains only variables (letters) and valid operators and adds variables to the map as they are found
	//All variables are assigned 0, so the map is initialized to the value 0
	for (unsigned int i = 0; i < infixEquation.length(); i++)
	{
		if (isalpha(infixEquation[i]))
			variables[infixEquation[i]] = 0;

		else if (validOperators.find(infixEquation[i]) == string::npos)
			error("Equations must contain only alphabetic variables and operators");
	}

	postfixEquation = infixToPostfix(infixEquation);
}

void Expression::outputTable()
{
	int numValues = pow(2.0, (int) variables.size()); //There are 2^n numbers in an n digit binary number (0-2^n -1)

	//Prints the table header
	map<char, bool>::iterator i;
	for (i = variables.begin(); i != variables.end(); i++)
	{
		printf("| %c ", i->first);
	}
	printf("| %s |\n", "Value");
	
	int tableWidth = 4*variables.size()+9;
	for(unsigned int i = 0; i < tableWidth; i++)
	{
		if (i%4 == 0 && i <= 4*variables.size())
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
			printf("| %d ",j->second);
		}
		printf("|   %d   |\n", evaluateExpression(postfixEquation,variables));

		increment(variables);
	}
}

void Expression::updateEquation(string infixEquation)
{
	postfixEquation = "";
	variables.clear();

	for (unsigned int i = 0; i < infixEquation.length(); i++)
	{
		if (isalpha(infixEquation[i]))
			variables[infixEquation[i]] = 0;

		else if (validOperators.find(infixEquation[i]) == string::npos)
			error("Equations must contain only alphabetic variables and operators");
	}

	postfixEquation = infixToPostfix(infixEquation);
}

void Expression::increment(map<char, bool> &variables)
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
			i->second = 0;
	}
	return;
}