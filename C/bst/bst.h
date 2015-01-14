/************************************************************ 
   C binary search tree implementation. 
Compare and display functions must be implemented separately 
for every certain datatype.
 

Skupoy Sergey. sergey.archlinux@gmail.com, 2015   
************************************************************/

#ifndef BST_H
#define BST_H

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
if you allocate "data" pointer dinamically! 
Be carefull! 
************************************************************/
typedef struct _bst_node {
    void* data;
    struct _bst_node* parent;
    struct _bst_node* left;
    struct _bst_node* right;
} bst_node;

/************************************************************
   Node insert function
************************************************************/
void bst_insert (bst_node **root, COMPARE compare, void* data);

/************************************************************
   Find function can be implemented to find by any creteria.
 ************************************************************/
void bst_find (bst_node *root, COMPARE compare, void* data);
    
/************************************************************
   Delete node function
************************************************************/
void bst_delete (bst_node **root, COMPARE compare, void* data);

/************************************************************
   Free tree functions.
   bst_free checks if root node has a parent. If it has then
parent's pointer must be set to NULL. Then _bst_free function
frees nodes recursively.
************************************************************/   
void _bst_free (bst_node **root);
void bst_free (bst_node **root);

/************************************************************
   MAXimum and MINimum
************************************************************/
void bst_maximum (bst_node* root, DISPLAY display);
void bst_minimum (bst_node* root, DISPLAY display);

/************************************************************ 
   Tree traversal functions. IN-, PRE- and POSTorder. 
************************************************************/
void in_order_bst (bst_node *root, DISPLAY display);
void pre_order_bst (bst_node *root, DISPLAY display);
void post_order_bst (bst_node *root, DISPLAY display);    
#endif
