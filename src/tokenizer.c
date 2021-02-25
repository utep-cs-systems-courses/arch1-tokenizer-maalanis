#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int main()
{
  char z[100];
  printf("Enter string\n");
  scanf("%[^\n]", &z);
  printf("You have entered %s\n", &z);
}

int space_char(char c)
{
  if (c == 32 || c == 9|| c == 48){
    return 1;
  }
  return 0;

}
int non_space_char(char c)
{
  if (c == 32 || c == 9 || c == 48)
    {
      return 0;
    }
  return 1;


}
