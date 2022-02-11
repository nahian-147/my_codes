#include <stdio.h>
#include <stdlib.h>

void calculateSum(int *n1,int *n2,int *sum){
    *sum = *n1 + *n2;
}

int main(){

    int *a,*b,*sum;
    
    a = (int*) malloc(sizeof(int*));
    b = (int*) malloc(sizeof(int*));
    sum = (int*) malloc(sizeof(int*));

    *a = 7;
    *b = 8;

    calculateSum(a,b,sum); // calling by reference (pointer)

    printf("%d\n",*sum);

    return 0;
}