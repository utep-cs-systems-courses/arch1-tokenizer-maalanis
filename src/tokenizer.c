#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  char z[100];
  printf("Enter string\n");
  scanf("%[^\n]", &z);
  printf("You have entered %s\n", &z);
}
