#include "PCartao.hpp"

PCartao::PCartao()
:Pagamento()
{}

PCartao::~PCartao(){}

void PCartao::pagar(int valor) 
{
    std::cout << "pagou com cartão o valor de:"<< valor << std::endl;
}
