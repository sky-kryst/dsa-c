#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

int getMinEdgeVertex(int distance[], bool visited[]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++) {
    if (visited[v] == false && distance[v] < min) {
      min = distance[v];
      min_index = v;
    }
  }

  return min_index;
}

void printMST(int parent[], int graph[V][V]) {
  printf("Edge \tWeight\n");
  for (int i = 1; i < V; i++) {
    printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
  }
}

void primMST(int graph[V][V]) {
  int parent[V];
  int distance[V];
  bool visited[V];

  // Initialize all keys as INFINITE
  for (int i = 0; i < V; i++) {
    distance[i] = INT_MAX;
    visited[i] = false;
  }
  // and initial node to 0
  distance[0] = 0;
  parent[0] = -1;

  // For all vertices of the graph (starting from any vertex )
  for (int count = 0; count < V - 1; count++) {
    int u = getMinEdgeVertex(distance, visited);
    visited[u] = true;

    // Relax all vertices from the minimum edge
    for (int v = 0; v < V; v++)
      if (graph[u][v] && visited[v] == false && graph[u][v] < distance[v]) {
        distance[v] = graph[u][v];
        parent[v] = u;
      }
  }

  printMST(parent, graph);
}

int main() {
  int graph[V][V] = {{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0}};

  primMST(graph);

  return 0;
}
