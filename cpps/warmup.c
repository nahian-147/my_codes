#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

void oprtarr(int *p,int size){

	int j;
	for(j=0;j<size;j++){
		int q = *(p+j);
		*(p+j) = q*q -2*q +5;
	}
}

void oprtmat(int *b[],int row){
	int i,j,v;
	for(i=0;i<row;i++){
		j = 0;
		while(*(b[i]+j) != INT_MAX){
			v = *(b[i]+j);
			*(b[i]+j) = v*v + 3*v -1;
			j++;
		}
	}
	printf("\nChange Function : v = v*v + 3*v -1\n");
}

void prntmat(int *b[],int row){
	int i,j;
	putchar('\n');
	for(i=0;i<row;i++){
		j = 0;
		while(*(b[i]+j) != INT_MAX){
			printf("%4d ",*(b[i]+j));
			j++;
		}
		putchar('\n');
	}
}


void prntarr(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%02d ",*(arr+i));
	}
	putchar('\n');
}

int main(int argc,char *argv[]){
	
	time_t now;
	time(&now);

	int i,j,r,c;
	
	if(argc == 2)
		r = atoi(argv[1]);
	else if(argc == 3){
		r = atoi(argv[1]);
		c = atoi(argv[2]);
	}
	else{
		r = 9;
		c = 9;
	}

	int A[5] = {1,2,3,4,5};
	int *mtrx[r];
	
	for(i=0;i<r;i++){
		mtrx[i] = (int*)malloc(c*sizeof(int));
		for(j=0;j<c;j++){
			*(mtrx[i]+j) = i+j+1;
		}*(mtrx[i]+c) = INT_MAX;
	}
	
	prntarr(A,5);
	oprtarr(A,5);
	prntarr(A,5);

	prntmat(mtrx,r);
	oprtmat(mtrx,r);
	prntmat(mtrx,r);


	int *C[r];
	for(i=1;i<=r;i++){
		C[i-1] = (int*)malloc((i+1)*sizeof(int));
		for(j=0;j<i;j++){
			*(C[i-1]+j) = i+j;
		}*(C[i-1]+i) = INT_MAX;
	}
	
	prntmat(C,r);
	oprtmat(C,r);
	prntmat(C,r);

	time_t then;
	time(&then);
	double d = difftime(then,now);
	printf("\f%f \n",d);
	return 0;
}
