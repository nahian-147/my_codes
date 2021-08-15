#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc,char *argv[]){
	printf("type\tsize\tmax\n");
	printf("short\t%ld\t%d\n",sizeof(short));
	printf("int\t%ld\t%d\n",sizeof(int),INT_MAX);
	printf("long\t%ld\t%ld\n",sizeof(long int),LONG_MAX);
	printf("uint\t%ld\t%u\n",sizeof(unsigned int),UINT_MAX);
	printf("lint\t%ld\t%lu\n",sizeof(unsigned long int),ULONG_MAX);

	printf("int*\t%ld\n",sizeof(int*));
	printf("lint*\t%ld\n",sizeof(long int*));
	printf("char*\t%ld\n",sizeof(char*));
	return 0;
}
