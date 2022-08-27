#include <stdio.h>
#include <stdlib.h>

typedef int data;
#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 100



//typedef struct _Node {
//    data value;
//    struct _Node *next
//} node;

typedef struct Queue {
    int front;
    int rear;
    data q_arr[QUEUE_SIZE];
} queue;

queue createQueue() {
    queue newQueue;
    newQueue.front = 0;
    newQueue.rear = 0;
    return newQueue;
}

int is_Empty(queue *q) {
    if (q->front == q->rear)
        return TRUE;
    else
        return FALSE;
};

int nextPostIdx(int pos) {
    if (pos == QUEUE_SIZE - 1)
        return 0;
    else
        return pos + 1;
}

int is_Full(queue *q) {
    if (nextPostIdx(q->rear) == q->front)
        return TRUE;
    else
        return FALSE;
}

void enqueue(queue *q, data value) {
    if(is_Full(q)){
        printf("The queue is full.");
        exit(-1);
    }
    q->rear = nextPostIdx(q->rear);
    q->q_arr[q->rear] = value;
}

data dequeue(queue *q){
    if(is_Empty(q)){
        printf("The queue is empty.");
        exit(-1);
    }
    q->front = nextPostIdx(q->front);
    return q->q_arr[q->front];
}


int main() {
    queue q = createQueue();
    int n = 100;
    for (int i = 1; i < n; ++i) {
        enqueue(&q, i);
    }

    for (int i = 1; i < n; ++i) {
        printf("%d\n", dequeue(&q));
    }

}
