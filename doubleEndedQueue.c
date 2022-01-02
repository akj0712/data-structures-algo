#include <stdio.h>
#include <stdlib.h>

#define DEQ 20

void insertFront(int deq[], int *r, int *f, int item)
{
    if (*f = 0 && *r == -1)
    {
        *r = *r + 1;
        deq[*r] = item;
        return;
    }
    if (*f != 0)
    {
        *f = *f - 1;
        deq[*f] = item;
        return;
    }
    printf("Insertion not possible\n");
}

void insertRear(int deq[], int *r, int item)
{
    if (*r == DEQ - 1)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    *r = *r + 1;
    deq[*r] = item;
}

void deleteFront(int deq[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("The deleted element is %d\n", deq[(*f)++]);
    if (*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void deleteRear(int deq[], int *r, int *f)
{
    if (*f > *r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("The deleted item is %d\n", deq[(*r)--]);
    if (*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int deq[], int r, int f)
{
    if (f > r)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The content of the queue is: ");
    for (int i = f; i <= r; i++)
    {
        printf("%d\t", deq[i]);
    }
    printf("\n");
}

int main(void)
{
    int f, r, item, choice, deq[20];
    f = 0;
    r = -1;
    for (;;)
    {
        printf("1.INSERT_FRONT\t2.INSERT_REAR\t3.DELETE_FRONT\t4.DELETE_REAR\t5.DISPLAY\t6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted in the Queue: ");
            scanf("%d", &item);
            insertFront(deq, &r, &f, item);
            break;

        case 2:
            printf("Enter the item to be inserted in the Queue: ");
            scanf("%d", &item);
            insertRear(deq, &r, item);
            break;

        case 3:
            deleteFront(deq, &f, &r);
            break;

        case 4:
            deleteRear(deq, &r, &f);
            break;

        case 5:
            display(deq, r, f);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}