#include <iostream>
using namespace std;

/*
public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.
*/

class Car
{
    public:
    int sing;
    string name;

    //costructors
    Car()
    {

    }
    Car(int sing, string name)
    {
        this->sing = sing;
        this->name = name;
    }

    //methods
    void breakLine()
    {
        cout << '\n';
    }
};
class OtherClass
{
    public:
    void breakLine()
    {
        cout << '\n';
    }
};

//Inheritance, u can add as much you want
class SportCar : public Car, public OtherClass{
    public:
    SportCar (int sing, string name)
    {
        this->sing = sing;
        this->name = name;
    }
};

int main()
{
    SportCar sportcar(33, "hpcv");
    Car car1(123, "nome");
    car1.sing = 1230;
    car1.name = "Onix";

    cout << car1.name;
    car1.breakLine();
    cout << car1.sing;
    car1.breakLine();

    cout << sportcar.name;
    sportcar.OtherClass::breakLine();
    cout << sportcar.sing;
    sportcar.Car::breakLine();
}