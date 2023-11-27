#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int aux[], int esquerda, int meio, int direita, int *trocas, int *comparacoes) {
    for (int k = esquerda; k <= direita; k++) {
        aux[k] = A[k];
    }

    int i = esquerda;
    int j = meio + 1;

    for (int k = esquerda; k <= direita; k++) {
        (*comparacoes)++;
        if (i > meio) {
            A[k] = aux[j];
            j++;
        } else if (j > direita) {
            A[k] = aux[i];
            i++;
        } else if (aux[j] < aux[i]) {
            A[k] = aux[j];
            j++;
            (*trocas)++;
        } else {
            A[k] = aux[i];
            i++;
            (*trocas)++;
        }
    }
}

void merge_sort_recursive(int A[], int aux[], int esquerda, int direita, int *trocas, int *comparacoes) {
    if (direita <= esquerda) {
        return;
    }

    int meio = (esquerda + direita) / 2;

    merge_sort_recursive(A, aux, esquerda, meio, trocas, comparacoes);
    merge_sort_recursive(A, aux, meio + 1, direita, trocas, comparacoes);

    merge(A, aux, esquerda, meio, direita, trocas, comparacoes);
}

void merge_sort(int A[], int n, int *trocas, int *comparacoes) {
    int *aux = (int *)malloc(n * sizeof(int));

    *trocas = 0;
    *comparacoes = 0;

    merge_sort_recursive(A, aux, 0, n - 1, trocas, comparacoes);

    free(aux);
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int trocas, comparacoes;

    merge_sort(arr, n, &trocas, &comparacoes);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Swaps: %d\n", trocas);
    printf("Comparisons: %d\n", comparacoes);

    return 0;
}
