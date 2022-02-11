#include <stdio.h>
#include <stdlib.h>

int getSumOfDigits(int n){
    if(n<10 && n>=0){
        return n;
    }else{
        return n%10 + n/10;
    }
}

int main(){
    int sum = 0;

    int k = 1;
    do{
        if(k%2 == 0){
            sum += getSumOfDigits(k);
            printf("%d %d \n",k,getSumOfDigits(k));
        }
        k++;
    }while (k <= 30);

    printf("Sum = %d \n",sum);

    return 0;
}