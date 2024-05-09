#ifndef LOANHANDLERBASE_HPP
#define LOANHANDLERBASE_HPP

#include "LoanHandler.hpp"

class LoanHandlerBase : public LoanHandler
{
private:
    LoanHandler *next_handler;

protected:
    LoanHandlerBase();

public:  
    virtual int Loan(Bank* bank, int amount);
    virtual LoanHandler* SetNext(LoanHandler *handler);
};

#endif