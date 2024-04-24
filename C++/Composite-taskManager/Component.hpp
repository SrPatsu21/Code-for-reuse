#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <list>
#include "CompositeIssue.hpp"


class Component
{
private:
    std::string title;
    CompositeIssue composite = CompositeIssue("root");
protected:
    Component();
public:
    ~Component();
    virtual void setTitle(std::string title);
    virtual std::string getTitle();
    virtual Component get();
};

#endif