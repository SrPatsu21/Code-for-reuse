#include <iostream>
#include <string>
using namespace std;

//all of them work, by the first work better with pointers

// typedef struct USER
// {
//     int id;
//     string name;
// }USER;

struct USER{
  int id;
  string name;
};

//just inside the main/class
// struct {
//   int id;
//   string name;
// } USER;

int main() 
{
    USER user;
    user.id = 0;
    user.name = "Tom";
    cout << user.id << " : " <<user.name;
    return 0;
}