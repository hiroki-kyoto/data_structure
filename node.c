//node.c
#include "node.h"

//create single node
node* create_node(elem_type data)
{
	// create single node with given data
	node *_n = (node*)malloc(sizeof(node));
	//memset(_n, NULL, sizeof(node));
	_n->data = data;
	_n->left = NULL;
	_n->right = NULL;
	return _n;
}


int destroy_node(node *_n)
{
	free(_n);
	return OK;
}
// node.c
