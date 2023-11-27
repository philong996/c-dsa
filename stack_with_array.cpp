#include<iostream>

using namespace std;

struct ArrayStack
{
    int size;
    int *stackData;
    int top;
};

/*
Operations

push
pop
peek
stackTop
isEmpty
isFull
*/

void initializeStack(ArrayStack* stack, int size)
{
    stack->size = size;
    stack->stackData = new int[size];
    stack->top = -1;
}

void push(ArrayStack* stack, int value)
{
    stack->stackData[stack->top++] = value;
}

void printStack(ArrayStack &stack)
{
    printf("Stack size: %d", stack.size);
    printf("Stack top: %d", stack.top);
}

int main()
{
    ArrayStack stack;

    initializeStack(&stack, 10);

    printStack(stack);

    return 0;
}

