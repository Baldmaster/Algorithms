#include "doublylinkedlist.h"

/* list initialization */
void initialize_list (linked_list *list) {
    list -> head = NULL;
    list -> tail = NULL;
}

/* add node to head */
linked_list* add_head(linked_list *list, void *data){
    /* create new node and allocate memory */
    list_node *node = malloc(sizeof(*node));

    /* check if memory is available */
    if (!node)  return NULL;

    /* add new node to head */
    node->data = data;
    node->prev = NULL;
    if (list->head){
        list->head->prev = node;
        node->next = list->head;
    }else{
        list->tail = node;
        node->next = NULL;
    }
    list->head = node;

    return list;
}

/* add node to the end of list */
linked_list* add_tail(linked_list *list, void *data){
    list_node *node = malloc(sizeof(*node));

    /* check if memory is available */
    if (!node)  return NULL;

    /* add new node to the end of list */
    node->data = data;
    node->next = NULL;
    if (list->head){
        list->tail->next = node;
        node->prev = list->tail;
    }else{
        list->head = node;
        node->prev = NULL;
    }    
    list->tail = node;

    return list;
}

/*delete node if it contains "data" value */
void delete (linked_list *list, COMPARE compare, void *data) {
    list_node *find = NULL;
    for (find = list->head; find && compare(find->data, data); find = find->next);

    if (find){
        if (find->prev)  find->prev->next = find->next;
        if (find->next)  find->next->prev = find->prev;
        if (find == list->head)  list->head = find->next;
        if (find == list->tail)  list->tail = find->prev;
        free(find);
        printf ("\nNode deleted successfully\n");
    }else{
        printf ("\nNode is not found\n");
    }
}

/* show list */
void display_list (linked_list *list, DISPLAY display) {
    if (list -> head == NULL) {
        printf ("\nList is empty!\n");
    }
    else {
        printf ("\nLinked list:\n");
    
        list_node *current = list -> head;

        while (current != NULL) {
            display (current -> data);
            current = current -> next;
        }

        printf ("\n__end of list__\n");
    }
}

/* reverse list */
void reverse_list (linked_list *list) {
    list_node *current = list -> head;
    list_node *prev = NULL;
    list_node *next = current;

    /* reassign "next" pointer for every node */
    while (current != NULL) {
        next = current -> next;
        current -> next = prev;
        current -> prev = next;
        prev = current;
        current = next;
    }

    /* swap head and tail pointers */
    current = list -> head;
    list -> head = list -> tail;
    list -> tail = current;
}
