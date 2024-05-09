#ifndef VERIFYRENT_HPP
#define VERIFYRENT_HPP

#include "LoanHandlerBase.hpp"

class VerifyRent: public LoanHandlerBase
{
public:
    VerifyRent();
    ~VerifyRent();
    virtual int Loan(Bank* bank, int amount);
};

#endif