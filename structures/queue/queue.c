#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* create_queue(){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    queue->qnt = 0;
    return queue;
}

int is_empty(Queue *queue){
    return(queue->front == NULL);
}

void enqueue(Queue *queue, int item){
    Node *new = (Node*) malloc(sizeof(Node));
    new->item = item;
    new->next_node = NULL;
    if(is_empty(queue)){
        queue->first = new;
    }
    else{
        queue->last->next_node = new;
    }
    queue->last = new;
    queue->qnt++;
}

int dequeue(Queue *queue){
    if(is_empty(queue)) return -1;

    Node *return_top = queue->first;
    int item = queue->front->item;
    queue->first = queue->first->next_node;
    free(return_top);
    return item;
}

