#ifndef PBOLETO_HPP
#define PBOLETO_HPP

#include "Pagamento.hpp"

class PBoleto:public Pagamento
{
public:
    PBoleto();
    ~PBoleto();    
    void pagar(int valor);
};

#endif