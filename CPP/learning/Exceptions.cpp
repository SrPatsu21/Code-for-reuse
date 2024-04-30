
#include <iostream>
using namespace std;

/*
The try statement allows you to define a block of code to be tested for errors while it is being executed.
The throw keyword throws an exception when a problem is detected, which lets us create a custom error.
The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.
*/

int main() {
  try {
    int age = 15;
    if (age >= 18) {
      cout << "Access granted - you are old enough.";
    } else {
      throw 505;
    }
  }
  catch (int err) {
    cout << "Access denied - You must be at least 18 years old.\n";
    cout << "Error number: " << err;  
  }
  return 0;
}
