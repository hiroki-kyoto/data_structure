// queue.c
#include "queue.h"

// create single queue
queue* create_queue()
{
	queue *_q = (queue*)malloc(sizeof(queue));

	// base node initialized with anything
	_q->head = create_node(0x000000);
	_q->tail = _q->head;

	return _q;
}

// destroy the queue
int destroy_queue(queue *_q)
{
	node *p = queue_pop(_q);
	while(p!=NULL)
	{
		destroy_node(p);
		p = queue_pop(_q);
	}
	
	return OK;
}

// add new node to queue
int queue_push(queue *_q, elem_type data)
{
	_q->tail->right = create_node(data);
	_q->tail = _q->tail->right;

	return OK;
}

// pop out tail node
node* queue_pop(queue *_q)
{
	// check legitimate
	if(_q->head==_q->tail)
	{
		// it's empty
		return NULL;
	}

	// the first node just next to base node
	node* p = _q->head->right;
	if(p==_q->tail)
	{
		// the last node
		_q->tail = _q->head;
	}
	_q->head->right = p->right;

	return p;
}


bool queue_empty(queue *_q)
{
	if(_q->head==_q->tail)
		return true;
	else
		return false;
}

// queue.c
