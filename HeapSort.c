// Max Heap

#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;        // left child
    int right = 2 * i + 2;       // right child
     // If left child is larger than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    // If right child is larger than root
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    // If root is not largest
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n , i);
    }
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root element to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main (void) {
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements are-\n");
    printArray(a, n);
    heapSort(a, n);
    printf("After sorting array elements are-\n");
    printArray(a, n);
    return 0;
}
