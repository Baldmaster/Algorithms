#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

/* Heapify function */
void heapify (bin_heap* heap, int index, const int size,
              COMPARE compare, SWAP swap) {
    /* getting left and right indexes */
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    /* index with largest [smallest] value */
    int temp = index;

    /* if left child is larger [smaller] than its parent's [index] value  */
    if (left < (heap -> size) &&
        compare (((heap -> data) + left * size), ((heap -> data) +  index * size)))
 
        temp = left;
    else
        temp = index;

    /* if right child is larger [smaller] of temp index value... */
    if (right < (heap -> size) &&
        compare (((heap -> data) + right * size), ((heap -> data) + temp * size)))
        temp = right;

    /* if index node's child is larger [smaller] than index node value then swap them 
       and call heapify function to that node */
    if (temp != index) {
        swap (((heap -> data) + index * size), ((heap -> data) + temp * size));
        heapify (heap, temp, size, compare, swap);
    }
}

/* Buid heap function */
void build_heap (bin_heap* heap, const int size, COMPARE compare, SWAP swap) {
    int i;
    /* call heapify for every node from last but one level to the top of heap */
    for (i = (heap -> size / 2) - 1; i >= 0; i--)
        heapify (heap, i, size, compare, swap);
}

