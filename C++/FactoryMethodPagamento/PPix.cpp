#include "PPix.hpp"

PPix::PPix():
Pagamento()
{}

PPix::~PPix(){}

void PPix::pagar(int valor) 
{
    std::cout << "pagou com pix o valor de:"<< valor << std::endl;
}
