#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history()
{
  List *head = NULL;
  head = (List *) malloc (sizeof(List));

  head->root= (Item *) malloc (sizeof(Item));
  return head;

}
void add_history(List *list, char *str)
{
  

}
