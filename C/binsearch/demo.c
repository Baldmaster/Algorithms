/************************************************************
  Binary search demo.
  Any user defined datatype can be searched. You only need to
  implement COMPARE function. And don't forget to sort array
  before searching!. 
 ************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "binsearch.h"

typedef struct test {
    int val;
} test;

int compare (test*, test*);

int main (void) {
    test arr[5];
    arr[0].val = 3;
    arr[1].val = 4;
    arr[2].val = 5;
    arr[3].val = 6;
    arr[4].val = 7;

    test arr2[5];
    arr2[0].val = 19;
    arr2[1].val = 16;
    arr2[2].val = 9;
    arr2[3].val = 3;
    arr2[4].val = 1;
 
    /* search value */
    test t;
    t.val = 5;
    
    printf ("\n ------ search in ascending order array ------ \n");
    
    if (binsearch (arr, &t, sizeof (arr[0]),
                   sizeof (arr) / sizeof (arr[0]), (COMPARE) compare))
        printf ("Not Found!\n");
    else
        printf ("Found\n");

    printf ("\n ------ search in descending order array ------ \n");

    if (binsearch (arr2, &t, sizeof (arr2[0]),
                   sizeof (arr2) / sizeof (arr2[0]), (COMPARE) compare))
        printf ("Not Found!\n");
    else
        printf ("Found\n");
}

int compare (test* a, test* b) {
    return (a -> val == b -> val) ? 0 : (a -> val < b -> val) ? 1 : 2;
}

