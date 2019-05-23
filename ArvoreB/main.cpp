#include <iostream>

using namespace std;

void insertionSort(int * vetor, int tamanho) {

    for (int i = 1; i < tamanho; i++) {
		int escolhido = vetor[i];
		int j = i - 1;

		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}

		vetor[j + 1] = escolhido;
	}
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
