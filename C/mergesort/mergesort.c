#include "mergesort.h"

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
        merge (arr, left_part, right_part, left_length, right_length);
        
        /* freeing memory */
	free (left_part);
	free (right_part);
    }
    else
	return;
}


void merge (int *arr, int *left_part, int *right_part, int left_length, int right_length)
{
    int len = right_length + left_length;
    
    while (len) {
        /* if one of two arrays reached the beginning *
         * write the rest of another one to arr...    */
	if (!right_length || !left_length) {
	    if (!right_length)
		while (left_length) 
		    *(arr + --len) = *(left_part + --left_length);
	    else 
		while (right_length)
		    *(arr + --len) = *(right_part + --right_length);
      	}
	
        /* otherwise compare elements and write to arr */
	else {
	    if (*(left_part + (left_length - 1)) > *(right_part + (right_length - 1))) 
		*(arr + --len) = *(left_part + --left_length);
	    else *(arr + --len) = *(right_part + --right_length);
        }
    }
}
