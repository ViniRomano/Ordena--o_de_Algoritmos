#include <stdio.h>

void bubble_sort(int arr[], int n, int *swaps, int *comparisons) {
    int i, j, temp;
    int ordered = 0;

    *swaps = 0;
    *comparisons = 0;

    for (i = 0; i < n - 1 && !ordered; i++) {
        ordered = 1;
        for (j = 0; j < n - 1 - i; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
                ordered = 0;
            }
        }
    }
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps, comparisons;

    bubble_sort(arr, n, &swaps, &comparisons);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Swaps: %d\n", swaps);
    printf("Comparisons: %d\n", comparisons);

    return 0;
}
