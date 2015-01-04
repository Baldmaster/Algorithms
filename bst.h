/* C binary search tree implementation               *
 * Compare and display functions must be implemented *
 * separately for every certain datatype.            *
 *                                                   *
 * Skupoy Sergey. sergey.archlinux@gmail.com, 2015   */

#ifndef BST_H
#define BST_H

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
typedef struct _tree_node {
    void* data;
    struct _tree_node* left;
    struct _tree_node* right;
} tree_node;



void bst_insert (tree_node **root, COMPARE compare, void* data) {
    if (*root == NULL) {
	/* create new node and allocate memory */
        tree_node *node = (tree_node*) malloc (sizeof (tree_node));
	/* return if no memory available */
        if (node == NULL) {
    	    printf ("\nNo memory available! Node not inserted.\n");
    	    return;
        }
	/* insert new node */
        node -> data = data;
        node -> left = NULL;
        node -> right = NULL;
        *root = node;
        
        printf ("node inserted successfully\n");
    }

    /* if current data less then "data" then insert it in left subtree */
    else if (compare ((*root) -> data, data) == 1)
	bst_insert (&((*root) -> left), compare, data);
    
    /* if bigger then insert it in right subtree */
    else if (compare ((*root) -> data, data) == 2)
	bst_insert (&((*root) -> right), compare, data);
}

void bst_delete (tree_node **root, COMPARE compare, void* data) {
    /* return if tree is empty */
    if ((*root) == NULL) {
	printf ("\nTree is empty. Nothing to delete!\n");
	return;
    }

    /* Temporary node pointers and variable */
    tree_node* temp = (*root);
    tree_node* parent = NULL;
    int i;

    while (temp != NULL) {
	/* comparing data with node data */
        i = compare (temp -> data, data);

	/* if node is present in tree */
        if ( i == 0) {
	    /* check child subtrees */
    	    if (temp -> left == NULL) {
		/* if node is a leaf, set parent pointer to NULL */
		if (temp -> right == NULL) {
		    if (parent -> left == temp) 
		        parent -> left = NULL;
	            else 
		        parent -> right = NULL;
		}
		/* if only right subtree is present, set parent pointer to this subtree */
                else {
		    if (parent -> left == temp)
		        parent -> left = temp -> right;
		    else 
		        parent -> right = temp -> right;
		}
    	    }
            /* if only left subtree is present, set parent pointer to this subtree */
    	    else if (temp -> right == NULL) {
		if (parent -> left == temp)
		    parent -> left = temp -> left;
		else
		    parent -> right = temp -> left;
    	    }
            /* if both subtrees present */
    	    else {
		tree_node *curr;
		parent = temp;
		curr = temp;
	        temp = temp -> right;
		
		/* if right subtree root has no left subtree */
                if (temp -> left == NULL) {
		    
		    /* set parent pointer to right subtree */
		    parent -> right = temp -> right;
		    
		    /* swap data pointers */
		    void* d = parent -> data;
		    parent -> data = temp -> data;
		    temp -> data = d;		  		    		    
		}
		else {
		    /* serching for the leftmost node in right subtree */
    	            while (temp -> left != NULL) {
		        curr = temp;
    		        temp = temp -> left;
    	            }
		    /*setting parent left pointer to right subtree of current node */
    	            curr -> left = temp -> right;
		    
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
	else if (i == 1) {
	    parent = temp;
	    temp = temp -> left;
	}
	/* if bigger then search in right subtree */
	else if (i == 2) {
	    parent = temp;
	    temp = temp -> right;
	}
    }
    /* if there is no such node */
    printf ("\nNode is not present in tree\n");
}

void in_order_bst (tree_node *root, DISPLAY display) {
    if (root != NULL) {
	in_order_bst (root -> left, display);
	display (root -> data);
	in_order_bst (root -> right, display);
    }
}

void pre_order_bst (tree_node *root, DISPLAY display) {
    if (root != NULL) {
	display (root -> data);
	pre_order_bst (root -> left, display);
	pre_order_bst (root -> right, display);
    }
}


void post_order_bst (tree_node *root, DISPLAY display) {
    if (root != NULL) {
	post_order_bst (root -> left, display);
	post_order_bst (root -> right, display);
	display (root -> data);
    }
}    

#endif
