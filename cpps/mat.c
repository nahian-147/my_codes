#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double** allocate(int r,int c){
	int i;
	double **A = (double**)malloc(r*sizeof(double*));
	for(i=0;i<r;i++){
		*(A+i) = (double*)malloc(c*sizeof(double));
	}
	return A;
}

double** multiply(double** M1, double** M2, int r1, int c1, int r2, int c2){
	double** M;
	double sm;
	M = allocate(r1,c2);
	int i,j,k;
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			sm = 0;
			for(k=0;k<c1;k++){
				sm += M1[i][k]*M2[k][j];
			}
			M[i][j] = sm;
		}
	}
	return M;
}

void print(double** m,int r, int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%3.1lf ",m[i][j]);
		}putchar('\n');
	}
}

double** gaussian(double** M,int r, int c){

}

int main(){
	time_t beg;
	time(&beg);
	double **A,**B,**M;
	
	int r=5000,c=5000;
	A = allocate(r,c);
	B = allocate(c,r);
	M = allocate(r,r);
	
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			A[i][j] = i+j+1;
			B[j][i] = i+j+3;
		}
	}
	
	//print(A,2,2);
	//print(B,2,2);

	M = multiply(A,B,r,c,c,r);
	
	//print(M,200,200);

	time_t end;
	time(&end);
	double df = difftime(end,beg);
	printf("total time = %lf\n",df);
	free(A);
	free(B);
	free(M);
	return 0;
}
