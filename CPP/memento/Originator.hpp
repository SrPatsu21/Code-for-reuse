#include "ConcreteMemento.hpp"

class Originator {
 private:
  std::string state_;
  std::string GenerateRandomString(int length = 10);
 public:
  Originator(std::string state);

  void DoSomething();

  Memento *Save();
  void Restore(Memento *memento);
};

std::string Originator::GenerateRandomString(int length = 10) {
  const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
  int stringLength = sizeof(alphanum) - 1;

  std::string random_string;
  for (int i = 0; i < length; i++) {
    random_string += alphanum[std::rand() % stringLength];
  }
  return random_string;
}

Originator::Originator(std::string state) : state_(state) {
  std::cout << "Originator: My initial state is: " << this->state_ << "\n";
}

void Originator::DoSomething() {
    std::cout << "Originator: I'm doing something important.\n";
    this->state_ = this->GenerateRandomString(30);
    std::cout << "Originator: and my state has changed to: " << this->state_ << "\n";
  }

  Memento* Originator::Save() {
    return new ConcreteMemento(this->state_);
  }
  
  void Originator::Restore(Memento *memento)
  {
    this->state_ = memento->state();
    std::cout << "Originator: My state has changed to: " << this->state_ << "\n";
  }