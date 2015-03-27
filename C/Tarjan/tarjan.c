#include <stdio.h>
#include <stdlib.h>

#include "tarjan.h"

components* tarjan (vertex* g, int size) {
    /* list of components */
    components* comp = NULL;

    /* depth index value */
    int index = 1;

    /* stack */
    node* stack = NULL;

    /* process all undiscovered vertexes */
    for (int i = 0; i < size; i++) {        
        if (!g[i].index) {
            strong_connect (&g[i], &comp, &stack, &index);
        }
    }
    return comp;
}

int strong_connect (vertex* v, components** comp, node** stack, int* index) {
    v -> index = *index;
    /* low is the smallest index of every node reachable from v, including v */
    v -> low = *index; 
    (*index)++;
    
    node* new_node = NULL;
    vertex* temp = NULL;
    push (stack, v);
    v -> in_stack = 1;

    /* traverse adjacent vertexes */
    for (node* i = v -> adj; i; i = i -> next) {
        /* if vertex is not visited */
        if ((i -> vert -> index) == 0) {
            /* call strong_connect recursively */
            strong_connect (i -> vert, comp, stack, index);
            /* check low index of adjacent node, if it is
               lower than predecessor low index, 
               set predecessor -> low to that value */ 
            if ((i -> vert -> low) < v -> low)
                v -> low = (i -> vert -> low);
        }
        /* if vertex is in list */
        else if (i -> vert -> in_stack) {
            /* check index of adjacent node, if it is
               lower than predecessor low index, 
               set predecessor -> low to that value */ 
            if ((i -> vert -> index) < (v -> low))
                v -> low = i -> vert -> index;
        }
    }

    /* if root vertex reached, create list of strongly connected vertexes */
    if (v -> low == v -> index) {
        do {
            temp = pop (stack);
            temp -> in_stack = 0;
            push (&new_node, temp);
        } while (v != temp);
        /* add component to component list */
        add_component (comp,  new_node);
    }
    return 0;
}

int add_component (components** c, node* n) {
    components* new_comp = (components*) malloc (sizeof (components));
    new_comp -> component = n;          
    if (!*c)
        new_comp -> next = NULL;
    else
        new_comp -> next = *c;
    *c = new_comp;
    return 0;
}

int push (node** stack, vertex* v) {
    node* new_node = (node*) malloc (sizeof (node));

    if (!new_node) {
        printf ("No memory!\n");
        return 1;
    }
    
    new_node -> vert = v;

    if (*stack)
        new_node -> next = *stack;
    else
        new_node -> next = NULL;

    *stack = new_node;
    
    return 0;
}

vertex* pop (node** stack) {
    if (*stack) {
        node* temp = *stack;
        vertex* v = temp -> vert;
        *stack = (*stack) -> next;
        free (temp);
        return v;
    }
    else
        return NULL;
}


