#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}


/*Dequeue*/
int dequeue(struct Queue* q)
{
    int value = -1;
    
    /* check the queue is Empty*/
    if (q->front == NULL)
    {
        printf("The queue is empty \n");
        return value;
    }

    struct Node* t = q->front;
    q->front = t->next;
    value = t->data;
    free(t);
    return value;
}


/*Enqueue*/
void enqueue(struct Queue* q, int x)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    /*check queue is full*/
    if (node == NULL)
    {
        printf("Queue is full \n");
        return;
    };

    node->data = x;
    node->next = NULL;

    if (q->front == NULL)
    {
        q->rear = q->front = node;
    } else 
    {
        q->rear->next = node;
        q->rear = node;
    }
};


/*Display the queue*/
void displayQueue(struct Queue* q)
{
    struct Node* p = q->front;
    int idx=0;

    while (p != NULL)
    {
        printf("Node %d value  %d \n", idx++, p->data);
        p = p->next;
    }
}


/*first*/

/*last*/

int main(int argc, char const *argv[])
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(q);
    displayQueue(q);

    enqueue(q, 5);
    enqueue(q, 3);
    enqueue(q, 1);
    displayQueue(q);


    int dequeuedValue = dequeue(q);

    while (dequeuedValue != -1)
    {
        printf("Dequeued value is %d \n", dequeuedValue);
        dequeuedValue = dequeue(q);
    }

    return 0;
}
