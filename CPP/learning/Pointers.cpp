#include <iostream>
using namespace std;

int main()
{
    string food = "Bread";
    string &meal = food;
    string * ptr = &food;

    //pointer has the adress
    cout << food << '\n';
    cout << meal << '\n';
    cout << ptr << '\n';
    //puting the * back again you can acess the information
    *ptr = "Pizza";

    cout << food << '\n';
    cout << *ptr << '\n';

    return 0;
}