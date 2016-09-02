#ifndef QUEUE_H
#define QUEUE_H

  typedef struct queue Queue;
  typedef struct node Node;

  struct node {
    int item;
    Node *next_node;
  };

  struct queue {
    Node *first;
		Node *last;
		int qnt;
  };

  Stack* create_stack();

	Queue* create_queue();
	void enqueue(Queue *queue, int item);
	int dequeue(Queue *queue);
	int is_empty(Queue *queue);

#endif /* STACK_H */