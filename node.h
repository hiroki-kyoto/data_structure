//node.h
#include "base.h"

typedef int elem_type;

typedef struct tag_node
{
	/* data */
	elem_type data;
	struct tag_node *left;
	struct tag_node *right;
}node;

//create single node
node* create_node(elem_type data);

//destroy single node and release memory
int destroy_node(node *_n);

// node.h
