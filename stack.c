#include "stdio.h"
#include "stdlib.h"
// #include "process.h"
#define SIZE 5

void push(int item, int *top, int s[])
{
    if (*top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    *top = *top - 1;
    s[*top] = item;
}

int pop(int *top, int s[])
{
    int item_deleted;
    if (*top == -1)
        return 0;
    item_deleted = s[*top--];
    return item_deleted;
}

void display(int top, int s[])
{
    int i;
    if (top == -1)
    {
        printf("STACK is EMPTY\n");
    }
    else{
        printf("Contents of the STACK is\n");
        for (i = 0; i <= top; i++)
            printf("%d\n", s[i]);
    }
}

void main()
{
    int top = -1;
    int s[10];
    int item;
    int item_deleted;
    int choice;

    for (;;)
    {
        printf("1: PUSH\t2:POP\n");
        printf("3: DISPLAY\t4:EXIT\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            push(item, &top, s);
            break;

        case 2:
            item_deleted = pop(&top, s);
            if (item_deleted == 0)
                printf("Stack is empty\n");
            else
            {
                printf("Item Deleted = %d\n", item_deleted);
                break;
            }

        case 3:
            display(top, s);
            break;

        default:
            exit(0);
        }
    }
}