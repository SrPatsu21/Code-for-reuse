#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

#include <iostream>

class Pagamento
{
    protected:
        Pagamento();
    public:
        virtual ~Pagamento() = 0;    
        virtual void pagar(int valor) = 0;
};

#endif