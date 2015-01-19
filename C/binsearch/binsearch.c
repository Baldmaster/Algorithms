#include <stdio.h>
#include <stdlib.h>

#include "binsearch.h"

int binsearch (void* array, void* key, size_t type_size, size_t array_size, COMPARE compare) {
    /* return failure if length is 0 */
    if (array_size == 0)
        return 1;

    /* chek order of array: < 2 - ascending, otherwise descendind */
    int flag = (compare (array, (array + (array_size - 1) * type_size)));

    /* return failure if key value is out of bounds */    
    if ((flag < 2) ?
        compare (array, key) == 2 ||
        compare ((array + (array_size - 1) * type_size), key) == 1 :
        compare (array, key) == 1 ||
        compare ((array + (array_size - 1) * type_size), key) == 2)
        return 1;

    /* indexes of region */
    int from = 0, to = array_size - 1;
    /* current index */
    int curr = array_size / 2;
    
    while (from <= to && curr >= from) {
        /* compare current array index with key */
        switch (flag < 2 ? compare (key, (array + curr * type_size)) :
                           compare ((array + curr * type_size), key)) {
            /* return success if match */
            case 0:
                return 0;
            /* othrewise keep on searching in left or right part */
            case 1:
                to = curr - 1;
                curr = from + (to - from) / 2;
                break;
            case 2:
                from = curr + 1;
                curr = from + (to - from) / 2 + 1;
        }
    }
    
    return 1;
}
