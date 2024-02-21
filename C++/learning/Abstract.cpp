#include <iostream>
using namespace std;

//abstract
class AB {
    public:
    virtual void f() = 0;
};

//abstract
struct A {
  virtual void f() = 0;
};

//testiing 
struct B : A {
  virtual void f() {
    cout << "hello";
   }
};
struct C : AB {
  virtual void f() {
    cout << "hello";
   }
};

class D : AB
{
public:
    virtual void f() {
        cout << "hello";
    }
};
class E : A
{
public:
    virtual void f() {
        cout << "hello";
    }
};

//* block not null
A& i(A&);

int main() {

   A* pa;
   B b;
   C c;
   D d;
   E e;

    //won't work
    //pa->f();
    b.f();
    c.f();
    d.f();
    e.f();
}