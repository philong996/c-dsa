#include<iostream>

using namespace std;

struct ArrayStack
{
    int size;
    int *data;
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

void initializeStack(ArrayStack *stack, int size)
{
    stack->size = size;
    stack->data = new int[size];
    stack->top = -1;
}

int isFull(ArrayStack* stack)
{
    if (stack->top < stack->size - 1)
        return 0;
    else
        return 1;
}

int isEmpty(ArrayStack* stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(ArrayStack* stack, int value)
{
    if (isFull(stack) == 0)
        stack->data[++stack->top] = value;
    else
        printf("Cannot append the value %d to the stack because it is full\n", value);
}

int pop(ArrayStack* stack)
{
    if (isEmpty(stack) == 1)
    {
        printf("The stack is empty");
    }

    return stack->data[stack->top--];
}



void printStack(ArrayStack &stack)
{
    printf("Stack size: %d \n", stack.size);
    printf("Stack top: %d \n", stack.top);
    printf("Stack data pointer: %p \n", stack.data);
}

int main()
{
    ArrayStack stack;

    initializeStack(&stack, 5);

    push(&stack, 10);
    push(&stack, 12);

    printStack(stack);

    int popValue = pop(&stack);
    printf("Value is pop from the stack %d \n", popValue);

    printStack(stack);

    return 0;
}

