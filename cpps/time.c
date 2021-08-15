#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 1000

int main(){

	int i,j;
	int *A[size];
	
	time_t beg;
	time(&beg);
	
	for(i=0;i<size;i++){
		A[i] = (int*)malloc(size*sizeof(int));
		for(j=0;j<size;j++){
			*(A[i]+j) = i+j;
	}}
	time_t end;
	time(&end);

	double 	df = difftime(end,beg);
	printf("%f\n",df);
	
	free(*A);
	return 0;
}
