#include <stdio.h>
#include <stdlib.h>

#include "bfs.h"

int bfs (vertex* graph, vertex* v) {
    queue q;
    q.head = NULL;
    q.tail = NULL;
    enqueue (&q, v);
    v -> color = 1;
    while (is_empty (&q)) {
        vertex* u = dequeue (&q);
        for (node* i = u -> adjacent; i ; i = i -> next) {
            if (i -> vert -> color == 2) {
                i -> vert -> color = 1;
                i -> vert -> d = (u -> d) + 1;
                enqueue (&q, i -> vert);
            }
        }
        u -> color = 0;
    }
    return 0;
}

int is_empty (queue* q) {
    if (q -> head)
        return 1;
    else
        return 0;
}

void enqueue (queue* q, vertex* v) {
    node* new_node = (node*) malloc (sizeof (node));
    new_node -> vert = v;
    new_node -> next = NULL;
    
    if (q -> head == NULL){
        q -> head = new_node;
    }
    else {
        q -> tail -> next = new_node;
    }
    q -> tail = new_node;
}

vertex* dequeue (queue* q) {
    vertex* v = q -> head -> vert;
    node* temp = q -> head;

    q -> head = q -> head -> next;
    
    free (temp);
    return v;
}


