#include "VerifyRent.hpp"

VerifyRent::VerifyRent()
: LoanHandlerBase()
{
}

VerifyRent::~VerifyRent()
{
}

int VerifyRent::Loan(Bank* bank, int amount)
{
    return LoanHandlerBase::Loan(bank, amount);
};