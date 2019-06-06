#include <iostream>
#include "TrieTernaria.h"
#include "NoTrieTernaria.h"



using namespace std;

int main()
{

    TrieTernaria* arvore = new TrieTernaria();
    arvore->inserir("pudim");
        cout << "Hello world!" << endl;
    bool deu = arvore->busca("pudim");
    cout<< "Sera?";
    return 0;
}
