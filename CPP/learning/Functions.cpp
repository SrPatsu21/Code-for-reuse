#include <iostream>
#include <cctype>
using namespace std;

void returnMessage(bool got) 
{
  cout << "I just got executed! " << got;
}

//this = 0 make this a default parameter
int Plus(int x = 0, int y = 0)
{
    int plus;
    plus = x + y;
    return plus;
};
//overloading function, same name, diferent parameters
//take care because um can`t set default parameters for all functions 
int Plus(float x, float y = 0.0)
{
    int plus;
    plus = x + y;
    return plus;
};
//Pass By Reference, make you able to change the variables inside the function
// you must not use default parameters here
void changeName(string &name)
{
    name = "Bella";
}
//Recursion functions call  it`s self
int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    cout << "work!";
    return 0;
  }
}



int main()
{
    string name = "Tom";

    returnMessage(false);
    cout << '\n';
    cout << Plus(1.2f);
    cout << '\n';

    changeName(name);
    cout << name;
    cout << '\n';

    sum(3);
    return 0;
}