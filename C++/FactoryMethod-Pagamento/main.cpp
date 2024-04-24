#include "PBoleto.hpp"
#include "PCartao.hpp"
#include "PPix.hpp"
#include "PTransferencia.hpp"

int main(void)
{
    Pagamento* p;
    p = new PBoleto();
    p->pagar(90);
    
    return 0;
}