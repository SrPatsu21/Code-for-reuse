#ifndef ISSUE_HPP
#define ISSUE_HPP

#include <iostream>
#include "Component.hpp"


class Issue : public Component
{
private:
    std::string title;
    std::string description;
    std::string deadline;

public:
    Issue(std::string title);
    Issue(std::string title, std::string description, std::string deadline);
    ~Issue();

    void setDescription(std::string description);
    std::string getDescription();
    void setDeadline(std::string deadline);
    std::string getDeadline();
    void get();
};

#endif