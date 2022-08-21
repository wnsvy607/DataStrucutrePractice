#include <stdio.h>
#include <stdlib.h>

typedef int data;
#define TRUE 1
#define FALSE 0


typedef struct _Node {
    data value;
    struct _Node *next
} node;

typedef struct Queue {
    node *front;
    node *rear;
} queue;

queue createQueue() {
    queue newQueue;
    newQueue.front = NULL;
    newQueue.rear = NULL;
    return newQueue;
}

int is_Empty(queue *q) {
    if (q->front == NULL)
        return TRUE;
    else
        return FALSE;
};

void enqueue(queue *q, data item) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = item;
    newNode->next = NULL;

    if(is_Empty(q)){
        q->front = newNode;
        q->rear = newNode;
    } else{
        q->rear->next = newNode;
        q->rear = newNode;
    }

}

data dequeue(queue *q){
    if(is_Empty(q)){
        printf("The queue is empty.");
        exit(-1);
    }

    node *tempNode = q->front;
    data tempItem = q->front->value;
    q->front = q->front->next;
    free(tempNode);
    return tempItem;
}

int main() {
    int n = 10000;
    queue q = createQueue();
    for (int i = 0; i < n; ++i) {
        enqueue(&q, i);
    }

    for (int i = 0; i < n+1; ++i) {
        printf("%d\n", dequeue(&q));
    }
}
