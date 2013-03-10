#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	string equation;
	string variables = "";
	string valid_operators = "()!+*^";
	cout << "Enter your equation: " << endl;
	cin >> equation;

	for (unsigned int i = 0; i < equation.length(); i++)
	{
		if (isalpha(equation[i]) && variables.find(equation[i]) == string::npos)
			variables += equation[i];

		else if (!isalpha(equation[i]) && valid_operators.find(equation[i]) == string::npos)
		{
			cout << "Equations must contain only alphabetic variables and operators" << endl;
			exit(1);
		}
	}

	cout << "Your equation is: " << equation << endl;
	cout << "Your variables are: " << variables << endl;

	return 0;
}