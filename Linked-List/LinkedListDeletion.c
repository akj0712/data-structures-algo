/*
1. Deleting the first node -> 0(1)
2. Deleting the node in between ->
3. Deleting the last node ->
4. Deleting the node with given key value ->
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// deleting the first element
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// deleting the element in between
struct Node *deleteBetween(struct Node *head, int index)
{
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// deleting last element
struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = q;
        q = q->next;
    }
    free(q);
    p->next = NULL;
    return head;
}

// delete the node with a particular data
struct Node *deleteKey(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Element not present\n");
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for the nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 10;
    second->next = third;

    // Link third and fourth node
    third->data = 13;
    third->next = fourth;

    // terminate at fourth end
    fourth->data = 16;
    fourth->next = NULL;

    printf("\nBefore: \n");
    linkedListTraversal(head);
    printf("\nAfter: \n");
    // head = deleteFirst(head);
    // head = deleteLast(head);
    // head = deleteBetween(head, 2);
    head = deleteKey(head, 19);
    linkedListTraversal(head);

    return 0;
}