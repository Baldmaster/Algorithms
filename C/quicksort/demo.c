/************************************************************
Example of using different data structures.
************************************************************/

#include "quicksort.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 20

/* Simple employee structure */
typedef struct _employee {
    char name[32];
    unsigned char age;
} employee;

void display_employee (employee*);
int compare_employees (employee*, employee*);
void swap_employees (employee*, employee*);

int main (void) {
    srand (time (NULL));
    int j;
    /* Array of names */
    char* names[SIZE] = {
	"Anna",
	"Liza",
	"Bob",
	"Bella", 
	"Tom", 
	"Caroline", 
	"Daniel", 
	"Rita", 
	"Eve", 
	"Fred",
	"Gillian", 
	"Ivor",
	"Jane",
	"Jane",
	"Karl",
	"Alex",
	"Mike",
	"Mike",
	"Diana",
	"Chuck"
    };

    /* Array of age values */
    unsigned char ages[SIZE] = { 22, 31, 34, 25, 28, 34, 31, 40, 20, 27,
				 32, 25, 27, 37, 29, 34, 24, 38, 33, 26};
	
    /* create array of emloyees */
    employee emps[SIZE];

    for (int j = 0; j < SIZE; j++) {
        /* assign structure fields */
	    strcpy(emps[j].name, names[j]);
	    emps[j].age = ages[j];
    }

    printf ("\n------------------------------------------------------\n");

    for (int j = 0; j < SIZE; j++)
        display_employee (&emps[j]);

    quicksort (emps, sizeof (employee), 0, SIZE - 1,
               (COMPARE) compare_employees, (SWAP) swap_employees);

    printf ("\n---  Sorted employees array  -------------------------\n");

    for (int j = 0; j < SIZE; j++)
        display_employee (&emps[j]);
    return 0;
    
}

/************************************************************
 As data pointer in tree node structure is of void type,
 it casts impicitely to any data type.
************************************************************/

int compare_employees (employee* a, employee* b) {
    int name =  strcmp (a -> name, b -> name);

    if (name <= 0)
	return 1;
    else
	return 0;
}

void display_employee (employee* node) {
    printf ("Name: %s, Age: %d\n",
	    node -> name,
	    node -> age);
}

void swap_employees (employee* a, employee* b) {
    employee temp;
    strcpy (temp.name, a -> name);
    temp.age = a -> age;
    strcpy (a -> name, b -> name);
    a -> age = b -> age;
    strcpy (b -> name, temp.name);
    b -> age = temp.age;
}
