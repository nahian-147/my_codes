#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){

	int a = 6;
	int b = 8;
	int *ip;

	ip = &a;
	printf("a = %d\n",*ip);
	ip = &b;
	printf("b = %d\n",*ip);

	double c = 6.6;
	double d = 7.9;
	double *dp;

	dp = &c;
	printf("c = %lf\n",*dp);
	dp = &d;
	printf("d = %lf\n",*dp);

	char S[10];
	char *s;

	s = S;

	scanf("%s",S);
	printf("%s\n",s);
	
	char *p[10];
	p[0] = "kaziNAHIAN\0";
	p[1] = "kaziFARZANA\0";
	p[2] = "JULI\0";
	p[3] = "PROVAT\0";

	printf("%s and %s love each-other.\n",p[0],p[1]);

	printf("%s and %s love each-other.\n",p[2],p[3]);

	int *iP, i, A[10];
	for(i=0;i<5;i++){
		A[i] = i*i-i+3;
	}
	iP = A;
	for(i=0;i<5;i++){
		printf("%d\n",(*iP)*2+1);
		iP++;
	}
	return 0;
}
