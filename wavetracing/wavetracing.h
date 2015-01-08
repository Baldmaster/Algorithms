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
   Return values:
   0 - success, 
   1 - path not found, 
   2 - adding node failure (no memory available).
 ************************************************************/
int find_path (unsigned char*, int, int, wave_node*, wave_node*);

/************************************************************
   Show path function. First argument is a pointer to 
  two-dimensional array. Two next are array dimensions.
  Two last are coordinates of final point. The function is called
  if find_path is succeded.
************************************************************/
void show_path (unsigned char* maze, int width, int height, int x, int y);

/************************************************************
   Insert new node into wavefront points list.
   Return values:
   0 - success, 1 - failure
 ************************************************************/
int insert (wave_node**, int, int);

/************************************************************
   Delete node from wavefront points list.
 ************************************************************/
void delete (wave_node**, wave_node**);

#endif
