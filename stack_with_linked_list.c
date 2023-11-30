#include<stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct LLStack
{
    struct Node *top;
    int length;
};

void initializeStack(struct LLStack *stack)
{
    stack->top = NULL;
}

void push(struct LLStack *stack, int value)
{
    if (stack->top == NULL)
    {
        stack->top = (struct Node*)malloc(sizeof(struct Node));
        stack->top->data = value;
        stack->top->next = NULL;

    }
    else
    {
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));

        p->data = value;
        p->next = stack->top;

        stack->top = p;
    }
};

int pop(struct LLStack *stack)
{
    if (stack->top == NULL)
        return -1;
    
    struct Node *p = stack->top;
    stack->top = p->next;
    int result = p->data;
    free(p);
    return result;
}

int peek(struct LLStack *stack, int pos)
{
    int cnt = 1;
    int value = -1;
    struct Node* p = stack->top;

    while ((p != NULL) && (cnt < pos) )
    {
        p = p->next;
        cnt++;
    }

    if (p != NULL)
    {
        value = p-> data;
    }

    return value;
}


void printStack(struct LLStack *stack)
{
    struct Node* p = stack->top; 
    while (p != NULL)
    {
        printf("Node %p %d \n", p, p->data);
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{
    struct LLStack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 5);
    int x = pop(&stack);
    printf("pop value %d \n", x);

    push(&stack, 7);

    printStack(&stack);

    int value1 = peek(&stack, 1);
    printf("value1 = %d \n", value1);

    int value2 = peek(&stack, 2);
    printf("value2 = %d \n", value2);

    int value3 = peek(&stack, 3);
    printf("value3 = %d \n", value3);

    return 0;
}
