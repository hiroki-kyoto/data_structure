//queue.h
#include "node.h"

/// queue structure demo
/// 0->1 [push] => 0->1->2->3
/// 0->1->2 [pop] => 1->2

typedef struct tag_queue
{
	/* data */
	node *head;
	node *tail;
}queue;

// create single queue
queue* create_queue();

// destroy the queue
int destroy_queue(queue *_q);

// add new node to queue
int queue_push(queue *_q, elem_type data);

// pop out tail node
node* queue_pop(queue *_q);

// check empty
bool queue_empty(queue *_q);
