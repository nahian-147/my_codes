#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int main(){
	int *p,i;
	p = (int*)malloc(SIZE*sizeof(int));	
	for(i=0;i<SIZE;i++){
		*(p+i) = 81%(i+1);
	}
	for(i=0;i<SIZE;i++){
		printf("%d %d\n",i+1,*(p+i));
	}
	putchar('\n');
	return 0;
}
