/************************************************************
  Binary heap. C implementation.


  Skupoy Sergey. sergey.archlinux@gmail.com,   2015
************************************************************/

#ifndef HEAP_H
#define HEAP_H


/************************************************************
  Function pointers to swap and compare functions.
  Functions for swapping and comparing must be implemented
  separately for every certain datatype.
 ************************************************************/
typedef void (*SWAP) (void*, void*);
typedef int (*COMPARE) (const void*, const void*);

/************************************************************
  bin_heap structure
 ************************************************************/
typedef struct _bin_heap {
    void* data;
    int size;
} bin_heap;

/************************************************************
 Heapify function. 
  first argument - pointer to bin_heap,
  second - index from wich to heapify,
  third - size of datatype in bytes,
  last two are compare and swap function pointers
 ************************************************************/
void heapify (bin_heap* heap, int index, const int type_size, COMPARE, SWAP);

/************************************************************
 Build heap function. 
 ************************************************************/
void build_heap (bin_heap* heap, const int type_size, COMPARE, SWAP);

#endif
