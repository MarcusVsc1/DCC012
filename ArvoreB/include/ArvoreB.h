#ifndef ARVOREB_H
#define ARVOREB_H
#include "Pagina.h"




class ArvoreB
{
    public:
        ArvoreB();
        ~ArvoreB();


    private:
        bool buscaB(int chave);
        Pagina* raiz;
        bool ehVazia();
        bool inserir(int chave, int ordem);
        int ordem;

};

#endif // ARVOREB_H
