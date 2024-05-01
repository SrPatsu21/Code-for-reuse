#ifndef VERIFYCASHDISPONIBILITY_HPP
#define VERIFYCASHDISPONIBILITY_HPP

#include "LoanHandlerBase.hpp"

class VerifyCashDisponibility : public LoanHandlerBase
{
public:
    VerifyCashDisponibility();
    ~VerifyCashDisponibility();
    virtual int Loan(Bank* bank, int amount);
};

#endif