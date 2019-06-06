#ifndef TRIETERNARIA_H
#define TRIETERNARIA_H
#include "NoTrieTernaria.h"
#include <string>

using namespace std;



class TrieTernaria
{
    public:
        TrieTernaria();
        ~TrieTernaria();
        void inserir(string frase);
        NoTrieTernaria* auxInserir(NoTrieTernaria* no, string frase, int posicao);
        bool busca(string frase);
        bool auxBusca(NoTrieTernaria* no, string frase, int posicao);


    private:
        NoTrieTernaria* raiz;
};

#endif // TRIETERNARIA_H
