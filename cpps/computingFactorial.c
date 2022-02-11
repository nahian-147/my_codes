#include <stdio.h>

long getFactorial(int n){
    long fatorial = 1;
    for(int k=1;k<=n;k++){
        fatorial *= k;
    }
    return fatorial;
}

int main(){
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);

    printf("%ld\n",getFactorial(n));
}