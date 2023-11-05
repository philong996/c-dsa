#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


void createLinkedList(int arr[], int n, struct Node* &first)
{
    struct Node *t, *last;

    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i=1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;

        last->next = t;
    
        last = t;
    }
}

void displayLinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%p - Node(data=%d next=%p )\n", p, p->data, p->next);
        p = p->next;
    }
}


int main(int argc, char const *argv[])
{
    struct Node* first = NULL;
    
    int arr[] = {1,3,5,7,9,11};

    createLinkedList(arr, 6, first);
    displayLinkedList(first);

    return 0;
}
