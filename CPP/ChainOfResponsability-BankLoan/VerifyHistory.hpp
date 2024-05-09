#ifndef VERIFYHISTORY_HPP
#define VERIFYHISTORY_HPP

#include "LoanHandlerBase.hpp"

class VerifyHistory : public LoanHandlerBase
{
private:
public:
    VerifyHistory();
    ~VerifyHistory();
    virtual int Loan(Bank* bank, int amount);
};

#endif