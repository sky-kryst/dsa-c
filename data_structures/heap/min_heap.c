#include "min_heap.h"
#include <stdlib.h>

static void heapSwap(HeapNode *a, HeapNode *b) {
  HeapNode tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapInit(MinHeap *h, int capacity) {
  h->data = malloc(capacity * sizeof(HeapNode));
  h->size = 0;
  h->capacity = capacity;
}

void heapFree(MinHeap *h) { free(h->data); }

void heapPush(MinHeap *h, HeapNode node) {
  if (h->size == h->capacity) {
    h->capacity *= 2;
    h->data = realloc(h->data, h->capacity * sizeof(HeapNode));
  }

  int i = h->size++;
  h->data[i].weight = node.weight;
  h->data[i].vertex = node.vertex;

  // Sift up
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (h->data[parent].weight <= h->data[i].weight)
      break;
    heapSwap(&h->data[parent], &h->data[i]);
    i = parent;
  }
}

HeapNode heapPop(MinHeap *h) {
  HeapNode top = h->data[0];
  h->size--;
  h->data[0] = h->data[h->size];

  // Sift down
  int i = 0;
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < h->size && h->data[left].weight < h->data[smallest].weight)
      smallest = left;
    if (right < h->size && h->data[right].weight < h->data[smallest].weight)
      smallest = right;

    if (smallest == i)
      break;

    heapSwap(&h->data[i], &h->data[smallest]);
    i = smallest;
  }

  return top;
}

HeapNode createHeapNode(int weight, int vertex) {
  HeapNode node;
  node.weight = weight;
  node.vertex = vertex;
  return node;
}

bool heapEmpty(MinHeap *h) { return h->size == 0; }
