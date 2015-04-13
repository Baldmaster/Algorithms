/************************************************************
   Dijkstra's algorithm. Heap based.


   Skupoy Sergey, sergey.archlinux@gmail.com, 2015
 ************************************************************/



#ifndef DIJKSTRA_H
#define DIJKSTRA_H

/************************************************************
  Vertex
 ************************************************************/
typedef struct _vertex {
    int q_number;
    int name;
    int dist;
    struct _vertex* p;
    struct _node* adj;
} vertex;

/************************************************************
  List node
 ************************************************************/
typedef struct _node {
    int weight;
    vertex* vert;
    struct _node* next;
} node;

/************************************************************
   Heap
 ************************************************************/
typedef struct _bin_heap {
    vertex** data;
    int size;
} bin_heap;


typedef void (*SWAP) (void*, void*);
typedef int (*COMPARE) (const void*, const void*);

void heapify (bin_heap* heap, int index, COMPARE, SWAP);
void build_heap (bin_heap* heap, COMPARE, SWAP);
void sort_heap (bin_heap* heap, COMPARE, SWAP);
int push (node** stack, vertex* v, int w);
int parent (int);
vertex* extract (bin_heap* h, COMPARE compare, SWAP swap);
void change_key (bin_heap* h, vertex* v, SWAP swap);
void dijkstra (bin_heap* heap, COMPARE compare, SWAP swap);

#endif
