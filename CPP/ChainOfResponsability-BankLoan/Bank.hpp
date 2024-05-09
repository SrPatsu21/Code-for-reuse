#ifndef BANK_HPP
#define BANK_HPP

class Bank
{
private:
    int cash;
    bool aprov;
public:
    Bank(int cash);
    ~Bank();
    int getCash();
    void setCash(int cash);
    void removeCash(int cash);
    bool isAprov();
    void setAprov(bool boolop);
};

#endif