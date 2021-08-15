#include<stdio.h>  

int main(){
	int no = 100, val ;
        asm ("movl %1, %%ebx;"
             "movl %%ebx, %0;"
         : "=r" (val)
         : "r" (no)
         : "%ebx");
	printf("c= %d\n",val);
	return 0;
} 
