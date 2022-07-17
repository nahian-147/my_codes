#include <stdio.h>
#include <stdlib.h>

struct Node{

    struct Node* incomingNode;

    struct Node* outGoingNode;

    char* name;

    int* adjacent; 
};


int main(){

    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2;
    struct Node *n3 = malloc(sizeof(struct Node));

    n2 = n1;

    n1->name = "n1\0";
    n3->name = "n3\0";

    printf("Our String is : %s\n",n2->name);

    n3->adjacent = (int*) malloc(sizeof(int));
    *n3->adjacent = 1;

    printf("Our int is : %d\n",*n3->adjacent);

    n1->incomingNode = n3;
    n3->outGoingNode = n1;

    printf("Our Outgoing Node is : %s\n",((n3->outGoingNode)->name));

    return 0;
}