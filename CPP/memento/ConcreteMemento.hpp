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

ConcreteMemento::ConcreteMemento(std::string state) : state_(state)
{
    this->state_ = state;
    this->date_ = std::time(0);
};

ConcreteMemento::~ConcreteMemento()
{

};

std::string ConcreteMemento::state()  const
{
    return this->state_;
};

std::string ConcreteMemento::GetName()  const
{
    return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
};

std::string ConcreteMemento::date() const
{
    return this->date_;
};

#endif