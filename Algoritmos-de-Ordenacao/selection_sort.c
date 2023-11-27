#include <stdio.h>

void selection_sort(int array[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            (*swaps)++;
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps, comparisons;

    selection_sort(arr, n, &swaps, &comparisons);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Swaps: %d\n", swaps);
    printf("Comparisons: %d\n", comparisons);

    return 0;
}
