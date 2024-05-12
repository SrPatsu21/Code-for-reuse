#ifndef ORIGINATOR_HPP
#define ORIGINATOR_HPP

#include "ConcreteMemento.hpp"

class Originator {
 private:
  std::string state_;
  std::string GenerateRandomString(int length);
 public:
  Originator(std::string state);

  void DoSomething();

  Memento *Save();
  void Restore(Memento *memento);
};

#endif