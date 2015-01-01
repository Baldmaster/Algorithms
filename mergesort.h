/* My emplementation of merge sort for INT      *
 * using pointers and dynamic memory allocation *
 *                                              *
 * Skupoy Sergey. 2014                          */

#ifndef MERGESORT_H
#define MEGRESORT_H

/* includes */
#include <stdio.h>
#include <stdlib.h>

void merge_sort (int* array, int array_length);
void merge (int* array, int* left_part, int* right_part,
	    int right_length, int left_length);


/*recursive mergesort function */
void merge_sort (int *arr, int length)
{
    /* if array consists of more then one element... */
    if (length > 1) {
        /* getting index of middle element and  *
         * setting size for left and right part */
	int left_length = length / 2;
	int right_length = length - left_length;

        /* allocate memory for left and right part *
         * and filling them from parrent array     */
	int *left_part = malloc (left_length * sizeof (int));
	int *right_part = malloc (right_length * sizeof (int));
	
        int i = 0, j = 0;

	while (i < left_length) { 
	    *(left_part + i) = *(arr + i);
	    i++;
	}

	while (i < length) {
	    *(right_part + j++) = *(arr + i);
	    i++;
	}

        /* recursive call of sort function for right and left part *
	 * until size is more than 1                               */
	merge_sort (right_part, right_length);
	merge_sort (left_part, left_length);
        
        /* merging two arrays into one */
        merge (arr, left_part, right_part, right_length - 1, left_length - 1);
        
        /* freeing memory */
	free (left_part);
	free (right_part);
    }
    else
	return;
}


void merge (int *arr, int *left_part, int *right_part, int right_length, int left_length)
{
    int len = right_length + left_length + 1;
    while (len >= 0) {
        /* if one of arrays is out of bounds       *
         * write the rest of another one to arr... */
	if (right_length < 0 || left_length < 0 ) {
	    if (right_length < 0)
		while (left_length >= 0) 
		    *(arr + len--) = *(left_part + left_length--);
	    else 
		while (right_length >= 0)
		    *(arr + len--) = *(right_part + right_length--);
      	}
        /* otherwise compare elements and write to arr */
	else {
	    if (*(left_part + left_length) > *(right_part + right_length)) 
		*(arr + len--) = *(left_part + left_length--);
	    else *(arr + len--) = *(right_part + right_length--);
        }
    }
}

#endif /* end of mergesort.h */
