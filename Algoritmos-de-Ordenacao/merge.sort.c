#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para armazenar estatísticas
typedef struct {
    int trocas;
    int comparacoes;
} Estatisticas;

// Função para preencher o array com valores aleatórios
void preencherAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % tamanho;  // Números aleatórios até o tamanho do array
    }
}

// Função para preencher o array em ordem crescente
void preencherOrdenadoCrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i;
    }
}

// Função para preencher o array em ordem decrescente
void preencherOrdenadoDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para realizar a mesclagem de dois subarrays ordenados
void merge(int arr[], int inicio, int meio, int fim, Estatisticas *estatisticas) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copia dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    // Mescla os arrays temporários de volta em arr[inicio..fim]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = inicio; // Índice inicial do array mesclado

    while (i < n1 && j < n2) {
        estatisticas->comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        estatisticas->trocas++;
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        estatisticas->trocas++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        estatisticas->trocas++;
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int inicio, int fim, Estatisticas *estatisticas) {
    if (inicio < fim) {
        // Encontra o ponto médio do array
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, inicio, meio, estatisticas);
        mergeSort(arr, meio + 1, fim, estatisticas);

        // Mescla as metades ordenadas
        merge(arr, inicio, meio, fim, estatisticas);
    }
}

int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatórios

    int tamanho1 = 1000;
    int tamanho2 = 10000;
    int tamanho3 = 100000;

    // Caso Melhor: Valores em ordem crescente
    int melhorCaso1[tamanho1];
    preencherOrdenadoCrescente(melhorCaso1, tamanho1);

    int melhorCaso2[tamanho2];
    preencherOrdenadoCrescente(melhorCaso2, tamanho2);

    int melhorCaso3[tamanho3];
    preencherOrdenadoCrescente(melhorCaso3, tamanho3);

    // Caso Médio: Valores desordenados com números aleatórios
    int casoMedio1[tamanho1];
    preencherAleatorio(casoMedio1, tamanho1);

    int casoMedio2[tamanho2];
    preencherAleatorio(casoMedio2, tamanho2);

    int casoMedio3[tamanho3];
    preencherAleatorio(casoMedio3, tamanho3);

    // Pior Caso: Valores em ordem decrescente
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
    mergeSort(melhorCaso1, 0, tamanho1 - 1, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(melhorCaso2, 0, tamanho2 - 1, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(melhorCaso3, 0, tamanho3 - 1, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Caso Médio
    inicio = clock();
    mergeSort(casoMedio1, 0, tamanho1 - 1, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(casoMedio2, 0, tamanho2 - 1, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(casoMedio3, 0, tamanho3 - 1, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Pior Caso
    inicio = clock();
    mergeSort(piorCaso1, 0, tamanho1 - 1, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(piorCaso2, 0, tamanho2 - 1, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    mergeSort(piorCaso3, 0, tamanho3 - 1, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    return 0;
}
