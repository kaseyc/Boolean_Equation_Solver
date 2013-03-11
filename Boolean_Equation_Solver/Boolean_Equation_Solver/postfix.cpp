#include "postfix.h"
#include <stack>

string infixToPostfix(string infixString)
{
	stack<char> operators;
	string postfix = "";

	for (unsigned int i = 0; i < infixString.length(); i++)
	{
		if (isalpha(infixString[i]))
		{
			postfix += infixString[i];

			//Inserts a * operator into a sequence of two variables, or a variable or a negation.
			//This allows for implicit multiplication (ab becomes a*b, a!b becomes a*!b)
			if ((i+1) < infixString.length() && (isalpha(infixString[i+1]) || infixString[i+1] == '!'))
			{
				infixString.insert((i+1), "*");
			}
		}

		else if (operators.empty() /*&& infixString[i] != ')'*/)
		{
			operators.push(infixString[i]);
		}

		else
		{
			switch (infixString[i])
			{
			case '(':
					operators.push(infixString[i]);
					break;

			case ')':
				if (!operators.empty())
				{
					while (operators.top() != '(')
					{
						postfix += operators.top();
						operators.pop();

						if (operators.empty())
						{
							error("Mismatched Parentheses");
						}
					}
					operators.pop();
				}

				else
					error("Mismatched Parentheses");

				break;

			default:
				while (!operators.empty() && (precedence(infixString[i]) < precedence(operators.top())))
				{
					postfix += operators.top();
					operators.pop();
				}
				operators.push(infixString[i]);
				break;
			}
		}
	}

	while (!operators.empty())
	{
		if (operators.top() == '(' || operators.top() == ')')
		{
			error("Mismatched Parentheses");
		}

		postfix += operators.top();
		operators.pop();
	}

	return postfix;
}


int evaluateExpression(string postfixString, map<char, bool> &values)
{
	int result = -1;
	int var1, var2;
	stack<int> operands;

	for(unsigned int i = 0; i < postfixString.length(); i++)
	{
		if (isalpha(postfixString[i]))
		{
			var1 = (bool) values[postfixString[i]];
			operands.push(var1);
		}

		else if (postfixString[i] == '!')
		{
			var1 = operands.top();
			operands.pop();

			operands.push(!var1);
		}

		else 
		{
			switch (postfixString[i])
			{
			case '+':
				var1 = operands.top();
				operands.pop();

				var2 = operands.top();
				operands.pop();

				operands.push(var1 || var2);
				break;

			case '*': 
				var1 = operands.top();
				operands.pop();

				var2 = operands.top();
				operands.pop();

				operands.push(var1 && var2);
				break;

			case '^':
				var1 = operands.top();
				operands.pop();

				var2 = operands.top();
				operands.pop();

				operands.push(var1 ^ var2);
				break;
			}
		}
	}

	return operands.top();
}