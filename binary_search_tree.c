#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* leftNode;
    struct TreeNode* rightNode;
};

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



struct BinarySearchTree
{
    struct TreeNode* root;
};

/*Initialize a tree*/
struct BinarySearchTree* initializeBinarySearchTree(int value)
{
    struct BinarySearchTree* tree = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));

    if (tree == NULL)
    {
        printf("The memory is full" );
        exit(1);
    }

    tree->root = initializeTreeNode(value);
    return tree;
}


struct TreeNode* recursiveSearch(struct TreeNode* node, int value)
{   
    if (node == NULL)
        return NULL;

    if (node->value == value)
        return node;
    else if (value > node->value)
        return recursiveSearch(node->rightNode, value);
    else
        return recursiveSearch(node->leftNode, value);
}

void insertNode(struct TreeNode* node, int value)
{   
    struct TreeNode *prevNode;

    while (node != NULL)
    {
        if (value < node->value)
        {
            prevNode = node;
            node = node->leftNode;

            if (node == NULL)
            {
                prevNode->leftNode = initializeTreeNode(value);
                break;
            }
        }
        else if (value > node->value)
        {
            prevNode = node;
            node = node->rightNode;

            if (node == NULL)
            {
                prevNode->rightNode = initializeTreeNode(value);
                break;
            }
        }
        else
        {
            printf("Cannot insert because %d exists in the tree\n", value);
            break;
        }
    }
}

struct TreeNode* recursiveInsert(struct TreeNode *node, int value)
{
    if (node == NULL)
    {
        node = initializeTreeNode(value);
        return node;
    }

    if (value > node->value)
        node->rightNode = recursiveInsert(node->rightNode, value);
    else if (value < node->value)
        node->leftNode = recursiveInsert(node->leftNode, value);
    
    return node;
}

void inOrderDisplay(struct TreeNode *node)
{
    if (node != NULL)
    {
        inOrderDisplay(node->leftNode);
        printf("%d ", node->value);
        inOrderDisplay(node->rightNode);
    }
}

int heightTree(struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    int heightOfLeft = heightTree(node->leftNode);
    int heightOfRight = heightTree(node->rightNode);    

    if (heightOfLeft > heightOfRight)
        return heightOfLeft + 1;

    return heightOfRight + 1;
}

struct TreeNode *findPreSuccessor(struct TreeNode *node)
{
    while (node && node->rightNode != NULL)
    {
        node = node->rightNode;
    }

    return node;
}

struct TreeNode *findSuccessor(struct TreeNode *node)
{
    while (node && node->leftNode != NULL)
    {
        node = node->leftNode;
    }

    return node;
}

struct TreeNode *deleteNode(struct TreeNode *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }
    if ((node->leftNode == NULL) & (node->rightNode == NULL))
    {
        free(node);
        return NULL;
    }

    if (value > node->value)
    {
        node->rightNode = deleteNode(node->rightNode, value);
    }
    else if (value < node->value)
    {
        node->leftNode = deleteNode(node->leftNode, value);
    }
    else
    {
        if (heightTree(node->leftNode) > heightTree(node->rightNode))
        {
            struct TreeNode *preNode = findPreSuccessor(node->leftNode);
            node->value = preNode->value;
            node->leftNode = deleteNode(node->leftNode, preNode->value);
        }
        else
        {
            struct TreeNode *successor = findSuccessor(node->rightNode);
            node->value = successor->value;
            node->rightNode = deleteNode(node->rightNode, successor->value);
        }
    }

    return node;
}


int main(int argc, char const *argv[])
{
    struct BinarySearchTree *tree = initializeBinarySearchTree(28);

    recursiveInsert(tree->root, 18);
    recursiveInsert(tree->root, 20);
    recursiveInsert(tree->root, 13);
    recursiveInsert(tree->root, 2);
    recursiveInsert(tree->root, 15);
    recursiveInsert(tree->root, 38);
    recursiveInsert(tree->root, 43);
    recursiveInsert(tree->root, 40);
    recursiveInsert(tree->root, 33);
    recursiveInsert(tree->root, 35);

    printf("Height of the tree: %d \n", heightTree(tree->root));

    printf("Tree before delete 28: ");
    inOrderDisplay(tree->root);

    printf("\nTree before delete 28: ");
    deleteNode(tree->root, 28);
    inOrderDisplay(tree->root);

    return 0;
}
