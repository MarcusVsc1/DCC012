#include <iostream>
#include "TrieTernaria.h"
#include "NoTrieTernaria.h"



using namespace std;

int main()
{

    TrieTernaria* arvore = new TrieTernaria();
    arvore->inserir("pudim");
    arvore->inserir("chucrute");
    arvore->inserir("banana");
    bool deu = arvore->busca("chucrute");
    return 0;

}
