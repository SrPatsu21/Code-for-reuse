#ifndef LOANHANDLER_HPP
#define LOANHANDLER_HPP

#include <iostream>
#include "Bank.hpp"

class LoanHandler
{
public:
    virtual int Loan(Bank* bank, int amount) = 0;
    virtual LoanHandler* SetNext(LoanHandler *handler) = 0;
};

#endif