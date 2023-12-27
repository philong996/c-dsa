/*
Use linked list to store the information of employee

insert operation
sort operation with salary
delete operation with the employee code
search employee with employee code
find the max salary of employees
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

struct Employee
{
    char employeeCode[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    float salary;
};

struct Employee* initEmployee(char name[], char employeeCode[], float salary)
{
    struct Employee *e = (struct Employee*)malloc(sizeof(struct Employee));
    strncpy(e->employeeCode, employeeCode, sizeof(e->employeeCode));
    strncpy(e->name, name, sizeof(e->name));
    e->salary = salary;

    return e;
}

struct Node
{
    struct Employee* data;
    struct Node* next;
};


void displayNode(struct Node* node)
{
    printf(
        "%p - Employee[code: %s, name: %s, salary: %f] - next: %p \n"
        , node
        , node->data->employeeCode
        , node->data->name
        , node->data->salary
        , node->next
    );
}

struct Node* initNode(char name[], char employeeCode[], float salary)
{
    struct Employee* e = initEmployee(name, employeeCode, salary);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = e;
    node->next = NULL;
    return node;
}

struct EmployeeLinkedList
{
    struct Node* head;
    struct Node* tail;
    int length;
};

struct EmployeeLinkedList* initEmployeeLinkedList()
{
    struct EmployeeLinkedList* ll = (struct EmployeeLinkedList*)malloc(sizeof(struct EmployeeLinkedList));

    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
}

void appendLast(struct EmployeeLinkedList* ll, char name[], char employeeCode[], float salary)
{
    struct Node* newNode = initNode(name, employeeCode, salary);
    if (ll->head == NULL)
    {
        ll->head = newNode;
    }
    else
    {
        if (ll->tail == NULL)
        {
            ll->head->next = newNode;
            ll->tail = newNode;
        }
        else
        {
            ll->tail->next = newNode;
            ll->tail = newNode;
        }
    }

    ll->length++;
}

float findMaxSalary(struct EmployeeLinkedList* ll)
{
    float result = 0;
    struct Node* p = ll->head;

    while (p != NULL)
    {
        if (p->data->salary > result)
        {
            result = p->data->salary;
        }

        p = p->next;
    }

    return result;
}

void searchEmployee(struct EmployeeLinkedList* ll, char employeeCode[])
{
    struct Employee* result = NULL;
    struct Node* p = ll->head;

    while (p != NULL)
    {
        if (strcmp(p->data->employeeCode, employeeCode) == 0)
        {
            result = p->data;            
        }
        p = p->next;
    }

    if (result != NULL)
    {
        printf("There is an employee with the code %s\n", employeeCode);
    }
    else
    {
        printf("There is no employee with the code %s\n", employeeCode);
    }
}

void displayLinkedList(struct EmployeeLinkedList* ll)
{
    printf("Length of the linked list: %d\n", ll->length);

    struct Node* p = ll->head;
    while(p != NULL)
    {
        displayNode(p);
        p = p->next;
    }
}

void sortEmployeesWithSalary(struct EmployeeLinkedList* ll)
{
    struct Node* currentNode = ll->head;
    
    while (currentNode != NULL)
    {
        struct Node* nextNode = currentNode->next;
        
        while (nextNode != NULL)
        {
            if (currentNode->data->salary > nextNode->data->salary)
            {
                struct Employee* temp = currentNode->data;                
                currentNode->data = nextNode->data;
                nextNode->data = temp;
            }

            nextNode = nextNode->next;
        }

        currentNode = currentNode->next;
    }
    
}

int main(int argc, char const *argv[])
{
    struct EmployeeLinkedList *ell = initEmployeeLinkedList();

    appendLast(ell, "A", "LN001", 10000);
    appendLast(ell, "B", "LN002", 30000);
    appendLast(ell, "C", "LN003", 20000);
    appendLast(ell, "D", "LN004", 50000);
    appendLast(ell, "E", "LN005", 15000);

    displayLinkedList(ell);

    printf("Max salary of employees: %f\n", findMaxSalary);

    searchEmployee(ell, "LN003");
    searchEmployee(ell, "LN004");

    printf("Employees after sorted: \n");
    sortEmployeesWithSalary(ell);
    displayLinkedList(ell);

    return 0;
}
