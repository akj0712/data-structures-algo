/*

1. Insert at the beginning -> O(1)
2. Insert in between -> O(n)
3. Insert at the end -> O(n)
4. Insert after a node -> O(n)

*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

//Traversal Function
void linkedListTraversal(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Insert in beginning
struct Node * insertFirst(struct Node* head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//Insert in between
struct Node * insertBetween(struct Node* head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

// Insert at End
struct Node * insertEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = data;


    struct Node * p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    
}

// Insert after a node
struct Node * insertAfter(struct Node * prev, struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = data;

    ptr->next = prev->next;
    prev->next = ptr;

    return head;
    
}


int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;


    // Allocate memory for the nodes in the linked list
    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 10;
    second->next = third;

    // terminate at the third node
    third->data = 13;
    third->next = NULL;

    printf("Linked list before Operation:\n");
    linkedListTraversal(head);
    printf("Linked list after operation:\n");
    // head = insertFirst(head, 56);
    // head = insertBetween(head, 56, 1);
    // head = insertEnd(head, 56);
    head = insertAfter(second, head, 56);
    linkedListTraversal(head);

    return 0;
}