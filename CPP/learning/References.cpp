#include <iostream>
using namespace std;

int main()
{
    string food = "Bread";
    //making like this, u save the memory location of food inside the meal, because meal is a reference variable.
    string &meal = food;
    //alterating meal you alterat food too
    meal = "Pizza";

    cout << food << '\n';
    cout << meal << '\n';
    //being a reference variable mean has same adress
    cout << &food << '\n';
    cout << &meal << '\n';

    return 0;
}