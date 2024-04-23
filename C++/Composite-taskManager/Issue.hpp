#ifndef ISSUE_HPP
#define ISSUE_HPP

#include <iostream>

class Issue
{
private:
    std::string title;
    std::string description;
    std::string deadline;

public:
    Issue();
    Issue(std::string title, std::string description, std::string deadline);
    ~Issue();
};

Issue::Issue()
{

};

Issue::Issue(std::string title, std::string description, std::string deadline)
{
    
};

Issue::~Issue()
{

};

#endif