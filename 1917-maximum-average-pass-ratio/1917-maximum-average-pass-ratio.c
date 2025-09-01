#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pass;
    int total;
} Class;

typedef struct {
    Class** data;
    int size;
    int capacity;
} MaxHeap;

double gain(int pass, int total) {
    return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
}

MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (Class**)malloc(sizeof(Class*) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Class** a, Class** b) {
    Class* tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyUp(MaxHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        double g1 = gain(heap->data[idx]->pass, heap->data[idx]->total);
        double g2 = gain(heap->data[parent]->pass, heap->data[parent]->total);
        if (g1 > g2) {
            swap(&heap->data[idx], &heap->data[parent]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MaxHeap* heap, int idx) {
    int left, right, largest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        largest = idx;

        if (left < heap->size &&
            gain(heap->data[left]->pass, heap->data[left]->total) >
            gain(heap->data[largest]->pass, heap->data[largest]->total)) {
            largest = left;
        }
        if (right < heap->size &&
            gain(heap->data[right]->pass, heap->data[right]->total) >
            gain(heap->data[largest]->pass, heap->data[largest]->total)) {
            largest = right;
        }
        if (largest != idx) {
            swap(&heap->data[idx], &heap->data[largest]);
            idx = largest;
        } else break;
    }
}

void push(MaxHeap* heap, Class* c) {
    heap->data[heap->size] = c;
    heapifyUp(heap, heap->size);
    heap->size++;
}

Class* pop(MaxHeap* heap) {
    if (heap->size == 0) return NULL;
    Class* top = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return top;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    MaxHeap* heap = createHeap(classesSize + extraStudents);

    for (int i = 0; i < classesSize; i++) {
        Class* c = (Class*)malloc(sizeof(Class));
        c->pass = classes[i][0];
        c->total = classes[i][1];
        push(heap, c);
    }

    for (int e = 0; e < extraStudents; e++) {
        Class* c = pop(heap);
        c->pass += 1;
        c->total += 1;
        push(heap, c);
    }

    double sum = 0.0;
    for (int i = 0; i < heap->size; i++) {
        sum += (double)heap->data[i]->pass / heap->data[i]->total;
        free(heap->data[i]);
    }

    free(heap->data);
    free(heap);

    return sum / classesSize;
}
