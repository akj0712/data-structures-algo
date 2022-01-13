#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    int i;
    for ( i = 0; i < n; i++) {
        if (key == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main (void)
{
    int key, n, result;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr) / sizeof(arr[0]);
    key = 50;
    result = linearSearch(arr, n, key);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result + 1 );

    return 0;
}
