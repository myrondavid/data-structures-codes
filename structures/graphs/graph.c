#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../queue/queue.h"

List* create_adj_list(int item){
  List *new_adj_list = (List*) malloc(sizeof(List));
  new_adj_list->item = item;
  new_adj_list->next = NULL;
  return new_adj_list;
}

Graph* create_graph(){
  Graph *graph = (Graph*) malloc(sizeof(Graph));
  int i;
  for (i = 1; i <= MAX_SIZE - 1; i++) {
    graph->vertices[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph; 
}

void add_edge(Graph *graph, int vertex1, int vertex2){
  List *vertex = create_adj_list(vertex2);
  vertex->next = graph->vertices[vertex1];
  graph->vertices[vertex1] = vertex;
  //Undirected graph. Edge to the other direction as well.
  vertex = create_adj_list(vertex1);
  vertex->next = graph->vertices[vertex2];
  graph->vertices[vertex2] = vertex;
}

void dfs(Graph *graph, int source){
  graph->visited[source] = 1;
  printf("%d\n", source);
  List *adj_list = graph->vertices[source];
  while (adj_list != NULL) {
    if (!graph->visited[adj_list->item]) {
      dfs(graph, adj_list->item);
    }
    adj_list = adj_list->next;
  }
}

void bfs(Graph *graph, int source){
  Queue *queue = create_queue();
  int dequeued;
  List * adj_list = graph->vertices[source];
  graph->visited[source] = 1;
  enqueue(queue, source);
  while (!is_empty(queue)) {
    dequeued = dequeue(queue);
    adj_list = graph->vertices[dequeued];
    while (adj_list != NULL) {
      if (!graph->visited[adj_list->item]) {
        printf("%d\n", adj_list->item);
        graph->visited[adj_list->item] = 1;
        enqueue(queue, adj_list->item);
      }
      adj_list = adj_list->next;
    }
  }
}

void print_graph(Graph *graph){
  
}