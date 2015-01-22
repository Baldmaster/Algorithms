/************************************************************
   Depth-first search.
   

   Skupoy Sergey. sergey.archlinux@gmail.com, 2015.
 ************************************************************/

#ifndef DFS_H
#define DFS_H

typedef struct _node {
    struct _vertex* vert;
    struct _node* next;
} node;

typedef struct _vertex {
    int color;            /* color. 2 - white, 1 - gray, 0 - black */
    int disc;             /* discovery time */
    struct _vertex* pred; /* vertex predecessor */
    struct _node* adj;    /* adjacent vertexes list */
} vertex;

/************************************************************
  DFS function. g - array of graph vertexes, 
                l - length of array
 ************************************************************/
int dfs (vertex* g, int l);

/************************************************************
  Visit function. time - discovery time.
 ************************************************************/
void dfs_visit (vertex* v, int* time);

#endif
