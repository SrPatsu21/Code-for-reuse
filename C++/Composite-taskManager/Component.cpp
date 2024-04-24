#include "Component.hpp"

Component::Component()
{

};

Component::~Component()
{

};

void Component::setTitle(std::string title)
{
    this->title = title;
};

std::string Component::getTitle()
{
    return title;
};

void Component::get()
{
    std::cout << "no open" << std::endl;
};

void Component::setType(Type type)
{
    this->type = type;
};

Type Component::getType()
{
    return type;
};