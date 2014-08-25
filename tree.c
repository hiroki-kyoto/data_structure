// tree.c
#include "tree.h"


// tree constructor
tree* create_tree()
{
	tree *_t = (tree*)malloc(sizeof(tree));
	if(_t!=NULL)
		(_t->root = NULL)||(_t->flag = _t->root);
	else
		return NULL;

	return _t;
}


int destroy_tree(tree *_t)
{
	if(_t->root==NULL)
		return ERROR;
	// use layer-by-layer strategy
	queue* _q = create_queue();

///////////////////////////////////// HOW TO REALIZE MULTI-TYPE OF STRUCTURE IN C? /////////////////////////
	queue_push(_q, (elem_type)(_t->root));
	// from root
	while(queue_empty(_q))
	{
		node *p = (node*)queue_pop(_q);
		if(p!=NULL)
			(queue_push(_q,(int)(p->left))==OK)&&(queue_push(_q, (int)(p->right))==OK)&&(destroy_node(p)==OK);
		else
			break; // actually, only exception occurs does it execute here
	}

	// destroy queue
	destroy_queue(_q);

	return OK;
}


int tree_set_root(tree *_t, elem_type data)
{
	_t->root = create_node(data);
	_t->flag = _t->root;

	return OK;
}


elem_type tree_get_root(tree *_t)
{
	return _t->root->data;
}

bool tree_empty(tree *_t)
{
	if(_t->root==NULL)
		return true;
	else
		return false;
}

int tree_set_left_child(tree* _t, elem_type data)
{
	if(_t->flag==NULL)
		return ERROR;
	else
		if(_t->flag->left==NULL)
			_t->flag->left = create_node(data);
		else
			_t->flag->left->data = data;
	return OK;
}

elem_type tree_get_left_child(tree* _t)
{
	if(_t->flag==NULL)
		return ERROR; // here's an errors
	else
		return _t->flag->left->data;
}


int tree_set_right_child(tree* _t, elem_type data)
{
	if(_t->flag==NULL)
		return ERROR;
	else
		if(_t->flag->right==NULL)
			_t->flag->right = create_node(data);
		else
			_t->flag->right->data = data;
	return OK;
}

elem_type tree_get_right_child(tree* _t)
{
	if(_t->flag==NULL)
		return ERROR;
	else
		return _t->flag->right->data;
}

bool tree_to_father(tree *_t)
{
	// search the whole tree
	if(_t->flag==NULL)
		return false;
	// use layer-by-layer strategy
	queue* _q = create_queue();
	queue_push(_q, (elem_type)(_t->root));

	// from root
	bool find = false;
	node *p = NULL;

	while(queue_empty(_q)&&find==false)
	{
		p = (node*)queue_pop(_q);
		if(p!=NULL)
			if(p->left==_t->flag||p->right==_t->flag)
				find = true;
			else
			{
				queue_push(_q, (int)(p->left));
				queue_push(_q, (int)(p->right));
			}
		else
			break; // actually, only exception occurs does it execute here
	}

	// destroy queue
	destroy_queue(_q);

	if(find)
		{_t->flag = p; return true;}
	else
		return false;
}

// manipulate the flag in the tree ==> move flag to left child
bool tree_to_left_child(tree* _t)
{
	if(_t->flag!=NULL&&_t->flag->left!=NULL)
	{
		_t->flag = _t->flag->left;
		return true;
	}
	else
		return false;
}

// manipulate the flag in the tree ==> move flag to right child
bool tree_to_right_child(tree* _t)
{
	if(_t->flag!=NULL&&_t->flag->right!=NULL)
	{
		_t->flag = _t->flag->right;
		return true;
	}
	else
		return false;
}

// visit them in order like: father->left_child->right_child and it's by layered method
// Width-fisrt search

int tree_width_first_search(tree *_t, F _f)
{
	if(_t->root==NULL)
		return ERROR;
	// use layer-by-layer strategy
	queue* _q = create_queue();

///////////////////////////////////// HOW TO REALIZE MULTI-TYPE OF STRUCTURE IN C? /////////////////////////
	queue_push(_q, (elem_type)(_t->root));
	// from root
	while(queue_empty(_q))
	{
		node *p = (node*)queue_pop(_q);
		if(p!=NULL)
		{
			queue_push(_q, (int)(p->left)); 
			queue_push(_q, (int)(p->right)); 
			_f(p);
		}
		else
			break; // actually, only exception occurs does it execute here
	}

	// destroy queue
	destroy_queue(_q);

	return OK;
}

// tree get current node value
elem_type tree_get(tree* _t)
{
	if(_t->flag==NULL)
		return ERROR;
	else
		return _t->flag->data;
}

// tree set node value
int tree_set(tree *_t, elem_type data)
{
	if(_t->flag==NULL)
		return ERROR;
	else
		_t->flag->data = data;

	return OK;
}

// go to tree root
int tree_to_root(tree *_t)
{
	_t->flag = _t->root;

	return OK;
}


// tree.c
