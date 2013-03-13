v1.0
_____
This program takes a boolean expression in infix notation and outputs the results as a formatted truth table. 

[Screenshot](http://imgur.com/sdvYtNG)

Uses single letters as variables. It is case sensitive, so up to 52 all together.
Supports the following operators:

	OR: +
	
	NOT: !
	
	AND: *
	
	XOR: ^
	
	Potentially more

Will error out if the equation contains anything other than letters, supported operators, and parentheses.

Supports implicit multiplication of variables (e.g. ab -> a*b, a!b -> a*!b)

Order of operations(High to low): NOT, AND, XOR, OR.
____

Usage:

Just compile the files and run. Uses only standard libraries.

The Visual Studio project file is included if you like.
____

Future Plans:

1. Command line arguments

2. K-maps

3. Config file to customize operator characters (e.g. use ~ for NOT instead of !)

4. Generate expression from formatted input (maybe)
