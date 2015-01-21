/************************************************************
   Breadth-first search.

   Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/
#ifndef BFS_H
#define BFS_H

typedef struct _vertex {
    int color;
    int d;
    struct _node* adjacent;
} vertex;

typedef struct _node {
    vertex* vert;
    struct _node* next;
} node;

typedef struct _queue {
    node* head;
    node* tail;
} queue;

int bfs (vertex* graph, vertex* v); 
int is_empty (queue* q);
void enqueue (queue* q, vertex* v);
vertex* dequeue (queue* q);


#endif
