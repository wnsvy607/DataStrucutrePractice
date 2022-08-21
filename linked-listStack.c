#include <stdio.h>
#include <stdlib.h>

typedef int data;

typedef struct node_ {
    data value;
    struct node_ *next;
} node;

typedef struct listStack {
    struct node_ *head;
} stack;

void init(stack *stk, data initData) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = initData;
    stk->head = newNode;
}

int isEmpty(stack *stk) {
    if (stk->head == '\0')
        return 1;
    else
        return 0;
}

void push(stack *stk, data newData) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = newData;
    newNode->next = stk->head;
    stk->head = newNode;
}

data pop(stack *stk) {
    if (isEmpty(stk)) {
        printf("스택에 값이 없습니다. 종료합니다.");
        exit(-1);
    }

    data temp = stk->head->value;
    node *tempNode = stk->head;
    stk->head = stk->head->next;
    free(tempNode);
    return temp;
}

data peek(stack *stk) {
    if (isEmpty(stk)) {
        printf("스택에 값이 없습니다. 종료합니다.");
        exit(-1);
    }

    return stk->head->value;
}

int main() {
    stack stk;
    init(&stk, 10);
    push(&stk, 51);
    push(&stk, 41);
    push(&stk, 31);
    push(&stk, 21);
    push(&stk, 10);
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", pop(&stk));
    }

}