#include <iostream>
#include <string>
#include <fstream>
#include "expression.h"

using namespace std;

//Defined in utilities.h
////////////////////////////////////////////
void error(string message);
////////////////////////////////////////////

int main(int argc, char* argv[])
{
	string equation;
	string validOperators = "()!+*^";
	ofstream expressions;

	if (argc == 1)
	{
		cout << "Enter your equation: ";
		cin >> equation;
		cout << endl << endl;
	}

	else if (argc == 2)
	{
		//If only 1 argument is provided, it is the equation to be evaluated
		string arg(argv[1]);
		equation = arg;
	}

	else
	{
		
		for (int i = 1; i < argc; i++)
		{
			string arg(argv[i]);

			if (arg[0] == '-')
			{
				if (arg.find("f") != string::npos) //f is for a file with multiple equations, 1 per line
				{
					if (i+1 < argc)
					{
						string file(argv[i+1]);
						expressions.open(file);
					}
					else
					{
						error("Must provide a file");
					}
				}
			}
		}
	}

	Expression a(equation, validOperators);
	
	a.outputTable();

	return 0;
}

