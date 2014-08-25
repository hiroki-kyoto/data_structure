// tree.h
#include "queue.h"

// tree
typedef struct tag_tree
{
	/* data */
	node *root;
	node *flag;
}tree;


// tree constructor
tree* create_tree();

int destroy_tree(tree *_t);


int tree_set_root(tree *_t, elem_type data);

elem_type tree_get_root(tree *_t);

bool tree_empty(tree *_t);

int tree_set_left_child(tree* _t, elem_type data);

elem_type tree_get_left_child(tree* _t);


int tree_set_right_child(tree* _t, elem_type data);

elem_type tree_get_right_child(tree* _t);

bool tree_to_father(tree *_t);

// manipulate the flag in the tree ==> move flag to left child
bool tree_to_left_child(tree* _t);

// manipulate the flag in the tree ==> move flag to right child
bool tree_to_right_child(tree* _t);

// visit them in order like: father->left_child->right_child and it's by layered method
// Width-fisrt search

// define a function type
typedef int(*F)(node*);

int tree_width_first_search(tree *_t, F _f);

// tree get current node value
elem_type tree_get(tree* _t);

// tree set node value
int tree_set(tree *_t, elem_type data);

int tree_to_root(tree *_t);

// tree.h

