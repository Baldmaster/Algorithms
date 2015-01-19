/* C emplementation of merge sort for INT      *
 * using pointers and dynamic memory allocation *
 *                                              *
 * Skupoy Sergey. 2014                          */

#ifndef MERGESORT_H
#define MEGRESORT_H

/* includes */
#include <stdio.h>
#include <stdlib.h>

/*recursive mergesort function */
void merge_sort (int *arr, int length);

/* merge function */
void merge (int *arr, int *left_part, int *right_part, int left_length, int right_length);

#endif /* end of mergesort.h */
