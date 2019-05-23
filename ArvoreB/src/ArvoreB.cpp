#include "ArvoreB.h"
#include "Pagina.h"


ArvoreB::ArvoreB()
{
    raiz = nullptr;
}

ArvoreB::~ArvoreB()
{
    //dtor
}

bool ArvoreB::ehVazia()
{
    return raiz == nullptr;
}

bool ArvoreB::inserir(int chave, int ordem){
    if(raiz == nullptr)
    {
        Pagina* nova = new Pagina(ordem);
        nova->chaves[0] = chave;
        raiz = nova;


    }
}
