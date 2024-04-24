#include "CompositeIssue.hpp"

CompositeIssue::CompositeIssue(std::string title)
{
    setTitle(title);
};

CompositeIssue::~CompositeIssue()
{

};

void CompositeIssue::add(Component newOne)
{
    ls.push_back(newOne);
};
void CompositeIssue::remove()
{
    ls.pop_back();
};

Component CompositeIssue::get()
{
    std::list<Component>::iterator it = ls.begin(); 
    (*it).setTitle('\t'+(*it).getTitle());
    return  *it;
}