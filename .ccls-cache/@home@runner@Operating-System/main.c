#include <stdio.h>
// #include "list.c"
#include "list.h"

int main() {
    list_t* list = list_alloc();
    // list->next = NULL;
    list_add_to_front(list, 1);
    list_add_to_front(list, 2);
    list_add_to_front(list, 3);
    list_print(list);
    // list_print(list);
 
    // Delete any position from list
    // list_remove_at_index(&list, 1);
    // list_print(list);
    return 0;
}