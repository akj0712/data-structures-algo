// C program for implementation of Selection sort

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int array[], int n)
{
    int i, j, min_ind;
    for ( i = 0; i < n - 1; i++) {
        min_ind = i;
        for ( j = i + 1; j < n; j++)
            if (array[j] < array[min_ind])
                min_ind = j;

            swap(&array[min_ind], &array[i]);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main (void)
{
    int array[] = {20, 10, 30, 50, 80, 40, 60};
    int n = sizeof(array) / sizeof(array[0]);
    selectionSort(array, n);
    printf("Sorted array is:\n");
    printArray(array, n);


    return 0;
}
