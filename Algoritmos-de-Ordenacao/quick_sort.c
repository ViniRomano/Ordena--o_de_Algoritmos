#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int left, int right, int *comparisons) {
    int pivotIndex = (left + right) / 2;

    if (A[pivotIndex] < A[left]) {
        swap(&A[pivotIndex], &A[left]);
    }
    if (A[right] < A[left]) {
        swap(&A[right], &A[left]);
    }
    if (A[right] < A[pivotIndex]) {
        swap(&A[right], &A[pivotIndex]);
    }

    swap(&A[pivotIndex], &A[right - 1]);

    int pivot = A[right - 1];
    int i = left;
    int j = right - 1;

    while (1) {
        while (A[++i] < pivot) {
            (*comparisons)++;
        }

        while (A[--j] > pivot) {
            (*comparisons)++;
        }

        if (i < j) {
            swap(&A[i], &A[j]);
        } else {
            break;
        }
    }

    swap(&A[i], &A[right - 1]);

    return i;
}

void quicksort(int A[], int left, int right, int *comparisons, int *swaps) {
    if (left + 10 <= right) {
        int pivotIndex = partition(A, left, right, comparisons);
        quicksort(A, left, pivotIndex - 1, comparisons, swaps);
        quicksort(A, pivotIndex + 1, right, comparisons, swaps);
    } else {
        
        for (int i = left + 1; i <= right; i++) {
            int j = i;
            int temp = A[i];
            (*comparisons)++;
            while (j > left && temp < A[j - 1]) {
                A[j] = A[j - 1];
                (*swaps)++;
                j--;
            }
            A[j] = temp;
            (*swaps)++;
        }
    }
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int comparisons = 0, swaps = 0;

    quicksort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    return 0;
}
