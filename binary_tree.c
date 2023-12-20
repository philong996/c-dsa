#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* leftNode;
    struct TreeNode* rightNode;
};

/*Initialize a node*/
struct TreeNode* initializeTreeNode(int value) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (node == NULL)
    {
        printf("The memory is full");
        exit(1);
    }

    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}


/*Define the queue for binary tree*/
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

struct QueueNode* initializeQueueNode(struct TreeNode* treeNode)
{
    struct QueueNode* queueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));

    if (queueNode == NULL)
    {
        printf("The memory is full");
        exit(1);
    }

    queueNode->data = treeNode;
    queueNode->next = NULL;

    return queueNode;
}


struct Queue
{
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

struct Queue* initializeQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL)
    {
        printf("The memory is full \n");
        exit(1);
    }

    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node)
{
    struct QueueNode* queueNode = initializeQueueNode(node);

    /*Check the queue is empty assign Node to the rear*/
    if (q->front == NULL)
    {
        q->rear = q->front = queueNode;
    }
    else 
    {
        q->rear->next = queueNode;
        q->rear = queueNode;
    }
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q)
{
    struct TreeNode* result = NULL;
    
    /*Check the queue is empty*/
    if (q->front == NULL)
    {
        printf("The queue is empty  \n");
        return result;    
    }

    struct QueueNode* queueNode = q->front;
    
    
    q->front = q->front->next;
    
    
    result = queueNode->data;
    q->size--;
    free(queueNode);
    return result;
}


struct BinaryTree
{
    struct TreeNode* root;
};

/*Initialize a tree*/
struct BinaryTree* initializeBinaryTree()
{
    struct BinaryTree* tree = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));

    if (tree == NULL)
    {
        printf("The memory is full" );
        exit(1);
    }

    tree->root = NULL;
    return tree;
}

/*Input the tree*/
void inputTree(struct BinaryTree* tree)
{
    struct Queue* q = initializeQueue();
    struct TreeNode* p;
    struct TreeNode* t;
    int value;

    printf("Input for root: ");
    scanf("%d", &value);
    
    /*Initialize the TreeNode*/
    p = initializeTreeNode(value);
    tree->root = p;
    enqueue(q, p);
    p = dequeue(q);

    while (p != NULL)
    {
        printf("input for left node of %d: ", p->value);
        scanf("%d", &value);
        if (value != -1)
        {
            t = initializeTreeNode(value);
            enqueue(q, t);
            p->leftNode = t;
        }

        printf("input for right node of %d: ", p->value);
        scanf("%d", &value);
        if (value != -1)
        {
            t = initializeTreeNode(value);
            enqueue(q, t);
            p->rightNode = t;
        }
        p = dequeue(q);
    }

}

/*display tree*/
void preOrderDisplay(struct TreeNode* p)
{
    if (p != NULL)
    {
        printf("%d ", p->value);
        preOrderDisplay(p->leftNode);
        preOrderDisplay(p->rightNode);
    }
}

void inOrderDisplay(struct TreeNode* p)
{
    if (p != NULL)
    {
        inOrderDisplay(p->leftNode);
        printf("%d ", p->value);
        inOrderDisplay(p->rightNode);
    }
}

void postOrderDisplay(struct TreeNode* p)
{
    if (p != NULL)
    {
        inOrderDisplay(p->leftNode);
        inOrderDisplay(p->rightNode);
        printf("%d ", p->value);
    }
}

void levelOrderDisplay(struct BinaryTree* tree)
{
    struct Queue* q = initializeQueue();
    struct TreeNode* p = tree->root;
    printf("%d ", p->value);

    while (p != NULL)
    {
        if (p->leftNode != NULL)
        {
            printf("%d ", p->leftNode->value);
            enqueue(q, p->leftNode);
        }

        if (p->rightNode != NULL)
        {
            printf("%d ", p->rightNode->value);
            enqueue(q, p->rightNode);
        }
        p = dequeue(q);
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct BinaryTree* tree = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    inputTree(tree);

    levelOrderDisplay(tree);

    return 0;
}
