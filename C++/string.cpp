#include <iostream>
#include <string>
using namespace std;

//string is an object like in Java
//.append() or + to concatenation
/*
\'	Single quote
\"	Double quote
\\	Backslash
\t  Tab
\n  New Line
*/
int main()
{
    string line1 = "seu ov";
    string line2 = "o";
    cout << line1 + line2;
    cout << '\n';
    cout << line1.append(line2);//in this case line1 will be = line1+line2
    cout << '\n';
    cout << line1.length();
    cout << line1.size();
    cout << '\n';
    cout << line1[1];
    return 0;
}