#include <iostream>
using namespace std;

// sizeof give the size in bit  

int main()
{
    int x [3] = {1, 2, 3};
    int y [] = {1, 2, 3, 4};
    cout << sizeof(x);
    cout << '\n';
    cout << sizeof(y)/ sizeof(int);
    //Multi-Dimensional Arrays
    //you must set all dimentions after the frist
    int z [] [3] = {
                    {1, 3, 2},
                    {1, 2, 3}
                             }; 
    return 0;
}