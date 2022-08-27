#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
typedef int data;

struct Array_Stack {
    data arr[SIZE];
    int top;
} typedef stack;

void init(stack *stk) {
    stk->top = -1;
}

int isEmpty(stack *stk) {
    if (stk->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *stk, data value) {
    stk->top++;
    stk->arr[stk->top] = value;
}

data pop(stack *stk) {
    if (isEmpty(stk)) {
        printf("스택에 값이 없습니다. 종료합니다.");
        exit(-1);
    }

    data temp = stk->arr[stk->top];
    stk->top--;
    return temp;
}

data peek(stack *stk) {
    if (isEmpty(stk)) {
        printf("스택에 값이 없습니다. 종료합니다.");
        exit(-1);
    }

    return stk->arr[stk->top];
}

int main() {
    stack stk;
    init(&stk);
    push(&stk, 51);
    push(&stk, 41);
    push(&stk, 31);
    push(&stk, 21);
    push(&stk, 10);
    for (int i = 0; i < 6; ++i) {
        printf("%d\n", peek(&stk));
    }

}
