/* Example of using linked list *
 * for any data structure       */

#include "doublylinkedlist.h"

typedef struct _complex {
    int real;
    int im;
} complex;


void display_complex (complex*);
void display_integer (int* );
int compare_complex (complex*, complex*);
int compare_integers (int*, int*);

int main (void) {
    /* create new list of complex numbers and initialize it */
    linked_list c_list;
    initialize_list (&c_list);

    /* create one more list of INTs and initialize it */
    linked_list i_list;
    initialize_list (&i_list);

    /* create some complex numbers */
    complex a;
    a.real = 3;
    a.im = -2;

    complex b;
    b.real = 9;
    b.im = 3;

    complex c;
    c.real = 8;
    c.im = -12;
   
    complex d;
    d.real = 7;
    d.im = -9;

    /* create some integers */
    int x = 9;
    int y = 7;
    int z = 5;
    
    /* add numbers to list */
    add_head (&c_list, &a);
    add_head (&c_list, &b);
    add_tail (&c_list, &c);
    add_tail (&c_list, &d);

    add_head (&i_list, &x);
    add_tail (&i_list, &y);
    add_head (&i_list, &z);
    
    /* try delete, reverse and display functions */
    printf ("\n---list of complex numbers---\n");
    delete (&c_list, (COMPARE)compare_complex, &b);
    reverse_list (&c_list);
    display_list (&c_list, (DISPLAY)display_complex);

    printf ("\n---list of integers---\n");
    reverse_list (&i_list);
    delete (&i_list, (COMPARE)compare_integers, &y);
    display_list (&i_list, (DISPLAY)display_integer);

    return 0;
}
    
void display_complex (complex* num) {
    if (num -> im == 0) {
        printf ("%d;\n", num -> real);
    }
    else {
        printf ("\n%d%ci%d;\n", num -> real,
                num -> im > 0 ? '+' : '-',
                num -> im < 0 ? num -> im * (-1) : num -> im);
    }
}

int compare_complex (complex* a, complex* b) {
    if (a -> real == b -> real && a -> im == b -> im)
        return 0;
    else
        return 1;
}


void display_integer (int* num) {
    printf ("\n%d\n",  *num);
}

int compare_integers (int* a, int* b) {
    if (*a == *b)
        return 0;
    else
        return 1;
}
