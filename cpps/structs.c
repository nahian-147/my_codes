#include<stdio.h>
#include<stdlib.h>

struct person{
	char name[20];
	char dob[11];
	int salary;
};

struct person* get_person(){
	struct person *P = (struct person*)malloc(sizeof(struct person));
	printf("Name ? : ");
	scanf("%s",P->name);
	printf("Date of Birth ? : ");
	scanf("%s",P->dob);
	printf("Salary ? :");
	scanf("%d",&P->salary);
	return P;
}

void print_person(struct person *p){
	
	printf("name\t%s,\tdob\t%s,\tsalary\t%d bdt.\n",p->name,p->dob,p->salary);
}

int main(){
	struct person n = {"kaziNAHIAN\0","15-10-1995\0",70000};
	struct person *N;
	N = get_person();
	print_person(&n);
	print_person(N);
	//printf("size of person = %ld Bits\nsize of &person = %ld Bits\n",8*sizeof(n),8*sizeof(&n));
	return 0;
}
