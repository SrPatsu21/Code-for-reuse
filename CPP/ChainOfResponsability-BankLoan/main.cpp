#include "Bank.hpp"
#include "VerifyCashDisponibility.hpp"
#include "VerifyHistory.hpp"
#include "VerifyPledge.hpp"
#include "VerifyRent.hpp"

int main(void)
{
    Bank * bank = new Bank(120);
    VerifyCashDisponibility* verifycash = new VerifyCashDisponibility();
    VerifyRent* verifyrent = new VerifyRent();
    VerifyHistory* verifyhistory = new VerifyHistory();
    VerifyPledge* verifypledge = new VerifyPledge();
    //chaining
    verifycash->SetNext(verifyrent)->SetNext(verifyhistory)->SetNext(verifypledge);

    //verify
    verifycash->Loan(bank, 40);
    if (true == bank->isAprov())
    {
        std::cout << "feito" << std::endl;
    }else
    {
        std::cout << "negado" << std::endl;
    }

    //verify
    bank->setCash(10);
    verifycash->Loan(bank, 40);
    if (true == bank->isAprov())
    {
        std::cout << "feito" << std::endl;
    }else
    {
        std::cout << "negado" << std::endl;
    }

    delete bank;
    delete verifycash;
    delete verifyrent;
    delete verifyhistory;
    delete verifypledge;

    return 0;
}