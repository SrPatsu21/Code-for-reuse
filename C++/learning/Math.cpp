#include <iostream>
using namespace std;

/*
+	Adds

–	Subtracts

*   Multiplication

/	Divides	

%   Modulo Operation

++ Increment Operator
-- Decrement Operator

The & (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.  
The | (bitwise OR) in C takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. 
The ^ (bitwise XOR) in C takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. 
The << (left shift) in C takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift. 
The >> (right shift) in C takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift. 
The ~ (bitwise NOT) in C takes one number and inverts all bits of it.
*/

/*
#include <cmath>
Function	Description
abs(x)	Returns the absolute value of x
acos(x)	Returns the arccosine of x
asin(x)	Returns the arcsine of x
atan(x)	Returns the arctangent of x
cbrt(x)	Returns the cube root of x
ceil(x)	Returns the value of x rounded up to its nearest integer
cos(x)	Returns the cosine of x
cosh(x)	Returns the hyperbolic cosine of x
exp(x)	Returns the value of Ex
expm1(x)	Returns ex -1
fabs(x)	Returns the absolute value of a floating x
fdim(x, y)	Returns the positive difference between x and y
floor(x)	Returns the value of x rounded down to its nearest integer
hypot(x, y)	Returns sqrt(x2 +y2) without intermediate overflow or underflow
fma(x, y, z)	Returns x*y+z without losing precision
fmax(x, y)	Returns the highest value of a floating x and y
fmin(x, y)	Returns the lowest value of a floating x and y
fmod(x, y)	Returns the floating point remainder of x/y
pow(x, y)	Returns the value of x to the power of y
sin(x)	Returns the sine of x (x is in radians)
sinh(x)	Returns the hyperbolic sine of a double value
tan(x)	Returns the tangent of an angle
tanh(x)	Returns the hyperbolic tangent of a double value
*/

/*
A floating point number can also be a scientific number with an "e" to indicate the power of 10:
    float x = 2e3;
    same as 2*10^3
    x = 2000
*/

int main()
{
    float x = 2e3;
    cout << x;
    return 0;
}