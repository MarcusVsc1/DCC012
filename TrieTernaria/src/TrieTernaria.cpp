#include "TrieTernaria.h"

TrieTernaria::TrieTernaria()
{
    raiz = NULL;
}

TrieTernaria::~TrieTernaria()
{
    //dtor
}


void TrieTernaria::inserir(string frase)
{
        raiz = auxInserir(raiz, frase, 0);
}

NoTrieTernaria* TrieTernaria::auxInserir(NoTrieTernaria* no, string frase, int posicao)
{
    if(posicao == frase.size())
    {
        return no;
    }

    if(no == NULL)
    {
        no = new NoTrieTernaria(frase[posicao]);
        no->setProx(auxInserir(no,frase,posicao+1));
    }
    else
    {
        if(no->getValor() == frase[posicao])
            {
                no->setProx(auxInserir(no->getProx(),frase,posicao+1));
            }
        if(no->getValor() > frase[posicao])
            {
                no->setDir(auxInserir(no->getDir(),frase,posicao));
            }
        if(no->getValor() < frase[posicao])
            {
                no->setEsq(auxInserir(no->getProx(),frase,posicao));
            }
    }

    if(posicao == frase.size()-1)//chegou no final da string
    {
        no->setFim(true);
    }

    return no;

}


bool TrieTernaria::busca(string frase)
{
    return auxBusca(raiz, frase, 0);
}

bool TrieTernaria::auxBusca(NoTrieTernaria* no, string frase, int posicao)
{
    if(no == NULL)
    {
        return false;
    }

    if(posicao == frase.size()-1)
    {
        return no->getFim() == true;
    }

    if(no->getValor() == frase[posicao])
    {
        return auxBusca(no->getProx(),frase,posicao+1);
    }
    else
    {
        if(no->getValor() > frase[posicao])
        {
            return auxBusca(no->getDir(),frase,posicao);
        }
        else
        {
            return auxBusca(no->getEsq(),frase,posicao);
        }
    }

}
