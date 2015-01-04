/* C binary search tree with parent pointers         *
 * Compare and display functions must be implemented *
 * separately for every certain datatype.            *
 *                                                   *
 * Skupoy Sergey. sergey.archlinux@gmail.com, 2015   */

#ifndef PBST_H
#define PBST_H

#include <stdio.h>
#include <stdlib.h>

/* Function pointers for comparing and displaying data. *
 * Return values for compare function:                  *
 *     0 -> equality,                                   *
 *     1 -> process left subtree,                       *
 *     2 -> process right subtree.                      *
 *                                                      */
typedef int (*COMPARE) (void*, void*);
typedef void (*DISPLAY) (void*);

/* tree node structure */
typedef struct _pbst_node {
    void* data;
    struct _pbst_node* parent;
    struct _pbst_node* left;
    struct _pbst_node* right;
} pbst_node;



void pbst_insert (pbst_node **root, COMPARE compare, void* data) {
    /* create new node and allocate memory */
    pbst_node *node = (pbst_node*) malloc (sizeof (pbst_node));
    /* return if no memory available */
    if (node == NULL) {
    	printf ("\nNo memory available! Node not inserted.\n");
        return;
    }
    /* set node fields */
    node -> data = data;
    node -> parent = NULL;
    node -> left = NULL;
    node -> right = NULL;
    
    /* temporary node and variable */
    pbst_node* parent = NULL;
    int i;

    /* while current node is not NULL */
    while ((*root) != NULL) {
	i = compare ((*root) -> data, data);
	parent = *root;
	/* if data is larger then node data then traverse left subtree */
        if (i == 1)
	    root = &((*root) -> left);
	/* if smaller then traverse right subtree */
	else if (i == 2)
	    root = &((*root) -> right);
	/* otherwise return */
	else
	    return;
    }
    /* set node parent */
    node -> parent = parent;

    /* insert new node */
    *root = node;
    printf ("node inserted successfully\n");
}

void pbst_delete (pbst_node **root, COMPARE compare, void* data) {
    /* return if tree is empty */
    if ((*root) == NULL) {
	printf ("\nTree is empty. Nothing to delete!\n");
	return;
    }

    /* Temporary node pointers and variable */
    pbst_node* temp = (*root);
    int i;

    /* Traverse tree until root pointer is not NULL */
    while (temp != NULL) {
	/* comparing data with node data */
        i = compare (temp -> data, data);

	/* if node is present in tree */
        if ( i == 0) {
	    /* check child subtrees */
    	    if (temp -> left == NULL) {
		/* if node is a leaf, set parent pointer to NULL */
		if (temp -> right == NULL) {
		    if (temp -> parent -> left == temp) 
		        temp -> parent -> left = NULL;
	            else 
		        temp -> parent -> right = NULL;
		}
		/* if only right subtree is present, set parent pointer to this subtree */
                else {
		    if (temp -> parent -> left == temp)
		        temp -> parent -> left = temp -> right;
		    else 
		        temp -> parent -> right = temp -> right;
		}
    	    }
            /* if only left subtree is present, set parent pointer to this subtree */
    	    else if (temp -> right == NULL) {
		if (temp -> parent -> left == temp)
		    temp -> parent -> left = temp -> left;
		else
		    temp -> parent -> right = temp -> left;
    	    }
            /* if both subtrees present */
    	    else {
		/* if right subtree root has no left subtree */
	        temp = temp -> right;
                if (temp -> left == NULL) {		    
		    /* set parent pointer to right subtree */
		    temp -> parent -> left = temp -> right;
		    
		    /* swap data pointers */
		    void* d = temp -> parent -> data;
		    temp -> parent -> data = temp -> data;
		    temp -> data = d;		  		    		    
		}
		else {
		    /* serching for the leftmost node in right subtree */
		    pbst_node* parent = temp -> parent;
    	            while (temp -> left != NULL) {
    		        temp = temp -> left;
    	            }
		    /*setting parent left pointer to right subtree of current node */
    	            temp -> parent -> left = temp -> right;		    
		    /* swap data pointers */
		    void* d = parent -> data;
		    parent -> data = temp -> data;
		    temp -> data = d;		    
		}		
    	    }
	    /* delete node and return */
	    free (temp);
	    return;
        }

	/* if node data less then "data", then search in left subtree */
	else if (i == 1)
	    temp = temp -> left;
	/* if bigger then search in right subtree */
	else if (i == 2)
	    temp = temp -> right;
	else
	    return;
    }
    /* if there is no such node */
    printf ("\nNode is not present in tree\n");
}

/* tree maximum value */
void pbst_maximum (pbst_node* root, DISPLAY display) {
    while (root -> right != NULL)
	root = root -> right;
    printf ("\nTree maximum value is: ");
    display (root -> data);
}

/* tree minimum value */
void pbst_minimum (pbst_node* root, DISPLAY display) {
    while (root -> left != NULL)
	root = root -> left;
    printf ("\nTree minimum value is: ");
    display (root -> data);
}
    
/* Tree traversal functions *
 * in-, pre- and postorder. */
void in_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	in_order_pbst (root -> left, display);
	display (root -> data);
	in_order_pbst (root -> right, display);
    }
}

void pre_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	display (root -> data);
	pre_order_pbst (root -> left, display);
	pre_order_pbst (root -> right, display);
    }
}

void post_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	post_order_pbst (root -> left, display);
	post_order_pbst (root -> right, display);
	display (root -> data);
    }
}    

#endif
