#include "Issue.hpp"

Issue::Issue(std::string title)
{
    setTitle(title);
    setType(Type::ISSUE);
};

Issue::Issue(std::string title, std::string description, std::string deadline)
{
    setTitle(title);
    setDescription(description);
    setDeadline(deadline);
    setType(Type::ISSUE);
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
    std::cout << "file description:" << std::endl << "\t" << getDescription() << std::endl;
};