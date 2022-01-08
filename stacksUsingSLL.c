#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node* NODE;

NODE getNode(){
    NODE x;
    x = (NODE)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Out of Memory\n");
        exit(0);
    }
    return x;
}

NODE insertNode(int item, NODE first){
    NODE temp;
    temp = getNode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE deleteFront(NODE first){
    NODE temp;
    if (first == NULL) {
        printf("List is Empty can't delete\n");
        return NULL;
    }
    temp = first;
    temp = temp->link;
    printf("Item deleted = %d\n", first->info);
    free(first);
    return temp;
}

void display(NODE first){
    NODE cur;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("The content of stack is:\n" );
    cur = first;
    while (cur != NULL) {
        printf("%d  ", cur->info );
        cur = cur->link;
    }
    printf("\n");
}

int main (void) {
    NODE first = NULL;
    int choice, item;
    for ( ; ; ) {
        printf("1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :printf("Enter the element you want to enter: \n" );
                    scanf("%d", &item);
                    first = insertNode(item, first);
                    break;

            case 2 :first = deleteFront(first);
                    break;

            case 3 :display(first);
                    break;

            case 4 :exit(0);

            default:printf("Invalid Choice\n");
                    break;
        }
    }
}
