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

// Função de ordenação Improved Bubble Sort com estatísticas
void improvedBubbleSort(int arr[], int tamanho, Estatisticas *estatisticas) {
    estatisticas->trocas = 0;
    estatisticas->comparacoes = 0;
    int trocas;

    for (int i = 0; i < tamanho - 1; i++) {
        trocas = 0;
        for (int j = 0; j < tamanho - i - 1; j++) {
            estatisticas->comparacoes++;

            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                estatisticas->trocas++;
                trocas = 1;
            }
        }

        // Se não houve trocas nesta iteração, o array já está ordenado
        if (trocas == 0) {
            break;
        }
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
    improvedBubbleSort(melhorCaso1, tamanho1, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(melhorCaso2, tamanho2, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(melhorCaso3, tamanho3, &estatisticas);
    fim = clock();
    printf("Melhor caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Caso Médio
    inicio = clock();
    improvedBubbleSort(casoMedio1, tamanho1, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(casoMedio2, tamanho2, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(casoMedio3, tamanho3, &estatisticas);
    fim = clock();
    printf("Caso medio (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Pior Caso
    inicio = clock();
    improvedBubbleSort(piorCaso1, tamanho1, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho1, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(piorCaso2, tamanho2, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho2, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    improvedBubbleSort(piorCaso3, tamanho3, &estatisticas);
    fim = clock();
    printf("Pior caso (tamanho %d): Trocas: %d, Comparacoes: %d, Tempo: %f segundos\n", tamanho3, estatisticas.trocas, estatisticas.comparacoes, ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    return 0;
}
