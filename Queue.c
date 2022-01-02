#include <stdio.h>
#include <process.h>
#define SIZE 5

void insert_rear(int item, int *r, int q[])
{
    if (*r == SIZE - 1)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    *r = *r + 1;
    q[*r] = item;
}

void delete_front(int q[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("The element deleted is %d\n", q[(*f)++]);
    if (*f > *r)
        *f = 0, *r = -1;
}

void display(int q[], int f, int r)
{
    if (f > r)
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("Contents of the queue is:\n");
    for (int i = 0; i <= r; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(void)
{
    int choice, item, f, r, q[10];
    f = 0;
    r = -1;
    for (;;)
    {
        printf("1: Insert\t2: Delete\n");
        printf("3: Display\t4: Quit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_rear(item, &r, q);
            break;

        case 2:
            delete_front(q, &f, &r);
            break;

        case 3:
            display(q, f, r);
            break;

        default:
            exit(0);
        }
    }
}
