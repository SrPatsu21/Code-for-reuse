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