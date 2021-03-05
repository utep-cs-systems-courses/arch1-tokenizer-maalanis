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
  List *ptr = list;
  Item *tmp = ptr->root;
  while(tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = (Item *) malloc (sizeof(Item));
  tmp->next->id = tmp->id+1;
  tmp->next->str = str;
  if(list->root->str == NULL)
    {
      list->root = list->root->next;
    }
  printf("String inserted: %s \n", tmp->next->str);

}
