/************************************************************
   Red-Black tree.


   Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/

#ifndef RBTREE_H
#define RBTREE_H
/************************************************************
  Function pointers
************************************************************/
typedef int (*COMPARE) (void*, void*);
typedef void (*DISPLAY) (void*);

/************************************************************
  Node structure
 ************************************************************/
typedef struct _rb_node {
    short color;
    void* data;
    struct _rb_node* parent;
    struct _rb_node* left;
    struct _rb_node* right;
} rb_node;

typedef struct _rb_tree {
    struct _rb_node* root;
} rb_tree;


int rb_insert (rb_tree* tree, void* data, COMPARE compare);
void left_rotate (rb_tree* tree, rb_node* node);
void right_rotate (rb_tree* tree, rb_node* node);
void rb_insert_fix (rb_tree* tree, rb_node* node);
void rb_transplant (rb_tree* tree, rb_node* x, rb_node* y);
int rb_delete (rb_tree* tree, void* data, COMPARE compare);
void rb_delete_fix (rb_tree* tree, rb_node* node);
rb_node* rb_find (rb_tree* tree, void* data, COMPARE compare);
rb_node* rb_min (rb_node* tree);   
void rb_inorder (rb_node* root, DISPLAY display, int);    




#endif
