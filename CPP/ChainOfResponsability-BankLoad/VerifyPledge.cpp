#include "VerifyPledge.hpp"


VerifyPledge::VerifyPledge()
{
}

VerifyPledge::~VerifyPledge()
{
}

int VerifyPledge::Loan(Bank* bank, int amount)
{
    return LoanHandlerBase::Loan(bank, amount);
};