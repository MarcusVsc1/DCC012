#include "TrieTernaria.h"
#include <iostream>
TrieTernaria::TrieTernaria()
{
    raiz = NULL;
}

TrieTernaria::~TrieTernaria()
{
    auxDelete(raiz);
}

void TrieTernaria::auxDelete(NoTrieTernaria* p)
{
    if(p!=NULL)
    {
        auxDelete(p->getDir());
        auxDelete(p->getEsq());
        auxDelete(p->getProx());
        delete p;
    }


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
        cout << "Inseriu "<<frase[posicao] <<endl;
        no = new NoTrieTernaria(frase[posicao]);
        no->setProx(auxInserir(NULL,frase,posicao+1));
    }
    else
    {

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

    cout << "Valor do no: " << no->getValor() << " valor na chave: " << frase[posicao] << endl;

    if(posicao == frase.size()-1 && no->getValor() == frase[posicao])//chegou no final da string e encontrou ultimo valor
    {
        cout << "Inseriu fim com sucesso. Valor do no: "<< no->getValor() <<endl;
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



    cout << no->getFim() << endl;
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

bool TrieTernaria::vazia()
{
    return raiz == NULL;
}

void TrieTernaria::removerChave(string chave)
{
    NoTrieTernaria* p = raiz;

    while(p->getValor() != chave[0] && p != NULL)
    {
        if(p->getValor() > chave[0])
        {
            p = p->getDir();
        }
        else
        {
            p = p->getEsq();
        }
    }

    auxRemover(p,chave,0);
}

void TrieTernaria::auxRemover(NoTrieTernaria* no, string chave, int posicao)
{

}
