#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void initializeNode(Node* node, int data)
{
    node->data = data;
    node->next = NULL;
}

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
    int length;
};

void initializeLinkedList(LinkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void appendFirst(LinkedList *list, Node *p)
{
    if (list->head == NULL)
    {
        list->head = p;
        ++list->length;
    }
    else {
        p->next = list->head;
        list->head = p;
        ++list->length;
    }
}


void appendArrayValues(int arr[], int n, LinkedList* list)
{
    struct Node *t;

    for (int i=0; i < n; i++)
    {
        t = new Node;
        initializeNode(t, arr[i]);
        appendFirst(list, t);
    }
}

void sortLinkedList(LinkedList* list)
{
    Node current;
    bool swap;

    while (swap)
}

void displayLinkedList(LinkedList *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        printf("%p - Node(data=%d next=%p )\n", p, p->data, p->next);
        p = p->next;
    }
    printf("Length of the LinkedList is %d", list->length);
}



int main(int argc, char const *argv[])
{
    struct LinkedList myList;
    initializeLinkedList(&myList);
    
    int arr[] = {1,3,5,7,9,11};

    appendArrayValues(arr, 6, &myList);

    Node *newNode = new Node;
    newNode->data = 13;
    newNode->next = NULL;
    appendFirst(&myList, newNode);

    displayLinkedList(&myList);

    return 0;
}
