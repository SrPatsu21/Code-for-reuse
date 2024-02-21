#include <iostream>
#include <string>
using namespace std;

/*
    cin — for standard input
    cout — for standard output
    cerr — for unbuffered standard error output
    clog — for buffered standard error output
*/

//string is an object like in Java
//.append() or + to concatenation
/*
\'	Single quote
\"	Double quote
\\	Backslash
\t  Tab
\n  New Line
*/

// [n], n=number, to acess any position of string/array of char

/*
.size and .length can be use to know the zise of the string
*/
int main()
{
    string line1 = "Hello Wor";
    string line2 = "ld";
    int x;

    //input
    cout << "send an int number:";
    cin >> x;
    cout << "this is your number:" << x;
    cout << '\n';
    //others

    cout << line1 + line2;
    cout << '\n';
    cout << line1.append(line2);//in this case line1 will be = line1+line2
    cout << '\n';
        //the line1 has the line2 inside too
    cout << line1.length();
    cout << '\n';
    cout << line1.size();
    cout << '\n';
    cout << line1[1];
    return 0;
}