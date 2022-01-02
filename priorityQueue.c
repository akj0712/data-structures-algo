#include <stdio.h>
#include <stdlib.h>

#define PQSIZE 20

void insertItem(int pq[], int *r, int item)
{
    int j;
    if (*r == PQSIZE - 1)
    {
        printf("QUEUE FULL\n");
        return;
    }
    j = *r;
    while (j >= 0 && item < pq[j])
    {
        pq[j + 1] = pq[j];
        j--;
    }
    pq[j + 1] = item;
    *r = *r + 1;
}

void deleteFront(int pq[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("The deleted item is %d\n", pq[(*f)++]);
    if (*f > *r)
    {
        *r = -1;
        *f = 0;
    }
}

void display(int pq[], int f, int r)
{
    if (f > r)
    {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    printf("THe content of the queue is:\n");
    for (int i = f; i <= r; i++)
    {
        printf("%d\n", pq[i]);
    }
}

int main(void)
{
    int f, r, item, choice, pq[5];
    f = 0;
    r = -1;
    for (;;)
    {
        printf("1.INSERT\t2.DELETE\t3.DISPLAY\t4.QUIT\n");
        printf("ENter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted in the Priority Queue: ");
            scanf("%d", &item);
            insertItem(pq, &r, item);
            break;

        case 2:
            deleteFront(pq, &f, &r);
            break;

        case 3:
            display(pq, f, r);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}