#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

void imprimirVetor(int* l, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << l[i] << endl;
    }
}

void troca(int** l, int i, int j)
{

}

void bubbleSort(int* l, int n)
{

    bool trocado;

    do
    {
        trocado = false;
        for(int i = 0; i < n-1; i++)
        {
            if(l[i]>l[i+1])
            {
                int aux = l[i];
                l[i] = l[i+1];
                l[i+1] = aux;
                trocado = true;
            }
        }
    }
    while(trocado);

}



void selectionSort(int* l, int n)
{

    for(int i = 0; i < n-1; i++)
    {
        int j;
        int menor = i;

        for(j = i+1; j < n; j++)
        {
            if(l[j]<l[menor])
            {
                menor = j;
            }
        }
        int aux = l[menor];
        l[menor] = l[i];
        l[i] = aux;

    }

}

void parse(string str,int* info, int posicao)
{
    int i = 0;
    stringstream ss(str);
    while(getline(ss, str, ','))
    {
        int val = atoi(str.c_str());
        if(i == 1)
        {
            info[posicao] = val;
            break;
        }
        i++;
    }

}

void puxarDadosRatings()
{

    int i = 40;
    ifstream arquivo;
    arquivo.open("ratings.csv");
    int cont = 0;
    string str;
    getline(arquivo, str);
    int userID[i];
    int movieID[i];

    if(arquivo.is_open())
    {
        while(cont < i)
        {
            getline(arquivo, str);
            parse(str,movieID, cont);
            cont++;

        }
    }
    else
    {
        cerr << "Erro ao abrir arquivo!" << endl;
    }
    arquivo.close();
    bubbleSort(movieID,i);
    imprimirVetor(movieID,i);

}




int main()
{
    int l[6] = {5, 9, 13, 14, 11, 23};
    puxarDadosRatings();
    return 0;
}
