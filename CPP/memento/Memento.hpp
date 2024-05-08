#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <iostream>
#include <ctime>

class Memento 
{
 public:
  virtual ~Memento() {}
  virtual std::string GetName() const = 0;
  virtual std::string date() const = 0;
  virtual std::string state() const = 0;
};

#endif