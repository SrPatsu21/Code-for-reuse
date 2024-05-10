#ifndef CARETAKER_HPP
#define CARETAKER_HPP

#include <vector>
#include "Originator.hpp"
#include "Memento.hpp"

class Caretaker {
 private:

  std::vector<Memento *> mementos_;
  Originator *originator_;

 public:
  Caretaker(Originator* originator);
  ~Caretaker();

  void Backup();
  void Undo();
  void ShowHistory() const;
  
};

#endif