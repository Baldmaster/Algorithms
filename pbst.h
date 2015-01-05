/************************************************************ 
   C binary search tree with parent pointers. 
Compare and display functions must be implemented separately 
for every certain datatype. See pbst.c example file.
 

Skupoy Sergey. sergey.archlinux@gmail.com, 2015   
************************************************************/

#ifndef PBST_H
#define PBST_H

#include <stdio.h>
#include <stdlib.h>

/************************************************************ 
Function pointers for comparing and displaying data.
  Return values for compare function:
       0 -> equality;
       1 -> process left subtree;
       2 -> process right subtree.
************************************************************/
typedef int (*COMPARE) (void*, void*);
typedef void (*DISPLAY) (void*);

/************************************************************
  Tree node structure. 
Point that data pointer is "void", that allows you to use
data of any type. 
                  !!!WARNING!!!
You must take care of correct memory deallocation functions
if you allocate "pbst_node" or "data" pointer dinamically! 
Be carefull! 
************************************************************/
typedef struct _pbst_node {
    void* data;
    struct _pbst_node* parent;
    struct _pbst_node* left;
    struct _pbst_node* right;
} pbst_node;

/************************************************************
  Setting node pointers to NULL, but !!!NOT DATA POINTER!!!
Thus, node becomes a free root node and can be used again until 
it is not destroyed by corresponding function if it is allocated
dinamically.
 ************************************************************/
void null_pointers (pbst_node *node) {
    node -> parent = NULL;
    node -> left = NULL;
    node -> right = NULL;
}

/* node insert function */
void pbst_insert (pbst_node **root, COMPARE compare, pbst_node* node) {
    /* temporary node and variable */
    pbst_node* parent = NULL;
    int i;

    /* while current node is not NULL */
    while ((*root) != NULL) {
	i = compare ((*root), node);
	parent = *root;
	/* if data is larger then node data then traverse left subtree */
        if (i == 1)
	    root = &((*root) -> left);
	/* if smaller then traverse right subtree */
	else if (i == 2)
	    root = &((*root) -> right);
	/* otherwise return */
	else if (i == 0)
	    return;
    }
    /* set node parent */
    node -> parent = parent;

    /* insert new node */
    *root = node;
}

/* node delete function */
void pbst_delete (pbst_node **root, COMPARE compare, pbst_node* node) {
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
        i = compare (temp, node);
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
		pbst_node* parent = temp -> parent;
		pbst_node* curr = temp -> right;
		/* if right subtree root has no left subtree */
                if (curr -> left == NULL) {		    
		    /* set parent pointer to right subtree */
		    temp -> right = curr -> right;		
		}
		else {
		    /* serching for the leftmost node in right subtree */
    	            while (curr -> left != NULL)
    		        curr = curr -> left;
		    /*setting parent left pointer to right subtree of current node */
    	            curr -> parent -> left = curr -> right;
		}
		/* setting parent pointer to current pointer */
		if (parent -> right == temp)
		     parent -> right = curr;
		else
		     parent -> left = curr;
		/* setting left, right and parent of current pointer */
		curr -> right = temp -> right;
		curr -> left = temp -> left;
		curr -> parent = parent;	    		
    	    }
	    /* free node and return */
	    null_pointers (temp);
	    return;
        }

	/* go to left subtree */
	else if (i == 1)
	    temp = temp -> left;
	/* go to right subtree */
	else if (i == 2)
	    temp = temp -> right;
	else
	    return;
    }
    /* if there is no such node */
    printf ("\nNode is not present in tree\n");
}

/************************************************************
   Free tree functions.
   pbst_free checks if root node has a parent. If it has then
parent's pointer must be set to NULL. Then _pbst_free function
frees nodes recursively.
************************************************************/
   
void _pbst_free (pbst_node **root) {       
    if ((*root) != NULL) {
	_pbst_free (&((*root) -> left));
	null_pointers (*root);
	_pbst_free (&((*root) -> right));
    }
}

void pbst_free (pbst_node **root) {
    if ((*root) -> parent != NULL) {
	if ((*root) -> parent -> left == (*root))
	    (*root) -> parent -> left = NULL;
	else
	    (*root) -> parent -> right = NULL;
    }
    _pbst_free (root);
}



/************************************************************
   MAXimum and MINimum
************************************************************/
void pbst_maximum (pbst_node* root, DISPLAY display) {
    while (root -> right != NULL)
	root = root -> right;
    printf ("\nTree maximum value is: ");
    display (root);
}

void pbst_minimum (pbst_node* root, DISPLAY display) {
    while (root -> left != NULL)
	root = root -> left;
    printf ("\nTree minimum value is: ");
    display (root);
}    


/************************************************************ 
   Tree traversal functions. IN-, PRE- and POSTorder. 
************************************************************/
void in_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	in_order_pbst (root -> left, display);
	display (root);
	in_order_pbst (root -> right, display);
    }
}

void pre_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	display (root);
	pre_order_pbst (root -> left, display);
	pre_order_pbst (root -> right, display);
    }
}

void post_order_pbst (pbst_node *root, DISPLAY display) {
    if (root != NULL) {
	post_order_pbst (root -> left, display);
	post_order_pbst (root -> right, display);
	display (root);
    }
}    

#endif
