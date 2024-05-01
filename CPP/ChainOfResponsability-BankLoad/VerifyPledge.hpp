#ifndef VERIFYPLEDGE_HPP
#define VERIFYPLEDGE_HPP

#include "LoanHandlerBase.hpp"

class VerifyPledge : public LoanHandlerBase
{
public:
    VerifyPledge();
    ~VerifyPledge();
    virtual int Loan(Bank* bank, int amount);
};

#endif