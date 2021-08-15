#include <stdio.h>
int main() {

  char c = 'f';

  switch (c) {

    default: printf("unknown colour ");

    case 'r': case 'R': printf("Red ");

    case 'g': case 'G': printf("Green ");

    case 'b': case 'B': printf("Blue");

  }

}


