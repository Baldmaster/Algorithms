/************************************************************
  Tarjan's strongly connected components algorithm.


   Skupoy Sergey. sergey.archlinux@gmail.com, 2015.
 ************************************************************/

#ifndef TARJAN_H
#define TARJAN_H

/************************************************************
  Vertex structure.
 ************************************************************/
typedef struct _vertex {
    char name;
    int in_stack;
    int index;
    int low;
    struct _node* adj;
} vertex;

/************************************************************
  List node.
 ************************************************************/
typedef struct _node {
    vertex* vert;
    struct _node* next;
} node;

/************************************************************
  Lists of strongly connected components.
 ************************************************************/
typedef struct _components {
    struct _node* component;
    struct _components* next;
} components;


/************************************************************
   Tarjan function returns a pointer to list of lists of 
   connected vertexes.
 ************************************************************/
components* tarjan (vertex* g, int size);


/************************************************************
   Search for strongly connected vertexes.
 ************************************************************/
int strong_connect (vertex* v, components** c, node** s, int* index);


/************************************************************
  Push ot stack/list.
 ************************************************************/
int push (node** s, vertex* v);


/************************************************************
  Pop from stack.
 ************************************************************/
vertex* pop (node** s);

/************************************************************
   Add component to components list
 ************************************************************/
int add_component (components** comps, node* component);

#endif

