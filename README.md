This program takes a boolean expression in infix notation and evaluates it. In the future, I plan to make it output K-maps and truth tables, as well as take command line arguments. I also plan on attempting to add in a function to take a truth table and output an expression using sum of products or product of sums.

Currently: 

Uses single letters as variables. It is case sensitive, so up to 52 all together.
Supports the following operators:
	OR: +
	NOT: !
	AND: *
	XOR: ^
	I may add more in the future

Will error out if the equation contains anything other than letters, supported operators, and parentheses.
Supports implicit multiplication of variables (e.g. ab -> a*b, a!b -> a*!b)

Order of operations(High to low): NOT, AND, XOR, OR.
