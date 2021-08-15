#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[] ){
	int p;
	if(argc>1) p = atoi(argv[1])*atoi(argv[1]);
	printf("%d\n",p);
	return 0;
}
