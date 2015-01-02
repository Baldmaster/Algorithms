/* C doubly-linked list implementation *
 *                                     *
 * Skupoy Sergey. 2014                 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_node;
    struct node *prev_node;
} list_node, *list_node_ptr;


void insert (list_node_ptr *list_head, int data)
{
    /* create new node and allocate memory */
    list_node_ptr new_node;
    new_node = malloc (sizeof (list_node));

    /* if memory is allocated successfully insert new node */
    if (new_node != NULL) {
        new_node -> data = data;
        new_node -> next_node = *list_head;
        new_node -> prev_node = NULL;
        *list_head = new_node;
    }
    else
        printf("%d not inserted. No memory available.\n", data);
}

void delete (list_node_ptr *list_head, int data)
{
    list_node_ptr prev_ptr, curr_ptr, temp_ptr;

    /* if data == head.data, then set new list head and delete node */
    if (data == (*list_head) -> data) {
        temp_ptr = *list_head;
        *list_head = (*list_head) -> next_node;
        free (temp_ptr);
        printf ("%d deleted successfully\n", data);
    }
    else {
        prev_ptr = *list_head;
        curr_ptr = (*list_head) -> next_node;

	/* find node with data or reach the end of list */
        while (curr_ptr != NULL && curr_ptr -> data != data) {
            prev_ptr = curr_ptr;
            curr_ptr = curr_ptr -> next_node;
        }

	/* if data is present in list, delete that node */
        if (curr_ptr != NULL) {
            temp_ptr = curr_ptr;
            prev_ptr -> next_node = curr_ptr -> next_node;
            free (temp_ptr);
            printf ("%d deleted successfully\n", data);
        }
	else
	    printf ("%d is not present in list.\n", data);
    }
}

/*check if list is empty */
int is_empty_list (list_node_ptr list_head)
{
    return list_head == NULL;
}

/* print list elements */
void print_list (list_node_ptr curr_ptr)
{
    if (curr_ptr == NULL)
        printf("List is empty.\n\n");
    else {
        printf("The list:\n");

        while (curr_ptr != NULL) {
            printf("%d-> ", curr_ptr -> data);
            curr_ptr = curr_ptr -> next_node;
        }
        printf ("NULL\n\n");
    }
}

#endif
