// C Progrsm to Implement Binary Search using RECURSION

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x){
    if ( r >= 1) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main (void) {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 100;
    int result = binarySearch(arr, 0, n, x);
    if (result == -1) {
        printf("Element not present in the array\n" );
    }
    else{
        printf("Element present at location %d\n", result + 1);
    }
    return 0;
}
