#include "PTransferencia.hpp"

PTransferencia::PTransferencia()
:Pagamento()
{}

PTransferencia::~PTransferencia(){}

void PTransferencia::pagar(int valor) 
{
    std::cout << "pagou com uma tranferencia o valor de:"<< valor << std::endl;
}
