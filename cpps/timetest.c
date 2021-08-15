#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 1000

int main(){
	time_t now;
	time(&now);
	
	struct tm mbeg;
	mbeg = *localtime(&now);
	mbeg.tm_hour = 0;
	mbeg.tm_min = 0;
	mbeg.tm_sec = 0;
	mbeg.tm_mday = 1;
 	
	double dff = difftime(now,mktime(&mbeg))/3600;
	printf("%f hours\n",dff);
	return 0;
}
