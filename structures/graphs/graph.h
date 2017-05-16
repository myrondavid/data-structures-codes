#ifndef GRAPH_H
#define GRAPH_H

#define MAX_SIZE = 10000;

typedef struct adj_list List;
typedef struct graph Graph;

struct adj_list {
int item;
List *next;
};

struct graph {
  List *vertices[MAX_SIZE];
  short visited[MAX_SIZE];
};

Graph* create_graph();

List* create_adj_list(int item);

void add_edge(Graph *graph, int vertex1, int vertex2);

void dfs(Graph *graph, int source);

void bfs(Graph *graph, int source);

void print_graph(Graph *graph);

#endif /* GRAPH_H */