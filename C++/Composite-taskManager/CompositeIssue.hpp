#ifndef COMPOSITEISSUE_HPP
#define COMPOSITEISSUE_HPP

#include "Component.hpp"

class CompositeIssue : public Component
{
private:
    std::list<Component> ls;
public:
    CompositeIssue();
    CompositeIssue(std::string title);
    ~CompositeIssue();
    void add(Component newOne);
    void remove();
    Component get(int index);
};
CompositeIssue::CompositeIssue(std::string title)
{
    setTitle(title);
};


CompositeIssue::~CompositeIssue()
{

};

void CompositeIssue::add(Component newOne)
{
    ls.insert(ls.end(), newOne);
};
void CompositeIssue::remove()
{
    ls.pop_back();
};

Component CompositeIssue::get(int index)
{
    return CompositeIssue();
}

#endif