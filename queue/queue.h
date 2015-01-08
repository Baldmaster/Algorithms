/* C queue implementation *
 *                        *
 * Skupoy Sergey. 2014    */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} queue_node, *queue_node_ptr;

/* insert value to queue */
void enqueue(queue_node_ptr *head_ptr, queue_node_ptr *tail_ptr, char value)
{
    /* create new node and allocate memory */
    queue_node_ptr new_ptr;
    new_ptr = malloc (sizeof (queue_node));

    /* if memory is allocated */
    if (new_ptr != NULL) {
        new_ptr -> data = value;
        new_ptr -> next = NULL;

        if (is_empty_queue(*head_ptr))
            *head_ptr = new_ptr;
        else
            (*tail_ptr)->next = new_ptr;
        *tail_ptr = new_ptr;
    }
    /* if no memory available */
    else
        printf ("%c not inserted. No memory available.\n", value);
}

/* dequeue */
char dequeue (queue_node_ptr *head_ptr, queue_node_ptr *tail_ptr)
{
    char value;
    queue_node_ptr temp_ptr;

    value = (*head_ptr) -> data;
    temp_ptr = *head_ptr;
    *head_ptr = (*head_ptr) -> next;

    if (*head_ptr == NULL)
        *tail_ptr = NULL;

    free(temp_ptr);
    return value;
}


int is_empty_queue (queue_node_ptr head_ptr)
{
    return head_ptr == NULL;
}

void print_queue (queue_node_ptr current_ptr)
{
    if (current_ptr == NULL)
        printf ("Queue is empty\n");
    else {
        printf ("The queue is : \n");

        while (current_ptr != NULL) {
            printf ("%c --> ", current_ptr -> data);
            current_ptr = current_ptr -> next;
        }
        printf ("NULL\n\n");
    }
}

#endif
