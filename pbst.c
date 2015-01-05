/************************************************************
Binary search tree.
Example of using different data structures.
************************************************************/

#include "pbst.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

/* Simple employee structure */
typedef struct _employee {
    char name[32];
    unsigned char age;
} employee;

void display_integer (pbst_node*);
void display_employee (pbst_node*);
int compare_integers (pbst_node*, pbst_node*);
int compare_employees (pbst_node*, pbst_node*);

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
    pbst_node* emp_tree = NULL;

    /* insert nodes in employee tree */ 
    for (j = 0; j < SIZE; j++) {
        /* create new employee and node*/
	employee* emp = (employee*) malloc (sizeof (employee));
	pbst_node* node = (pbst_node*) malloc (sizeof (pbst_node));

        /* return if no memory available */
        if (emp == NULL || node == NULL) {
             printf ("\nNo memory available!\n"); 
        return 1;
        }
        /* assign structure fields */
	strcpy(emp -> name, names[j]);
	emp -> age = ages[j];

	node -> parent = NULL;
	node -> left = NULL;
	node -> right = NULL;
	node -> data = emp;
        /* insert new node into tree */
	pbst_insert (&emp_tree, (COMPARE)compare_employees, node);
    }

    printf ("\n------------------------------------------------------\n");
    printf ("\nEmployee tree inorder traversal:\n");
    in_order_pbst (emp_tree, (DISPLAY)display_employee);
    printf ("\nEmployee tree minimum value\n");
    pbst_minimum (emp_tree, (DISPLAY)display_employee);

    printf ("\n------------------------------------------------------\n");

    /* new tree root */
    pbst_node *tree = NULL;
    /* array of tree node pointers */
    pbst_node* arr[SIZE];

    for (j = 0; j < SIZE; j++) {
	arr[j] = (pbst_node*) malloc (sizeof (pbst_node));
	int* a = (int*) malloc (sizeof (int));

        /* return if no memory available */
        if (arr[j] == NULL || a == NULL) {
             printf ("\nNo memory available!\n"); 
        return 1;
        }
        /* assign structure fields */
	*a = rand () % 100 + 3;
	arr[j] -> data = a;
	arr[j] -> parent = NULL;
	arr[j] -> left = NULL;
	arr[j] -> right = NULL;
        /* insert new node in tree */
	pbst_insert (&tree, (COMPARE)compare_integers, arr[j]);
    }

    /*show max number */
    pbst_maximum (tree, (DISPLAY)display_integer);
    printf ("\nTree inorder traversal: \n");
    in_order_pbst (tree, (DISPLAY)display_integer);
 
    return 0;
}

/************************************************************
 As data pointer in tree node structure is of void type,
 it has to be cast explicitely to needed type as shown in
 functions below.
************************************************************/

void display_integer (pbst_node* a) {
    printf ("%d\n", *(int*)(a -> data));
}

int compare_integers (pbst_node* a, pbst_node* b) {
    if (*(int*)(a -> data) == *(int*)(b -> data))
	return 0;
    if (*(int*)(a -> data) < *(int*)(b -> data))
	return 2;
    else
	return 1;
}

int compare_employees (pbst_node* a, pbst_node* b) {
    int name =  strcmp (((employee*)(a -> data)) -> name,
	                ((employee*)(b -> data)) -> name);
    int age = ((employee*)(a -> data)) -> age -
	      ((employee*)(b -> data)) -> age;
    
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

void display_employee (pbst_node* node) {
    printf ("Name: %s, Age: %d\n",
	    ((employee*)(node -> data)) -> name,
	    ((employee*)(node -> data)) -> age);
}
