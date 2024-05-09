#include "LoanHandlerBase.hpp"

LoanHandlerBase::LoanHandlerBase()
{
  this->next_handler = NULL;
}

int LoanHandlerBase::Loan(Bank* bank, int amount)
{
    if (this->next_handler != NULL) {
      return this->next_handler->Loan(bank, amount);
    }

    return 1;
};
LoanHandler* LoanHandlerBase::SetNext(LoanHandler *handler)
{
    this->next_handler = handler;
    return handler;
};