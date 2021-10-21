#include<stdio.h>
int main() {

  char c = 'r';

  switch (c) {

    case 'r': case 'R': printf("Red \n");

    case 'g': case 'G': printf("Green \n"); break;

    case 'b': case 'B': printf("Blue \n");

    default: printf("unknown colour \n");
  }

}
