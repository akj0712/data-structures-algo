#include<stdio.h>
#include<process.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;
NODE first = NULL;

NODE getNode(){
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("OUT OF MEMORY!\n");
        exit(0);
    }
    return x;
}

void freeNode(NODE x){
    free(x);
}

NODE insertFront(int item, NODE first){
    NODE temp;
    temp = getNode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE deleteFront(NODE first){
    NODE temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY CAN'T BE DELETED\n");
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Item deleted: %d\n", temp->info);
    freeNode(first);
    return temp;
}

NODE insertRear(int item, NODE first){
    NODE temp;
    NODE cur;
    temp = getNode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link  = temp;
    return first;
}

NODE deleteRear(NODE first){
    NODE cur, prev;
    if (first == NULL)
    {
        printf("LIST IS EMPTY CAN'T DELETE\n");
        return first;
    }
    if (first->link == NULL)
    {
        printf("The item to be deleted is %d\n", first->info);
        freeNode(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("The item deleted is %d\n", cur->info);
    freeNode(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first){
    NODE temp;
    if(first == NULL){
        printf("LIST IS EMPTY\n");
        return;
    }
    printf("The content of Singly Linked List:\n");
    temp = first;
    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}


int main(void){
    NODE first = NULL;
    int choice, item;
    for ( ; ; )
    {
        printf("1.INSERT FRONT\t2. DELETE FRONT\t3.INSERT REAR\n4.DELETE REAR\t5.DISPLAY\t6.QUIT\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted in the list: ");
            scanf("%d", &item);
            first = insertFront(item, first);
            break;
        
        case 2:
            first = deleteFront(first);
            break;

        case 3:
            printf("Enter the item to be inserted in the list: ");
            scanf("%d", &item);
            first = insertRear(item, first);
            break;

        case 4:
            first = deleteRear(first);
            break;

        case 5: display(first);
                break;
        
        case 6: exit(0);

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}
