#include "VerifyHistory.hpp"

VerifyHistory::VerifyHistory()
:LoanHandlerBase()
{
}

VerifyHistory::~VerifyHistory()
{
}

int VerifyHistory::Loan(Bank* bank, int amount)
{
    return LoanHandlerBase::Loan(bank, amount);
};