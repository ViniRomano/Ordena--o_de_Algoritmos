#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para armazenar estatísticas de trocas e comparações
struct Estatisticas {
    int trocas;
    int comparacoes;
};

// Função para trocar dois elementos
void trocar(int *a, int *b, struct Estatisticas *estatisticas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    estatisticas->trocas++;
}

// Função que particiona o array e retorna o índice do pivô
int particionar(int arr[], int baixo, int alto, struct Estatisticas *estatisticas) {
    int pivô = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        estatisticas->comparacoes++;
        if (arr[j] < pivô) {
            i++;
            trocar(&arr[i], &arr[j], estatisticas);
        }
    }
    trocar(&arr[i + 1], &arr[alto], estatisticas);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int baixo, int alto, struct Estatisticas *estatisticas) {
    if (baixo < alto) {
        // Encontrar o índice do pivô
        int pi = particionar(arr, baixo, alto, estatisticas);

        // Separadamente ordenar elementos antes e depois do pivô
        quickSort(arr, baixo, pi - 1, estatisticas);
        quickSort(arr, pi + 1, alto, estatisticas);
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para preencher o array com valores aleatórios
void preencherAleatoriamente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        arr[i] = rand() % 1000; // Valores aleatórios entre 0 e 999
}

// Função para preencher o array em ordem crescente
void preencherOrdenadoCrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        arr[i] = i;
}

// Função para preencher o array em ordem decrescente
void preencherOrdenadoDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        arr[i] = tamanho - i - 1;
}

int main() {
    srand(time(NULL));

    // Tamanhos do array
    int tamanhos[] = {1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];

        // Alocar e preencher arrays para cada caso
        int *arrMelhorCaso = (int *)malloc(tamanho * sizeof(int));
        int *arrCasoMedio = (int *)malloc(tamanho * sizeof(int));
        int *arrPiorCaso = (int *)malloc(tamanho * sizeof(int));

        preencherOrdenadoCrescente(arrMelhorCaso, tamanho);
        preencherAleatoriamente(arrCasoMedio, tamanho);
        preencherOrdenadoDecrescente(arrPiorCaso, tamanho);

        // Inicializar estatísticas
        struct Estatisticas estatisticasMelhorCaso = {0, 0};
        struct Estatisticas estatisticasCasoMedio = {0, 0};
        struct Estatisticas estatisticasPiorCaso = {0, 0};

        // Medir tempo e executar o Quick Sort para cada caso
        clock_t inicio, fim;

        // Melhor Caso
        inicio = clock();
        quickSort(arrMelhorCaso, 0, tamanho - 1, &estatisticasMelhorCaso);
        fim = clock();
        double tempoMelhorCaso = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        // Caso Médio
        inicio = clock();
        quickSort(arrCasoMedio, 0, tamanho - 1, &estatisticasCasoMedio);
        fim = clock();
        double tempoCasoMedio = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        // Pior Caso
        inicio = clock();
        quickSort(arrPiorCaso, 0, tamanho - 1, &estatisticasPiorCaso);
        fim = clock();
        double tempoPiorCaso = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        // Imprimir resultados
        printf("\nTamanho do Array: %d\n", tamanho);
        printf("Melhor Caso: Tempo = %f s, Trocas = %d, Comparacoes = %d\n", tempoMelhorCaso, estatisticasMelhorCaso.trocas, estatisticasMelhorCaso.comparacoes);
        printf("Caso Médio: Tempo = %f s, Trocas = %d, Comparacoes = %d\n", tempoCasoMedio, estatisticasCasoMedio.trocas, estatisticasCasoMedio.comparacoes);
        printf("Pior Caso: Tempo = %f s, Trocas = %d, Comparacoes = %d\n", tempoPiorCaso, estatisticasPiorCaso.trocas, estatisticasPiorCaso.comparacoes);

        // Liberar memória alocada para os arrays
        free(arrMelhorCaso);
        free(arrCasoMedio);
        free(arrPiorCaso);
    }

    return 0;
}
