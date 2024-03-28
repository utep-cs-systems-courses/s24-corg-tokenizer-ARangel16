#include "history.h"
#include "stdio.h"
#include "stdlib.h"

int main(){}


int string_length(char str[]){

  int i;
  for(i=0;str[i] != '\0'; ++i);
  return i;

}

List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list ->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *new_item = (Item*)malloc(sizeof(Item));
  // Set item id

  new_item->id = (list->root == NULL) ? 1 : list->root->id + 1;



  // Allocate memory for the string and copy its contents

  int length = 0;

  while (str[length] != '\0') {

    length++;

  }
  new_item->str = (char*)malloc((length + 1) * sizeof(char));
  for (int i = 0; i <= length; i++) {

    new_item->str[i] = str[i];

  }



  new_item->next = NULL;



  // Add new item to the end of the list

  if (list->root == NULL) {

    list->root = new_item;

  } else {

    Item *current = list->root;

    while (current->next != NULL) {

      current = current->next;

    }

    current->next = new_item;

  }

}//end of add historyB

char *get_history(List *list, int id) {

  Item *current = list->root;

  while (current != NULL) {

    if (current->id == id) {

      return current->str;

    }

    current = current->next;

  }

  return NULL;

}void print_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    printf("%d: %s\n", current->id, current->str);

    current = current->next;

  }

}


void free_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    Item *temp = current;

    current = current->next;

    free(temp->str);

    free(temp);

  }

  free(list);

}
