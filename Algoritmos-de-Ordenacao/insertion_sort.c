#include <stdio.h>

void insertion_sort(int arr[], int n, int *swaps, int *comparisons) {
    int i, key, j;

    *swaps = 0;
    *comparisons = 0;

    if (n <= 1) {
        return;
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            (*swaps)++;
            (*comparisons)++;
            j--;
        }

        arr[j + 1] = key;
        (*swaps)++;
    }
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps, comparisons;

    insertion_sort(arr, n, &swaps, &comparisons);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Swaps: %d\n", swaps);
    printf("Comparisons: %d\n", comparisons);

    return 0;
}
