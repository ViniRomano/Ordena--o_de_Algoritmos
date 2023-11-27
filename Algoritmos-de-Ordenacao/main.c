#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubble_sort(int arr[], int n);
void improved_bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void merge_sort(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);
void radix_sort(int arr[], int n);


void print_array(int arr[], int n);
int* generate_fixed_data(int size, char* case);
void swap(int* a, int* b);


typedef struct {
    char* Algorithm;
    char* Case;
    int Size;
    int Swaps;
    int Comparisons;
    double ExecutionTime;
} SortingData;

int main() {
    srand(42);

    
    char* cases[] = {"melhor", "pior", "aleatorio"};
    int sizes[] = {1000, 10000, 100000};

    
    SortingData data_dict[21];
    int data_index = 0;

    
    char* algorithms[] = {"bubble_sort", "improved_bubble_sort", "insertion_sort", "selection_sort", "merge_sort", "quick_sort", "radix_sort"};

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int size = sizes[k];
                char* case_type = cases[j];
                int* arr = generate_fixed_data(size, case_type);

                clock_t start_time = clock();
                
                if (strcmp(algorithms[i], "bubble_sort") == 0) {
                    bubble_sort(arr, size);
                } else if (strcmp(algorithms[i], "improved_bubble_sort") == 0) {
                    improved_bubble_sort(arr, size);
                } else if (strcmp(algorithms[i], "insertion_sort") == 0) {
                    insertion_sort(arr, size);
                } else if (strcmp(algorithms[i], "selection_sort") == 0) {
                    selection_sort(arr, size);
                } else if (strcmp(algorithms[i], "merge_sort") == 0) {
                    merge_sort(arr, 0, size - 1);
                } else if (strcmp(algorithms[i], "quick_sort") == 0) {
                    quick_sort(arr, 0, size - 1);
                } else if (strcmp(algorithms[i], "radix_sort") == 0) {
                    radix_sort(arr, size);
                }

                clock_t end_time = clock();

                
                data_dict[data_index].Algorithm = algorithms[i];
                data_dict[data_index].Case = case_type;
                data_dict[data_index].Size = size;
                data_dict[data_index].Swaps = 0; 
                data_dict[data_index].Comparisons = 0; 
                data_dict[data_index].ExecutionTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

                data_index++;

                
                free(arr);
            }
        }
    }

    
    printf("%-20s%-10s%-10s%-10s%-15s%-20s\n", "Algoritmo", "Caso", "Tamanho", "Trocas", "Comparações", "Tempo de Execução");
    for (int i = 0; i < 21; i++) {
        printf("%-20s%-10s%-10d%-10d%-15d%-20lf\n", data_dict[i].Algorithm, data_dict[i].Case, data_dict[i].Size, data_dict[i].Swaps, data_dict[i].Comparisons, data_dict[i].ExecutionTime);
    }

    
    return 0;
}


void bubble_sort(int arr[], int n) {
    
}

void improved_bubble_sort(int arr[], int n) {
    
}

void insertion_sort(int arr[], int n) {
   
}

void selection_sort(int arr[], int n) {
   
}

void merge_sort(int arr[], int left, int right) {
   
}

void quick_sort(int arr[], int left, int right) {
   
}

void radix_sort(int arr[], int n) {
  
}

void print_array(int arr[], int n) {

}

int* generate_fixed_data(int size, char* case_type) {
   
    return NULL;
}

void swap(int* a, int* b) {
   
}
