/************************************************************
Binary search tree.
Example of using different data structures.
************************************************************/

#include "bst.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

/* Simple employee structure */
typedef struct _employee {
    char name[32];
    unsigned char age;
} employee;

void display_integer (int*);
void display_employee (employee*);
int compare_integers (int*, int*);
int compare_employees (employee*, employee*);

int main (void) {
    srand (time (NULL));
    int j;
    /* sample array of names */
    char* names[32] = {
	"Anna",
	"Alex",
	"Bob",
	"Bella", 
	"Chuck", 
	"Caroline", 
	"Daniel", 
	"Diana", 
	"Eve", 
	"Fred",
	"Gillian", 
	"Ivor",
	"Jane",
	"Jane",
	"Karl",
	"Liza",
	"Mike",
	"Mike",
	"Rita",
	"Tom"
    };

    /* sample array of age values */
    unsigned char ages[SIZE] = { 22, 31, 34, 25, 28, 34, 31, 40, 20, 27,
				 32, 25, 27, 37, 29, 34, 24, 38, 33, 26};
	
    /* create employee tree root node */
    bst_node* emp_tree = NULL;

    /* create array of emloyees */
    employee* emps[SIZE] = {NULL};

    /* insert nodes in employee tree */ 
    for (j = 0; j < SIZE; j++) {
        /* create new employee and node*/
	emps[j] = (employee*) malloc (sizeof (employee));
        /* return if no memory available */
        if (emps[j] == NULL) {
             printf ("\nNo memory available!\n"); 
        return 1;
        }
        /* assign structure fields */
	strcpy(emps[j] -> name, names[j]);
	emps[j] -> age = ages[j];
       
        /* insert new node into tree */
        bst_insert (&emp_tree, (COMPARE)compare_employees, emps[j]);
    }

    printf ("\n------------------------------------------------------\n");
    printf ("\nEmployee tree inorder traversal:\n");
    in_order_bst (emp_tree, (DISPLAY)display_employee);
    printf ("\nEmployee");
    bst_minimum (emp_tree, (DISPLAY)display_employee);

    printf ("\n------------------------------------------------------\n");

    /* new tree root */
    bst_node *tree = NULL;
    /* array of tree node pointers */
    int* arr[SIZE];

    for (j = 0; j < SIZE; j++) {
	arr[j] = (int*) malloc (sizeof (int));

        /* return if no memory available */
        if (arr[j] == NULL) {
             printf ("\nNo memory available!\n"); 
        return 1;
        }
        *arr[j] = rand () % 100 + 3;
        /* insert new node in tree */
        bst_insert (&tree, (COMPARE)compare_integers, arr[j]);
    }

    /*show max number */
    printf ("\nTree of integers inorder traversal: \n");
    in_order_bst (tree, (DISPLAY)display_integer);
    bst_maximum (tree, (DISPLAY)display_integer);

    return 0;
}

/************************************************************
 As data pointer in tree node structure is of void type,
 it casts impicitely to any data type.
************************************************************/

void display_integer (int* a) {
    printf ("%d\n", *a);
}

int compare_integers (int* a, int* b) {
    if (*a == *b)
	return 0;
    if (*a < *b)
	return 2;
    else
	return 1;
}

int compare_employees (employee* a, employee* b) {
    int name =  strcmp (a -> name,
	                b -> name);
    int age = a -> age - b -> age;
    
    if (name == 0) {
	if (age == 0)
	    return 0;
	else if (age > 0)
	    return 1;
	else
	    return 2;
    }
    else if (name > 0)
	return 1;
    else
	return 2;
}

int compare_emp_name (employee* a, char* n) {
    int name =  strcmp (a -> name, n);    
    if (name == 0) {
         return 0;
    }
    else if (name > 0)
	return 1;
    else
	return 2;
}

void display_employee (employee* node) {
    printf ("Name: %s, Age: %d\n",
	    node -> name,
	    node -> age);
}
