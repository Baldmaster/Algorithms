/************************************************************
   Quicksort.

   Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdlib.h>

typedef int (*COMPARE) (const void*, const void*);
typedef void (*SWAP) (void*, void*);


void quicksort (void* array, size_t type_size, int p, int r, COMPARE compare, SWAP swap);
int partition (void* array, size_t type_size, int p, int r, COMPARE compare, SWAP swap);



#endif
