/************************************************************
   Lee algorithm.
   In order not to check all points on every iteration
   linkedlist is used for saving wavefront points.

 ************************************************************/
#ifndef WAVETRACING_H
#define WAVETRACING_H

#include <stdio.h>
#include <stdlib.h>

/************************************************************
 List node structure.
 x, y coordinate.
 next, prev - next and previous nodes.
************************************************************/
typedef struct _wave_node {
    int x;
    int y;
    struct _wave_node *next;
    struct _wave_node *prev;
} wave_node;


/************************************************************
  Delete all list nodes. Gets first node of list as argument.
************************************************************/
void empty_wavefront (wave_node**);

/************************************************************
   Find path function. First argument is a pointer to
 two-dimensional array. two next are width and height values.
 BE CAREFULL WITH POINTERS. Check correctness of width and 
 height values. Two last are start and target node (point), 
 check their values!
 ************************************************************/
int find_path (int*, int, int, wave_node*, wave_node*);

/************************************************************
   Insert new node into wavefront points list.
 ************************************************************/
int insert (wave_node**, int, int);

/************************************************************
   Delete node from wavefront points list.
 ************************************************************/
void delete (wave_node**, wave_node**);

#endif
