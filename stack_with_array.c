#include<stdio.h>
#include <stdlib.h>

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

void initializeStack(struct ArrayStack *stack, int size)
{
    stack->size = size;
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
}

int isFull(struct ArrayStack* stack)
{
    if (stack->top < stack->size - 1)
        return 0;
    else
        return 1;
}

int isEmpty(struct ArrayStack* stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(struct ArrayStack* stack, int value)
{
    if (isFull(stack) == 0)
        stack->data[++stack->top] = value;
    else
        printf("Cannot append the value %d to the stack because it is full\n", value);
}

int pop(struct ArrayStack* stack)
{
    if (isEmpty(stack) == 1)
    {
        printf("The stack is empty");
    }

    return stack->data[stack->top--];
}

int* peek(struct ArrayStack* stack, int index)
{
    if ((index > stack->size - 1) | (index > stack->top))
    {
        printf("Cannot get the index %d", index);
        return NULL;
    }

    int *result = &stack->data[index];

    for (int i = index+1; i <= stack->top; i++)
    {
        stack->data[i - 1 ] = stack->data[i]; 
    }

    return result;
}

void printStack(struct ArrayStack stack)
{
    printf("Stack size: %d \n", stack.size);
    printf("Stack top: %d \n", stack.top);
    printf("Stack data pointer: %p \n", stack.data);
}

int main()
{
    struct ArrayStack stack;

    initializeStack(&stack, 5);

    push(&stack, 10);
    push(&stack, 12);
    push(&stack, 14);
    push(&stack, 15);
    push(&stack, 17);
    push(&stack, 18);

    printStack(stack);

    int popValue = pop(&stack);
    printf("Value is pop from the stack %d \n", popValue);


    int *peek_value = peek(&stack, 2);
    if (peek_value == NULL)
        printf("Peek value is null\n");
    else
        printf("Peek value is %d \n", *peek_value);
    
    printStack(stack);

    return 0;
}

