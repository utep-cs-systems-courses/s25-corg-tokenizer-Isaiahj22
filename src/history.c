#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list->root = NULL;
    return list;

}

void add_history(List *list, char *str){
  Item *newItem = (Item*)malloc(sizeof(Item));
  
  newItem->id = 1;
  newItem->str = str;
  newItem->next = NULL;

  if(list->root == NULL){
    list->root = newItem;
  }else{
    Item *temp = list->root;
    newItem->id = 2;
    while(temp->next){
      newItem->id = newItem->id + 1;
      temp = temp->next;
    }

    temp->next = newItem;

  }

}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while(temp->id != id){
    if(temp->next != NULL){
      temp = temp->next;
    }else{
      printf("Id: %d not in history\n", id);
      return NULL;
    }
  }

  return temp->str;
   
}


void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL){
    printf("ID: %d String: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
  
}


void free_history(List *list)
{
  Item *current = list->root;
  Item *next;

  while(current != NULL){
    next = current->next;
    free(current);
    current = next;

  }

  list->root = NULL;
}
