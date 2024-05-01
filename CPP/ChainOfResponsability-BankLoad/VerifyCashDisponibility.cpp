#include "VerifyCashDisponibility.hpp"

VerifyCashDisponibility::VerifyCashDisponibility()
: LoanHandlerBase()
{

}

VerifyCashDisponibility::~VerifyCashDisponibility()
{

}

int VerifyCashDisponibility::Loan(Bank* bank, int amount)
{
    if (bank->getCash() <  amount)
    {
        bank->setAprov(false);
    }
    
    return LoanHandlerBase::Loan(bank, amount);
};