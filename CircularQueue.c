#include<stdio.h>
#include<stdlib.h>

#define CQSIZE 5

void insert(int item, int *r, int cq[], int *count)
{
    if (*count == CQSIZE)
    {
        printf("CIRCULAR QUEUE OVERFLOW\n");
        return;
    }
    *r = (*r + 1) % CQSIZE;
    cq[*r] = item;
    *count = *count + 1;
}

void delete (int *f, int *count, int cq[])
{
    if (*count == 0)
    {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
        return;
    }
    printf("The deleted item is %d\n", cq[*f]);
    *f = (*f + 1) % CQSIZE;
    *count = *count - 1;
}

void display(int f, int count, int cq[])
{
    if (count == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("The content of the circular queue is: ");
    for (int i = 1; i <= count; i++)
    {
        printf("%d ", cq[f]);
        f = (f + 1) % CQSIZE;
    }
    printf("\n");
}

int main(void)
{
    int f, r, count, choice, item;
    int cq[20];
    f = 0;
    r = -1;
    count = 0;

    
    for (;;)
    {
        printf("1. INSERT\t2. DELETE\t3.DISPLAY\t4.EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &item);
            insert(item, &r, cq, &count);
            break;

        case 2:
            delete (&f, &count, cq);
            break;

        case 3:
            display(f, count, cq);
            break;

        case 4:
            exit(0);

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}
