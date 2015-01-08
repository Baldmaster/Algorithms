/* C stack implementation *
 *  using linked list     *
 *                        *
 * Skupoy Sergey. 2014    */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} stack_node, *stack_node_ptr;

/* get data from stack */
int pop (stack_node_ptr *stack_ptr);

/* insert new node to stack */
void push (stack_node_ptr *stack_ptr, int data);

/* print stack data */
void print_stack (stack_node_ptr stack_ptr);

#endif
