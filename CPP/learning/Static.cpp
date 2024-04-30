   
#include <iostream>
#include <string>
using namespace std;
 
void demo()
{
    // static variable
    static int count = 0;
    cout << count << " ";
 
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}
 
int main()
{
    for (int i = 0; i < 5; i++)
        demo();
    return 0;
}
/*
You can see in the above program that the variable count is declared static.
 So, its value is carried through the function calls.
  The variable count is not getting initialized every time the function is called.
*/