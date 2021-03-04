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
  int word_count = count_words(z);
  printf("%d words\n",word_count);
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

char *word_start(char *str)
{
  char *ptr = str;
  while(non_space_char(*ptr))
    {
      *ptr++;
    }
  while(space_char(*ptr))
    {
      *ptr++;
    }
  return ptr;
}

char *word_terminator(char *str)
{
  while(non_space_char(*str))
    {
      str++;
    }
    return str;
}
int count_words(char *str)
{
  int counter = 0;
  char previous = '0';
  int i = 0;
  if(non_space_char(str[0])==1)
    counter++;
  while(str[i] != '\0')
    {
      if(str[i] != ' ' && previous == ' ')
	counter++;
      previous = str[i];
      i++;
    }
  return counter;
}
char *copy_str(char *inStr, short len)
{
  char *new_word;
  new_word =(char *) malloc(len+1);

  int i=0;
  for(;i<len+1;i++)
    {
      new_word[i] = inStr[i];
    }
  new_word[i] = '\0';
  return new_word;
}
void print_tokens(char **tokens)
{
  int i=0;
  int j=0;

  while(tokens[i][j] != NULL)
    {
      printf("token#%d: ", i);
      while(tokens[i][j] != '\0')
	{
	  printf("%c", tokens[i][j]);
	  j++;
	}
      printf("\n");
      i++;
      j=0;
    }
  printf("\n");
}
