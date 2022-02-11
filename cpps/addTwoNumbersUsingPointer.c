#include <stdio.h>
#include <stdlib.h>

int main(){

    int *pointer1,*pointer2,sum;

    pointer1 = (int*) malloc(sizeof(int*));
    pointer2 = (int*) malloc(sizeof(int*));

    printf("Enter First Number\n");
    scanf("%d",pointer1);

    printf("Enter Second Number\n");
    scanf("%d",pointer2);
    
    sum = (*pointer1) + (*pointer2);

    printf("Sum = %d\n",sum);

    return 0;
}