#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int main()
{
  char str[100];
  printf("Enter string\n");
  scanf("%[^\n]", &str);

  while(compare(str, "EOF") != 0)
    {
  
      printf("You have entered %s\n", &str);
      int length = strlen(str);
      int length_final = 0;
      int spaces = 0;
      int non_spaces =0;

      for(int i=0; i<length; i++)
	{
	  if(space_char(str[i])>0)
	    spaces++;
	  if(non_space_char(str[i])>0)
	    non_spaces++;
	  if(str[i] != ' ')
	    length_final++;
	}
      char *ptr;
      char *next_space;
      ptr = str;
      next_space = word_start(str);
      char *copy;
      int word_count = count_words(str);
      copy = copy_str(str, length_final);
      char **tokens;
      tokens = tokenize(str);
      print_tokens(tokens);
      
      
      printf("%d words\n",word_count);
      char *cop_word = copy_str(str, word_count);

      printf("Enter string: ");
      scanf(" %[^\n]", &str);
    }
  
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

  while(tokens[i] != NULL)
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
void free_tokens( char** tokens)
{
  char *ptr = *tokens;
  while(ptr !=NULL)
    {
      free(ptr);
      ptr++;
    }
  free(ptr);
}
char **tokenize(char *str)
{
  int word_count = count_words(str);
  char **tokens = malloc (sizeof(char *)*(word_count+1));
  char *beg = str;
  char *end = word_terminator(beg);
  int i =0;
  for(;i<word_count;i++)
    {
      int word_length = end -beg;
      char *token = copy_str(beg, word_length);
      tokens[i] = token;

      beg = word_start(beg);
      end = word_terminator(beg);
    }

  char var = '0';
  char *terminator = &var;
  tokens[i] = terminator;
  return tokens;
}
int compare (char *str1, char *str2)
{
  int i =0;
  while(str1[i] == str2[i])
    {
      if(str1[i]== '\0' && str2[i] == '\0')
	break;

      i++;
    }
  return str1[i] - str2[i];
}
