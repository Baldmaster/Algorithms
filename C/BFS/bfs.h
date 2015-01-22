/************************************************************
   Breadth-first search.

   Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/
#ifndef BFS_H
#define BFS_H

/************************************************************
  Vertex structure. 
   color values: 2 - white, 1 - gray, 0 - black.
 ************************************************************/
typedef struct _vertex {
    int color;
    int distance; /* distance to initial vertex */
    struct _node* adjacent;
} vertex;

/************************************************************
   Node structure.
 ************************************************************/
typedef struct _node {
    struct _vertex* vert;
    struct _node* next;
} node;

/************************************************************
   Queue structure.
 ************************************************************/
typedef struct _queue {
    node* head;
    node* tail;
} queue;

/************************************************************
   BFS function.
 ************************************************************/
int bfs (vertex* v);

/************************************************************
   Queue functions.
 ************************************************************/
int is_empty (queue* q);
void enqueue (queue* q, vertex* v);
vertex* dequeue (queue* q);


#endif
