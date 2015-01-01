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
int pop (stack_node_ptr *stack_ptr)
{
    /* create temp ptr and return variable */
    stack_node_ptr temp_ptr;
    int pop_value;

    /* assign top of stack to temp ptr */
    temp_ptr = *stack_ptr;

    /* assign return variable */
    pop_value = (*stack_ptr) -> data;

    /* shift top of stack */
    *stack_ptr = (*stack_ptr) -> next;

    /* free temp pointer */
    free(temp_ptr);

    /* return popped value */
    return pop_value;
}

/* insert new node to stack */
void push (stack_node_ptr *stack_ptr, int data)
{
    /* create new node and allocate memory */
    stack_node_ptr new_node;
    new_node = malloc (sizeof (stack_node));

    /* if memmory is allocated then insert new node to stack */
    if (new_node != NULL) {
        new_node -> data = data;
        new_node -> next = *stack_ptr;
        *stack_ptr = new_node;
    }

    /* if no memory available */
    else
        printf("%d not inserted. No memory available.\n", data);
}

/* print stack data */
void print_stack (stack_node_ptr stack_ptr)
{
    /* if stack is empty show corresponding message */
    if (stack_ptr == NULL)
        printf("The stack is empty. \n\n");

    /* otherwise print stack data */
    else {
        printf("The stack:\n");

        while (stack_ptr != NULL) {
            printf("%d -> ", stack_ptr -> data);
            stack_ptr = stack_ptr -> next;
        }

        printf("NULL\n\n");
    }
}

/* check if stack is empty */
int is_empty_stack (stack_node_ptr stack_ptr)
{
    return stack_ptr == NULL;
}

#endif
