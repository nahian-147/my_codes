#include<stdio.h>
#include<stdlib.h>

double** allocate(int r,int c){
	
	int i;
	double **A = (double**)malloc(r*sizeof(double*));
	for(i=0;i<r;i++){
		*(A+i) = (double*)malloc(c*sizeof(double));
	}
	return A;
}

int main(){
    FILE *input;
    char get_char;
    input = fopen("myimage.bmp", "rb");
    while((get_char=fgetc(input))!= EOF){

    }
    fclose(input);
}