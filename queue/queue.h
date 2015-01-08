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
void enqueue(queue_node_ptr *head_ptr, queue_node_ptr *tail_ptr, char value);

/* dequeue */
char dequeue (queue_node_ptr *head_ptr, queue_node_ptr *tail_ptr);

/* check queue for emptiness */
int is_empty_queue (queue_node_ptr head_ptr);

/* display queue nodes */
void print_queue (queue_node_ptr current_ptr);

#endif
