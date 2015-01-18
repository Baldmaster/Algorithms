/************************************************************
   Binary search.
   
   Skupoy Sergey. sergey.archlinux@gmail.com, 2015.
 ************************************************************/

#ifndef BINSEARCH_H
#define BINSEARCH_H

/************************************************************
  Compare function pointer.
  Return values:
  0 - a == b,
  1 - a < b,
  2 - a > b.
  
 ************************************************************/
typedef int (*COMPARE) (const void* a, const void* b);

/************************************************************
  Search function.
  first two parameters are array and key value pointers,
  next two are size of datatype and size of array,
  the last one is user defined compare function for certain 
  datatype.
   Function example:
   int compare_mydatatype (my_type* a, my_type* b) {
       if (*a -> some_value == b -> some_value)
           return 0; // 0 - success, and so on...
    .......................
   }                               
 ************************************************************/
int binsearch (void* array, void* key,
               size_t type_size, size_t array_size, COMPARE compare);

#endif

