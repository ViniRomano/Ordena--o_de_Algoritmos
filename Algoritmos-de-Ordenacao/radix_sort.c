#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para encontrar o maior número
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Função para realizar a ordenação por contagem de acordo com a posição
int countSort(int arr[], int n, int exp) {
    int output[n]; // array de saída
    int count[10] = {0};
    int movimentacoes = 0;

    // Contagem do número de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Atualização do array count[] para conter as posições reais
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construção do array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        movimentacoes++;
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar o array de saída para arr[], assim arr[] contém números ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    return movimentacoes;
}

// Função principal para implementar o Radix Sort
int radixSort(int arr[], int n) {
    // Encontrar o número máximo para saber o número de dígitos
    int max = findMax(arr, n);
    int movimentacoes = 0;

    // Aplicar o counting sort para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10)
        movimentacoes += countSort(arr, n, exp);

    return movimentacoes;
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para preencher um array com valores aleatórios
void fillRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000; // Limitado a valores até 9999 para melhor visualização
}

// Função para preencher um array em ordem crescente
void fillAscendingArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = i;
}

// Função para preencher um array em ordem decrescente
void fillDescendingArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = size - i;
}

int main() {
    // Tamanhos dos arrays
    int sizes[] = {1000, 10000, 100000};

    // Loop para cada tamanho
    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        int arr[size];

        // Caso Melhor: Valores em ordem crescente
        fillAscendingArray(arr, size);
        int mov_best = radixSort(arr, size);
        printf("Melhor Caso (Tamanho %d): %d movimentacoes\n", size, mov_best);

        // Caso Médio: Valores desordenados com números aleatórios
        fillRandomArray(arr, size);
        int mov_avg = radixSort(arr, size);
        printf("Caso Médio (Tamanho %d): %d movimentacoes\n", size, mov_avg);

        // Caso Pior: Valores em ordem decrescente
        fillDescendingArray(arr, size);
        int mov_worst = radixSort(arr, size);
        printf("Pior Caso (Tamanho %d): %d movimentacoes\n", size, mov_worst);

        printf("\n");
    }

    return 0;
}
