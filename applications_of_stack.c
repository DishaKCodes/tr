#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int top;
    int size;
    int* A;
} stack;

void init_stack(stack* s, int size) {
    s->top = -1;
    s->size = size;
    s->A = (int*)malloc(size * sizeof(int));
    if (s->A == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int isEmpty(stack s) {
    return (s.top == -1);
}

int pop(stack* s) {
    if (isEmpty(*s)) {
        return INT_MIN;
    }
    return s->A[s->top--];
}

int peek(stack s) {
    if (isEmpty(s)) {
        return INT_MIN;
    }
    return s.A[s.top];
}

int isFull(stack s) {
    return (s.top == s.size - 1);
}

void push(stack* s, int val) {
    if (isFull(*s)) {
        printf("Stack overflow\n");
        return;
    }
    s->A[++(s->top)] = val;
}

void displayStack(stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.A[i]);
    }
}

int main() {
    stack s;
    init_stack(&s, 5);
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    int a = pop(&s);
    printf("Popped value: %d\n", a);

    int b = peek(s);
    printf("Top value: %d\n", b);

    displayStack(s);

    free(s.A);

    return 0;
}