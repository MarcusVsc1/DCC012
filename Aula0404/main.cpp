#include <iostream>

using namespace std;

void imprimeVetor(int* l, int fim){
    for( int i = 0; i < fim; i++ )
    {
        cout << l[i] << " ";
    }
}

void heapSort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void quickSort(int* l, int inicio, int fim){
    int i, j, pivo, aux;
    i = inicio;
    j = fim;
    pivo = l[(inicio+fim)/2];
    while(i <= j)
    {
        while(l[i] < pivo && i < fim)
        {
            i++;
        }
        while(l[j] > pivo && j > inicio)
        {
            j--;
        }
        if(i <= j)
        {
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio)
    {
        quickSort(l, inicio, j+1);
    }
    if(i < fim)
    {
        quickSort(l, i, fim);
    }
}


int main()
{
    int l[12] = {15, 8, 1, 12, 7, 3, 6, 9, 4, 10, 5, 2};
    heapSort(l,12);
    imprimeVetor(l, 12);
    return 0;
}
