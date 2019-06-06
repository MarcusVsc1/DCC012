#include "TrieTernaria.h"
#include <iostream>
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
    cout << "rodou."<<endl;
    if(posicao == frase.size())
    {
        return no;
    }

    if(no == NULL)
    {
        cout << "Inseriu "<<frase[posicao] <<endl;
        no = new NoTrieTernaria(frase[posicao]);
        no->setProx(auxInserir(NULL,frase,posicao+1));
    }
    else
    {
        cout << frase[posicao] <<endl;
        if(no->getValor() == frase[posicao])
            {
                cout <<frase[posicao]<<" ja existe." <<endl;
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

    if(posicao == frase.size() && no->getValor() == frase[posicao])//chegou no final da string e encontrou ultimo valor
    {
        cout << "Inseriu fim com sucesso."<<endl;
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
        if(posicao==0)
        {
            cout << "Chave nao existe na Trie!" << endl;
        }
        else
        {
            cout << "Chave parcialmente encontrada!" << endl;
        }
        return false;
    }




    if(no->getValor() == frase[posicao])
    {
        cout << "Encontrou parte da chave! "<<frase[posicao]<<endl;
        posicao++;
        if(posicao == frase.size())
        {
            if(no->getFim() == true)
            {
                cout << "Chave encontrada!" << endl;
                return true;
            }
            else
            {
                cout << "Elementos da chave foram encontrados, porem chave nao faz parte da arvore!" << endl;;
                return false;
            }

        }
        return auxBusca(no->getProx(),frase,posicao);
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

void TrieTernaria::impressao()
{

}
