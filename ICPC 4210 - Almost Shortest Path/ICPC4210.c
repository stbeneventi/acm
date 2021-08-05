/******************************************************************************************************************************
 * ICPC 4210 - Almost Shortest Path
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=2211
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 10000

struct AdjListNode {
  int dest;
  int weight;
  struct AdjListNode* next;
};

struct AdjList {
  struct AdjListNode* head;
};

struct Graph {
  int numberOfNodes;
  int storedNodes;
  struct AdjList* nodes;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
  struct AdjListNode* newNode =
      (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph() {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numberOfNodes = 0;
  graph->storedNodes = 0;
  return graph;
}

void printArray(int* array, int length) {
  int i;
  printf("[");
  for (i = 0; i < length; i++) {
    printf("%d%s", array[i], i != length - 1 ? "," : "");
  }
  printf("]\n");
}

void printGraph(struct Graph* graph) {
  int v;
  printf("SN: %d, NN: %d\n\n", graph->storedNodes, graph->numberOfNodes);
  for (v = 0; v < graph->storedNodes; ++v) {
    struct AdjListNode* pt = graph->nodes[v].head;
    printf("[%d]: ", v);
    while (pt) {
      printf("%d(%d), ", pt->dest, pt->weight);
      pt = pt->next;
    }
    printf("\n");
  }
  printf("\n\n");
}

void increaseGraphStorage(struct Graph* graph, int size) {
  int prevSize = graph->storedNodes;
  graph->storedNodes = size;
  graph->nodes = (struct AdjList*)realloc(
      graph->nodes, graph->storedNodes * sizeof(struct AdjList));
  int i;
  for (i = prevSize; i < graph->storedNodes; ++i) graph->nodes[i].head = NULL;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
  struct AdjListNode* newNode = newAdjListNode(dest, weight);

  int max = src + 1 > dest + 1 ? src + 1 : dest + 1;
  if (graph->numberOfNodes < max) graph->numberOfNodes = max;

  if (graph->storedNodes < src + 1) increaseGraphStorage(graph, src + 1);

  struct AdjListNode* curr = graph->nodes[src].head;
  struct AdjListNode* prev = graph->nodes[src].head;

  if (!curr || newNode->dest < curr->dest) {
    newNode->next = graph->nodes[src].head;
    graph->nodes[src].head = newNode;
    return;
  }

  while (curr && curr->dest < newNode->dest) {
    prev = curr;
    curr = curr->next;
  };

  if (curr && curr->dest == newNode->dest) {
    curr->weight = newNode->weight;
    return;
  }

  newNode->next = curr;
  prev->next = newNode;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
  if (graph->storedNodes < src + 1) return;

  struct AdjListNode* curr = graph->nodes[src].head;
  struct AdjListNode* prev = graph->nodes[src].head;

  if (!curr || dest == curr->dest) {
    graph->nodes[src].head = curr->next;
    return;
  }

  while (curr && curr->dest < dest) {
    prev = curr;
    curr = curr->next;
  };

  if (curr && curr->dest == dest) {
    prev->next = curr->next;
    return;
  }
}

int getWeight(struct Graph* graph, int src, int dest) {
  if (graph->storedNodes < src + 1) return 0;

  struct AdjListNode* curr = graph->nodes[src].head;

  while (curr && curr->dest < dest) curr = curr->next;

  if (curr && curr->dest == dest) {
    return curr->weight;
  }
}

int* createArray(int size, int value) {
  int* ptr = (int*)malloc(size * sizeof(int));
  int i;
  for (i = size; i--;) ptr[i] = value;
  return ptr;
}

int* dijkstra(int startNode, int endNode, struct Graph* graph,
              int* totalWeight) {
  int s = startNode;
  int e = endNode;
  int n = graph->numberOfNodes;
  int* path = createArray(n, -1);
  int* minCosts = createArray(n, INFINITY);
  int* visited = createArray(n, 0);

  int currentNode, min, node;
  minCosts[s] = 0;
  while (currentNode != e) {
    int min = INFINITY, currentNode = -1;
    for (node = 0; node < n; node++) {
      if (!visited[node] && minCosts[node] < min) {
        min = minCosts[node];
        currentNode = node;
      }
    }
    if (min == INFINITY) break;

    struct AdjListNode* neighbor = graph->nodes[currentNode].head;
    while (neighbor) {
      if (!visited[neighbor->dest] &&
          (minCosts[neighbor->dest] == INFINITY ||
           (minCosts[neighbor->dest] >
            minCosts[currentNode] + neighbor->weight))) {
        path[neighbor->dest] = currentNode;
        minCosts[neighbor->dest] = minCosts[currentNode] + neighbor->weight;
      }
      neighbor = neighbor->next;
    }

    visited[currentNode] = 1;
  }

  *totalWeight = minCosts[e];

  return path;
}

int deletePath(struct Graph* graph, int* path, int startNode, int endNode) {
  int n = graph->numberOfNodes;
  int currentNode = endNode;
  while (currentNode != startNode) {
    if (path[currentNode] == -1) return 0;
    deleteEdge(graph, path[currentNode], currentNode);
    currentNode = path[currentNode];
  }
  return 1;
}

void printPathWeight(struct Graph* graph, int* path, int startNode,
                     int endNode) {
  int n = graph->numberOfNodes;
  int currentNode = endNode;
  int totalWeight = 0;
  while (currentNode != startNode) {
    if (path[currentNode] == -1) {
      printf("-1\n");
      return;
    }
    totalWeight += getWeight(graph, path[currentNode], currentNode);
    currentNode = path[currentNode];
  }
  printf("%d\n", totalWeight);
}

int main() {
  struct Graph* graph;
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  while (vertices != 0 && edges != 0) {
    graph = createGraph();
    int i, a, b, weight, start, end;
    scanf("%d %d", &start, &end);
    for (i = 0; i < edges; i++) {
      scanf("%d %d %d", &a, &b, &weight);
      addEdge(graph, a, b, weight);
    }
    scanf("%d %d", &vertices, &edges);
    int minimumWeight = -1;
    int* shortestPath = dijkstra(start, end, graph, &minimumWeight);
    if (minimumWeight == -1) {
      printf("-1\n");
      continue;
    }
    int currentWeight = minimumWeight;
    while (minimumWeight == currentWeight) {
      deletePath(graph, shortestPath, start, end);
      shortestPath = dijkstra(start, end, graph, &currentWeight);
      if (currentWeight == -1) {
        printf("-1\n");
        continue;
      }
    }
    printPathWeight(graph, shortestPath, start, end);
  }

  return 0;
}
