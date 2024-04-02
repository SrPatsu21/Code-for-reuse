#ifndef PPIX_HPP
#define PPIX_HPP

#include "Pagamento.hpp"

class PPix: public Pagamento
{
public:
    PPix();
    ~PPix();    
    void pagar(int valor);
};

#endif