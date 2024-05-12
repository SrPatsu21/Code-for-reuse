#include <iostream>
#include "Caretaker.hpp"
#include "Originator.hpp"

int main() {
  //start time
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  //done
  Originator *originator = new Originator("Super-duper-super-puper-super.");
  Caretaker *caretaker = new Caretaker(originator);
  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();
  std::cout << "\n";

  //undone
  caretaker->ShowHistory();
  std::cout << "\nClient: Now, let's rollback!\n\n";
  caretaker->Undo();
  std::cout << "\nClient: Once more!\n\n";
  caretaker->Undo();
  std::cout << "\nClient: Once more!\n\n";
  caretaker->Undo();
  std::cout << std::endl;

  delete originator;
  delete caretaker;

  return 0;
}