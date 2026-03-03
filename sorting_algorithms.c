#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// -------------------- FUNÇÃO AUXILIAR --------------------
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int source[], int dest[], int n) {
    for(int i = 0; i < n; i++)
        dest[i] = source[i];
}

// -------------------- BUBBLE SORT --------------------
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// -------------------- SELECTION SORT --------------------
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// -------------------- INSERTION SORT --------------------
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// -------------------- QUICK SORT --------------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -------------------- MERGE SORT --------------------
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// -------------------- MAIN --------------------
int main() {

    int original[SIZE];
    int arr[SIZE];
    clock_t start, end;
    double time_taken;
    int option;

    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
        original[i] = rand() % 10000;

    do {
        printf("\n===== MENU DE ORDENACAO =====\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Quick Sort\n");
        printf("5 - Merge Sort\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        copyArray(original, arr, SIZE);

        switch(option) {
            case 1:
                start = clock();
                bubbleSort(arr, SIZE);
                end = clock();
                break;
            case 2:
                start = clock();
                selectionSort(arr, SIZE);
                end = clock();
                break;
            case 3:
                start = clock();
                insertionSort(arr, SIZE);
                end = clock();
                break;
            case 4:
                start = clock();
                quickSort(arr, 0, SIZE - 1);
                end = clock();
                break;
            case 5:
                start = clock();
                mergeSort(arr, 0, SIZE - 1);
                end = clock();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                continue;
        }

        if(option != 0) {
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Tempo de execucao: %f segundos\n", time_taken);
        }

    } while(option != 0);

    return 0;
}
