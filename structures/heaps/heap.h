#ifndef HEAP_H
#define HEAP_H

typedef struct heap Heap;
struct heap {
  int size;
  int max_size;
  int *data;
};

Heap* create_heap(int size);

void enqueue_min(Heap *heap, int item);

void enqueue_max(Heap *heap, int item);

int dequeue_min(Heap *heap);

int dequeue_max(Heap *heap);

int get_parent_index(Heap *heap, int i);

int get_left_index(Heap *heap, int i);

int get_right_index(Heap *heap, int i);

int get_size(Heap *heap);

int item_of(Heap *heap, int i);

void min_heapify(Heap *heap, int i);

void max_heapify(Heap *heap, int i);

void heapsort(Heap *heap);

#endif  /* HEAP_H */
