#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    /* Find largest among root, left child and right child */
    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    /* Swap and continue heapifying if root is not largest */
    if(largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

/* Heap Sort Function */
void heapSort(int a[], int n) {

    /* Build max heap */
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements from heap */
    for(int i = n - 1; i >= 0; i--) {

        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

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

    heapSort(a, n);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Elements:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}