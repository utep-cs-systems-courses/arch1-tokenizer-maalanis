#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
int main()
{
  char str[100];
  printf("Enter string\n");
  scanf("%[^\n]", &str);

  List *history = init_history(); // List of history to store strings put
  
  // Program stops asking for strings when "EOF" entered
  while(compare(str, "EOF") != 0)
    {
  
      printf("You have entered %s\n", &str);

      // variables used to tokenize
      int length = strlen(str);
      int length_final = 0;
      int spaces = 0;
      int non_spaces =0;

      for(int i=0; i<length; i++)
	{
	  if(space_char(str[i])>0) // if char is a space
	    spaces++;
	  if(non_space_char(str[i])>0) // if char is not a space
	    non_spaces++;
	  if(str[i] != ' ') // if char is not a space
	    length_final++;
	}
      char *ptr;
      char *next_space;
      ptr = str;
      next_space = word_start(str); // returns a pointer to the start of next strng before a space
      char *copy;
      int word_count = count_words(str); //renturns counter of words entered in string
      copy = copy_str(str, length_final); // makes a copy of the original string
      if(compare(copy, "!*") !=0 && copy[0]-'!' !=0) // adds the string to history list 
	add_history(history, copy);
      
      if(compare(copy, "!*") == 0) // prints the whole history
	print_history(history);
      
      if(copy[0] - '!' == 0 && copy[1]>=48 && copy[1]<=57) // prints history at number
	get_history(history, copy[1]);
      
      char **tokens;
      if(compare(copy, "!*") !=0 && copy[0]-'!' !=0)
	{
	  tokens = tokenize(str);
	  print_tokens(tokens);
	}
      
      printf("%d words\n",word_count); // method to check number os words entered
      char *cop_word = copy_str(str, word_count); 

      printf("Enter string: ");
      scanf(" %[^\n]", &str);
    }
  
}
// true if char is space
int space_char(char c)
{
  if (c == 32 || c == 9|| c == 48){
    return 1;
  }
  return 0;

}
// true if char is not a space
int non_space_char(char c)
{
  if (c == 32 || c == 9 || c == 48)
    {
      return 0;
    }
  return 1;
}

// returns char at begining of next  word
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

//returns char to the end of the word
char *word_terminator(char *str)
{
  while(non_space_char(*str))
    {
      str++;
    }
    return str;
}
//returns int of number of words entered
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

//returns a copy of string with malloc
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
//prints tokenizer
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
//liberates memory from pointers
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

//takes string an organizes on list with pointers
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

//compares chars returns true if they are equal
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
