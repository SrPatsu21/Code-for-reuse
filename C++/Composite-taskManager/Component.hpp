#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <list>

enum Type { ISSUE = 1, COMPOSITEISSUE = 2, NONE = 0};

class Component
{
private:
    std::string title;
    Type type = Type::NONE;
protected:
public:
    Component();
    ~Component();
    virtual void setTitle(std::string title);
    virtual std::string getTitle();
    virtual void get();
    void setType(Type type);
    Type getType();
};

#endif