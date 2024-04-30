#include "BaseDecorator.hpp"

BaseDecorator::BaseDecorator(PlayMusic* playm): PlayMusic()
{
        this->playm = playm;
}

BaseDecorator::~BaseDecorator()
{

}