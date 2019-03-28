#include <iostream>

using namespace std;

void intercala(int* l, int inicio, int meio, int fim){
    int indice_inicio, indice_inicio_vet2, indice_aux;
    int* aux = new int(fim*sizeof(int));
    indice_inicio = inicio;
    indice_inicio_vet2 = meio;
    indice_aux = 0;

    while(indice_inicio < meio && indice_inicio_vet2 < fim){
        if(l[indice_inicio] <= l[indice_inicio_vet2]){
            aux[indice_aux] = l[indice_inicio];
            indice_aux++;
            indice_inicio++;
        } else {
            aux[indice_aux] = l[indice_inicio_vet2];
            indice_aux++;
            indice_inicio_vet2++;
        }
    }

    while(indice_inicio < meio){
        aux[indice_aux] = l[indice_inicio];
        indice_aux++;
        indice_inicio++;
    }

    while(indice_inicio_vet2 < fim){
        aux[indice_aux] = l[indice_inicio_vet2];
        indice_aux++;
        indice_inicio_vet2++;
    }

    for(indice_inicio = inicio; indice_inicio < fim; indice_inicio++){
        l[indice_inicio] = aux[indice_inicio-inicio];
    }

   delete [] aux;
}

void mergeSort(int* l, int inicio, int fim){

    int meio;

    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(l, inicio, meio);
        mergeSort(l, meio+1, fim);
        intercala(l, inicio, meio, fim);
    }

}

void mergeSortIterativo(int *l, int meio, int fim){

    int v1[fim-meio];
    int v2[meio];
    int i = 0;
    while(i<meio){
        v1[i]=l[i];
        i++;
    }
    while(i<fim){
        v2[i-meio]=l[i];
        i++;
    }

    int i1 = 0, i2 = 0;

    while(i1 < fim-meio && i2 < meio){
        if(v1[i1]<=v2[i2]){
            l[i1+i2]=v1[i1];
            i1++;
        }else{
            l[i1+i2]=v2[i2];
            i2++;
        }
    }

    while(i1<fim-meio){
        l[i1+i2]=v1[i1];
        i1++;
    }

    while(i2<meio){
        l[i1+i2]=v2[i2];
        i2++;
    }

}


void insertionSort(int* l, int n){
    for(int i = 1; i<n; i++){
        int pivo = l[i];
        int j = i-1;
        while(j>=0 && l[j]>pivo){
            l[j+1]=l[j];
            j--;
        }
        l[j+1]=pivo;
    }
}


void imprimeVetor(int* l, int n){
    cout<<"=============================="<< endl;
    for(int i = 0; i<n; i++){
        cout << l[i] << " ";
    }
    cout<< endl <<"=============================="<< endl;
}

int main()
{
    int l[8] = { 1, 7, 4, 10, 2, 35, 56, 8 };
    mergeSort(l,4,8);
    imprimeVetor(l,8);
    return 0;
}
