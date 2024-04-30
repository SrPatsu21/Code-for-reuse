#ifndef PTRANSFERENCIA_HPP
#define PTRANSFERENCIA_HPP

#include "Pagamento.hpp"

class PTransferencia: public Pagamento
{
public:
    PTransferencia();
    ~PTransferencia();    
    void pagar(int valor);
};

#endif