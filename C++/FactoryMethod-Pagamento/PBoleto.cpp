#include "PBoleto.hpp"
#include "Pagamento.hpp"

PBoleto::PBoleto()
:Pagamento()
{}

PBoleto::~PBoleto(){}

void PBoleto::pagar(int valor) 
{
    std::cout << "pagou com boleto o valor de:"<< valor << std::endl;
}
