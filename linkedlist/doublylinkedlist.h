/* C linked list implementation.              *
 * any data type acceptable.                  *
 * Functions for comparing and showing        *
 * type variables must be defined separately. *
 *                                            *
 * Skupoy Sergey. 2014                        */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

/* function pointer to compare and show functions *
 *                                                */
typedef int (*COMPARE) (void*, void*);
typedef void (*DISPLAY) (void*);

/* node structure */
typedef struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
} list_node;

/* list structure */
typedef struct _linked_list {
    list_node *head;
    list_node *tail;
} linked_list;

/* list initialization */
void initialize_list (linked_list *list);

/* add node to head */
linked_list* add_head (linked_list *list, void *data);

/* add node to the end of list */
linked_list* add_tail (linked_list *list, void *data);

/*delete node if it contains "data" value */
void delete (linked_list *list, COMPARE compare, void *data);

/* show list */
void display_list (linked_list *list, DISPLAY display);

/* reverse list */
void reverse_list (linked_list *list);
#endif
