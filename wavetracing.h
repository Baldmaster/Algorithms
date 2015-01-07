/************************************************************
   Lee algorithm.
   In order not to check all points on every iteration
   linkedlist is used for saving wavefront points.

 ************************************************************/
#include <stdio.h>
#include <stdlib.h>

/************************************************************
 List node structure.
 x, y coordinate.
 next, prev - next and previous nodes.
************************************************************/
typedef struct _wave_node {
    int x;
    int y;
    struct _wave_node *next;
    struct _wave_node *prev;
} wave_node;


/************************************************************
  Delete all list nodes. Gets first node of list as argument.
************************************************************/
void empty_wavefront (wave_node** wavefront);

/************************************************************
   Find path function. First argument is a pointer to
 two-dimensional array. two next are width and height values.
 BE CAREFULL WITH POINTERS. Check correctness of width and 
 height values. Two last are start and target node (point), 
 check their values!
 ************************************************************/
void find_path (int* maze, int width, int height, wave_node *start, wave_node *target);

/************************************************************
   Insert new node into wavefront points list.
 ************************************************************/
void insert (wave_node**, int, int);

/************************************************************
   Delete node from wavefront points list.
 ************************************************************/
void delete (wave_node**, wave_node**);

/************************************************************
   Coordinates increment
 ************************************************************/
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


void find_path (int* maze, int width, int height, wave_node *start, wave_node *target) {
    wave_node* wavefront = (wave_node*) malloc (sizeof (wave_node));
    wave_node* wave;
    insert (&wavefront, start -> x, start -> y);
    int n = 2;
    int j, temp_x, temp_y;
    *(maze + ((start -> y) * height) + (start -> x)) = 1;
    while (wavefront) {
	wave = wavefront;
	while (wave) {
	    for (j = 0; j < 4; j++) {
		temp_x = (wave -> x) + dx[j];
		temp_y = (wave -> y) + dy[j];
		if (temp_x == target -> x && temp_y == target -> y) {
		    *(maze + (temp_y * height) + temp_x) = n;
		    empty_wavefront (&wavefront);
		    free (wavefront);
		    printf ("\n----- Path found! Length: %d -----\n", n);
		    return;
		}
		if (temp_x < 0 || temp_x > width || temp_y < 0 || temp_y > height)
		    continue;
	      
		if (*(maze + (temp_y * height) + temp_x) == 0) {
		    *(maze + (temp_y * height) + temp_x) = n;
		    insert (&wavefront, temp_x, temp_y);
		}
	    }
	    wave_node* temp = wave;
	    delete (&wavefront, &temp);	   
	    wave = wave -> next;
	}
	n++;
    }
    printf ("\n----- PATH NOT FOUND -----\n");
    empty_wavefront (&wavefront);
    free (wavefront);
}
    
void insert (wave_node** start, int x, int y) {
    wave_node* node = (wave_node*) malloc (sizeof (wave_node));
    if (node == NULL)
	printf ("\nNo memory!!!\n");
    else {
	node -> x = x;
	node -> y = y;
	if ((*start) == NULL) {
	    node -> next = NULL;
	}
	else {
	    node -> next = *start;
	    (*start) -> prev = node;
	}
	node -> prev = NULL;
	*start = node;
    }
}
    
		
void delete (wave_node** start, wave_node** wave) {
    if (*start == *wave) {
	free (*wave);
	*start = NULL;
    }
    else {
	wave_node* prev = (*wave) -> prev;
	wave_node* next = (*wave) -> next;
	prev -> next = next;
	if (next)
	    next -> prev = prev;
	free (*wave);
    }

}

void empty_wavefront (wave_node** start) {
    wave_node* temp = (*start);
    wave_node* next = (*start);
    while (temp != NULL) {
	next = next -> next;
	free (temp);
	temp = next;
    }
}
    
