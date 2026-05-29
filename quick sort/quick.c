#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n, i;
    int a[100000];

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Generate random numbers */
    for(i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }

    start = clock();

    quickSort(a, 0, n - 1);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Elements:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}

/* Quick Sort Function */
void quickSort(int a[], int low, int high) {
    if(low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* Partition Function */
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(1) {

        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            break;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}