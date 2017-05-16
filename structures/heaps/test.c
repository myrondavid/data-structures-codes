#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int main(){
  Heap *h1 = create_heap(10);
  Heap *h2 = create_heap(10);
  int i;
  
  for(i = 0; i < 10; i++){
    enqueue_min(h1, i);
  }
  for(i = 0; i < 10; i++){
    enqueue_max(h2, i);
  }

  printf("MIN: ");
  for(i = 0; i < 10; i++){
    printf(" %d ", dequeue_min(h1));
  }
  printf("\n");

  printf("MAX: ");
  for(i = 0; i < 10; i++){
    printf(" %d ", dequeue_max(h2));
  }
  printf("\n");

  return 0;
}