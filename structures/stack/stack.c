#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* create_stack() {
  Stack *stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, int item) {
  Node *new_top = (Node*) malloc(sizeof(Node));
  new_top->item = item;
  new_top->next_node = stack->top;
  stack->top = new_top;
}

int pop(Stack *stack) {
  if (is_empty(stack)) return -1;
  
  Node *return_top = (Node*) malloc(sizeof(Node));
  int item = stack->top->item;
  stack->top = stack->top->next_node;
  free(return_top);
  return item;
}

int peek(Stack *stack) {
  if(is_empty(stack)) return -1;

  else return stack->top->item;
}

int is_empty(Stack *stack) {
  return (stack->top == NULL);
}
