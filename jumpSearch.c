// C Program to implement Jump Search

#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key)
{
    int i, low = 0, jump = sqrt(n);
    for (i = 0; i < n; i += jump)
    {
        if (arr[i] == key)
        {
            return i;
        }
        if (arr[i] < key)
        {
            low = i;
        }
        else
        {
            break;
        }
    }
    for (i = low; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int n, key, result;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr) / sizeof(arr[0]);
    key = 70;
    result = jumpSearch(arr, n, key);
    (result == -1)
        ? printf("ELEMENT NOT FOUND\n")
        : printf("Element found at position %d\n", result + 1);
        
    return 0;
}
