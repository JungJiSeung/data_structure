#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

typedef struct _Queue {
    Node* head;
    Node* rear;
} Queue;

/*
 * Operation : Add data to Queue
 * Arguments : queue is pointer of data structure Queue
 *             data is Data add to Queue
 */
void enqueue(Queue* queue, int data) {
    Node* node;
    
    if(queue == NULL) return;

    node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    if(queue->head == NULL) {
        queue->head = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

/*
 * Operation : Remove data from Queue And return removed data
 * Argument  : queue is pointer of data structure Queue
 * return    : if queue is empty then return -1, else Removed Data
 */
int dequeue(Queue* queue) {
    Node* node;
    int res;

    if(queue == NULL) return -1;
    if(queue->head == NULL) return -1;
    
    node = queue->head;
    queue->head = node->next;
    res = node->data;
    free(node);

    return res;
}

/*
 * Operation : print all data of queue
 * Argument  : queue is pointer of data structure Queue
 */
void print(Queue* queue) {
    Node* node;

    if(queue == NULL) return;

    node = queue->head;

    while(node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int main(void) {
    Queue* queue = malloc(sizeof(Queue));

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    print(queue);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
}
