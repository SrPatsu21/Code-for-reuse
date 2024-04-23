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
    void setTitle(std::string title);
    virtual std::string getTitle();
};

Component::Component()
{

}

Component::~Component()
{

}

void Component::setTitle(std::string title)
{
    this->title = title;
};

std::string Component::getTitle()
{
    return title;
};

#endif