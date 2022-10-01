// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include<stdio.h>
#include<stdlib.h>
#include "list.h"

list_t *list_alloc(){
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}
void list_free(list_t *l){
  node_t* temp;
  node_t* next;
  temp = l->head;
  while(temp!=NULL){
    next = temp->next;
    free(temp);
    temp = next;
  }
  free(l->head);
  l->head =NULL;
  }

node_t *node_alloc(){
  node_t* list = (node_t*)malloc(sizeof(list_t));
  list->next = NULL;
  return list;
}

void node_free(node_t *n){
  free(n);
}

/* Prints the list in some format. */
void list_print(list_t *l){
  node_t *curr = l->head;
   	while ( curr != NULL) {
        printf("%d ", curr-> value);
        curr = curr-> next;
    }
}

/* Returns the length of the list. */
int list_length(list_t *l){
  int res = 0;
  node_t *curr = l->head;
  while (curr) {
    res++;
    curr= curr->next;
    }
return res;
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value){
   node_t* curr = l->head; 
    while (curr != NULL) {
        if (curr-> value == value)
            return true;
        curr = curr->next;
    }
    return false;
}

/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(list_t *l, int index){
  node_t* curr = l-> head;
  int counter = 0;
  while (curr) {
    if (counter == index){
      return curr->value; 
    }
    counter++;
    curr = curr->next;
    }
  return -1; 
}

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(list_t *l, elem value){
  int index;
  node_t *curr = l->head;
  index = 0;
  curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return index;
   }
    else{
      curr = curr->next;
      index ++;
    }
}
  if (curr->value == value) {
      return index;
   } 
}

// /* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value){
  node_t* new_node = node_alloc();
  node_t *last = l->head; 
  if (l->head == NULL){
    new_node->value = value;
    l->head = new_node;
    }
  else{
    while (last->next != NULL){
      last = last->next;
    }
    if(last->next == NULL){
      new_node->value = value;
      last->next = new_node;
    }
  }
  
     
}

void list_add_to_front(list_t *l, elem value){
  if (l->head == NULL) {
    node_t* new_node = node_alloc();
    new_node->value = value;
    l->head = new_node;
    }
  else {
    node_t* new_node = node_alloc();
    new_node->value = value;
    node_t* temp = l->head;
    l->head = new_node;
    new_node->next = temp;
      }  
}

void list_add_at_index(list_t *l, elem value, int index){
  node_t *new_node = node_alloc();
  new_node->value = value;
  node_t *curr = l->head;
  
  int counter = 0;
  int next_count = counter + 1;
  if(index == 0){
    list_add_to_front(l,value);
  }
  else{
    while(next_count != index){
    counter += 1;
    curr = curr->next;
  }
    }
  node_t *t = curr->next;
  curr->next = new_node;
  new_node->next = t;
  
}

/* Methods for removing from the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_back(list_t *l){
  if (l->head == NULL){
    return -1;
    }
  else {
    node_t *prev = l->head;
    node_t *curr = l->head->next;
    while (curr->next) {
      curr = curr->next;
      prev = prev->next;
    }
    if (curr->next == NULL) {
        prev->next = NULL;
     
      }

  }
  
  }

elem list_remove_from_front(list_t *l){
  node_t *temp = l->head;
  if (l->head == NULL){
    return -1;
  }
  else {
    temp = temp->next;
    l->head = temp;
    }
}

elem list_remove_at_index(list_t *l, int index){
  node_t* temp;
  node_t* prev;
  int c = 0;
  prev = node_alloc();
   if(index == 0){
    list_remove_from_front(l);
  }
  else{
    while(c != index){
      prev = temp;
      temp = temp->next;
      c +=1;
    }
    node_t *s = temp->next;
    prev->next = s;
  }
  return -1;
}

