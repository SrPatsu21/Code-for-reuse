#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <list>

class Component
{
private:
    std::string title;
protected:
public:
    Component();
    ~Component();
    virtual void setTitle(std::string title);
    virtual std::string getTitle();
    virtual void get();
};

#endif