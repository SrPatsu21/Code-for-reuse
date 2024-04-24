#include "Issue.hpp"

Issue::Issue(std::string title)
{
    setTitle(title);
};

Issue::Issue(std::string title, std::string description, std::string deadline)
{
    setTitle(title);
    setDescription(description);
    setDeadline(deadline);
};

Issue::~Issue()
{

};

void Issue::setDescription(std::string description)
{
    this->description = description;
};

std::string Issue::getDescription()
{
    return this->description;
};

void Issue::setDeadline(std::string deadline)
{
    this->deadline = deadline;
};

std::string Issue::getDeadline()
{
    return this->deadline;
};

void Issue::get()
{
    std::cout << getDescription() << std::endl;
};