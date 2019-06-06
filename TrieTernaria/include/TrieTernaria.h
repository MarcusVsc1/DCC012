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
        void impressao();
        bool vazia();
        void auxDelete(NoTrieTernaria* p);
        void removerChave(string chave);
        void auxRemover(NoTrieTernaria* no, string chave, int posicao);


    private:
        NoTrieTernaria* raiz;
};

#endif // TRIETERNARIA_H
