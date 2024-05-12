#include "Caretaker.hpp"


  Caretaker::Caretaker(Originator* originator) 
  : originator_(originator) 
  {
  };

  Caretaker::~Caretaker() 
  {
      for (auto m : mementos_) delete m;
  };

  void Caretaker::Backup() 
  {
    std::cout << "\nCaretaker: Saving Originator's state...\n";
    this->mementos_.push_back(this->originator_->Save());
  };

  void Caretaker::Undo() 
  {
    if (!this->mementos_.size()) 
    {
      return;
    }
    Memento *memento = this->mementos_.back();
    this->mementos_.pop_back();
    std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";
    try 
    {
      this->originator_->Restore(memento);
    } catch (...) 
    {
      this->Undo();
    }
  };

  void Caretaker::ShowHistory() const 
  {
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for (Memento *memento : this->mementos_) 
    {
      std::cout << memento->GetName() << "\n";
    }
  };