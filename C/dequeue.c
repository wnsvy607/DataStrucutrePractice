#include <stdio.h>
#include <stdlib.h>

typedef int data;
#define TRUE 1
#define FALSE 0


typedef struct _Node {
    data value;
    struct _Node *next;
    struct _Node *prev;
} node;

typedef struct Dequeue {
    node *head;
    node *tail;
} dequeue;

dequeue createDequeue(){
    dequeue deq;
    deq.head = NULL;
    deq.tail = NULL;
    return deq;
}

int isEmpty(dequeue *q){
    if(q->head == NULL){
        return TRUE;
    }
    return FALSE;
}




int main() {
    printf("Hello, World!\n");
    return 0;
}
