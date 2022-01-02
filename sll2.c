#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
};

typedef struct node* NODE;

NODE getNode(){
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("NO MEMORY ALLOCATED!\n");
        exit(0);
    }
    return x;
}

NODE insertFront(int item, NODE first){
    NODE temp;
    temp = getNode();
    temp->info = item;
    temp->link = first;
    return temp;
}

void display(NODE first){
    NODE temp;
    if (first == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    temp = first;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    printf("\n");
    
}

int main(void){
    NODE first = NULL;
}