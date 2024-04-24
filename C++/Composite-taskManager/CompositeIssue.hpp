#ifndef COMPOSITEISSUE_HPP
#define COMPOSITEISSUE_HPP

#include "Component.hpp"

class CompositeIssue : public Component
{
private:
    std::list<Component> ls;
public:
    CompositeIssue(std::string title);
    ~CompositeIssue();
    void add(Component newOne);
    void remove();
    Component get();
};

#endif