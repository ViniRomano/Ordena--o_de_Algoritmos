#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int trocas;
    int comparacoes;
} Estatisticas;


void preencherAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % tamanho;  
    }
}


void preencherOrdenadoCrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i;
    }
}


void preencherOrdenadoDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}


void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubbleSort(int arr[], int tamanho, Estatisticas *estatisticas) {
    estatisticas->trocas = 0;
    estatisticas->comparacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            estatisticas->comparacoes++;

            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                estatisticas->trocas++;
            }
        }
    }
}

int main() {
    srand(time(NULL));  

    int tamanho1 = 1000;
    int tamanho2 = 10000;
    int tamanho3 = 100000;

    
    int melhorCaso1[tamanho1];
    preencherOrdenadoCrescente(melhorCaso1, tamanho1);

    int melhorCaso2[tamanho2];
    preencherOrdenadoCrescente(melhorCaso2, tamanho2);

    int melhorCaso3[tamanho3];
    preencherOrdenadoCrescente(melhorCaso3, tamanho3);

    
    int casoMedio1[tamanho1];
    preencherAleatorio(casoMedio1, tamanho1);

    int casoMedio2[tamanho2];
    preencherAleatorio(casoMedio2, tamanho2);

    int casoMedio3[tamanho3];
    preencherAleatorio(casoMedio3, tamanho3);

   
    int piorCaso1[tamanho1];
    preencherOrdenadoDecrescente(piorCaso1, tamanho1);

    int piorCaso2[tamanho2];
    preencherOrdenadoDecrescente(piorCaso2, tamanho2);

    int piorCaso3[tamanho3];
    preencherOrdenadoDecrescente(piorCaso3, tamanho3);

    // Teste e medição do tempo de execução para cada caso
    clock_t inicio, fim;
    Estatisticas estatisticas;

    // Caso Melhor
    inicio = clock();
    bubbleSort(melhorCaso1, tamanho1, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(melhorCaso2, tamanho2, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(melhorCaso3, tamanho3, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Caso Médio
    inicio = clock();
    bubbleSort(casoMedio1, tamanho1, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(casoMedio2, tamanho2, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(casoMedio3, tamanho3, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Pior Caso
    inicio = clock();
    bubbleSort(piorCaso1, tamanho1, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(piorCaso2, tamanho2, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(piorCaso3, tamanho3, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    return 0;
}

