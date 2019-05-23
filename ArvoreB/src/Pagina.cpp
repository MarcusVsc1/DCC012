#include "Pagina.h"

Pagina::Pagina(int minimo)
{
    minChaves = minimo;
    chaves = new int[minimo*2];
    ehExterno = true;
    prox = new Pagina*[(minimo*2)+1];
}
Pagina::~Pagina()
{
    //dtor
}


