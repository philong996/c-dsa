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

void appendFirst(LinkedList *list, int value)
{
    Node *p = new Node; 
    initializeNode(p, value);

    if (list->head == NULL)
    {
        list->head = p;
    }
    else {
        p->next = list->head;
        list->head = p;
        
    }
    ++list->length;
}

void appendLast(LinkedList *list, int value)
{
    Node *p = new Node;
    initializeNode(p, value);

    if (list->head == NULL)
    {
        list->head = p;
    }
    else 
    {
        if (list->tail != NULL)
        {
            list->tail->next = p;
        }
        else
        {
            list->head->next = p;
            list->tail = p;
        }
        list->tail = p;
    }
    ++list->length;

}

void appendArrayValues(int arr[], int n, LinkedList* list)
{

    for (int i=0; i < n; i++)
    {
        appendLast(list, arr[i]);
    }
}

void swap(Node *a, Node *b)
{
    int temp = a->data;

    a->data = b->data;
    b->data = temp;
}

void sortLinkedList(LinkedList* list)
{
    Node *i, *j;
    int flag = 0;

    for (i = list->head; i != list->tail; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i, j);
                flag = 1;
            }
        }
        
        if (flag == 0)
            break;
    }
}

void removeValue(LinkedList *list, int value)
{
    Node *temp = list->head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                list->head = temp->next;
                delete temp;
                --list->length;
                temp = list->head;
            }
            else
            {
                prev->next = temp->next;
                --list->length;
                delete temp;
                temp = prev->next;
            }
        } else 
        {
            prev = temp;
            temp = temp->next;            
        }
    }
}

void displayLinkedList(LinkedList list)
{
    Node *p = list.head;
    while (p != NULL)
    {
        printf("%p - Node(data=%d next=%p )\n", p, p->data, p->next);
        p = p->next;
    }
    printf("Length of the LinkedList is %d \n", list.length);
}




int main(int argc, char const *argv[])
{
    struct LinkedList myList;
    initializeLinkedList(&myList);
    
    int arr[] = {1,3,5,7,9,11};

    appendArrayValues(arr, 6, &myList);

    appendFirst(&myList, 13);
    appendFirst(&myList, 18);
    appendLast(&myList, 21);
    appendLast(&myList, 1);


    displayLinkedList(myList);

    sortLinkedList(&myList);

    cout << "List after sorted " << endl;
    displayLinkedList(myList);


    removeValue(&myList, 21);
    cout << "list after removing 21" << endl;
    displayLinkedList(myList);

    removeValue(&myList, 9);
    cout << "list after removing 9" << endl;
    displayLinkedList(myList);

    removeValue(&myList, 1);
    cout << "list after removing 1" << endl;
    displayLinkedList(myList);


    removeValue(&myList, 3);
    removeValue(&myList, 5);
    removeValue(&myList, 7);
    removeValue(&myList, 11);
    removeValue(&myList, 13);
    removeValue(&myList, 18);

    cout << "list after removing all elements" << endl;
    displayLinkedList(myList);

    return 0;
}
