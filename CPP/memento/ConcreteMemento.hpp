#ifndef CONCRETEMEMENTO_HPP
#define CONCRETEMEMENTO_HPP

#include "Memento.hpp"

class ConcreteMemento : public Memento {
 private:
  std::string state_;
  std::string date_;

 public:
    ConcreteMemento(std::string state);
    ~ConcreteMemento();
    std::string state() const override;
    std::string GetName() const override;
    std::string date() const override;
};

#endif