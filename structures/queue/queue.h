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

Queue* create_queue();
void enqueue(Queue *queue, int item);
Queue dequeue(Queue *queue);
int is_empty(Queue *queue);
void print_queue(Queue* queue);
int sizeof_queue(Queue* queue);

#endif /* QUEUE_H */