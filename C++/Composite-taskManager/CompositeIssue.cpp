#include "CompositeIssue.hpp"

CompositeIssue::CompositeIssue(std::string title)
{
    setTitle(title);
};

CompositeIssue::~CompositeIssue()
{

};

void CompositeIssue::add(Component* newOne)
{
    ls.push_back(newOne);
};
void CompositeIssue::remove()
{
    ls.pop_back();
};

void CompositeIssue::get()
{
    for (size_t i = 0; i < ls.size(); i++)
    {
        std::list<Component*>::iterator it = ls.begin();
        std::advance(it, i);
        std::cout << ((Component*)(*it))->getTitle() << ":" << std::endl;
        std::cout << "/*" << std::endl;
        (*it)->get();
        std::cout << "*/" << std::endl;    
    }
}