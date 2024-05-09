#include "Bank.hpp"

Bank::Bank(int cash)
{
    this->cash = cash;
    this->aprov = true;
};

Bank::~Bank()
{

};

int Bank::getCash()
{
    return this->cash;
};
void Bank::setCash(int cash)
{
    this->cash = cash;
};
void Bank::removeCash(int cash)
{
    this->cash -= cash;
};

bool Bank::isAprov()
{
    return this->aprov;
};
void Bank::setAprov(bool boolop)
{
    this->aprov = boolop;
};