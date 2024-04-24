#ifndef PCARTAO_HPP
#define PCARTAO_HPP

#include "Pagamento.hpp"

class PCartao: public Pagamento
{
public:
    PCartao();
    ~PCartao();    
    void pagar(int valor);
};

#endif