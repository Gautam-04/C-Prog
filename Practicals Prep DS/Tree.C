#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_tree()
{
    return NULL;
}

struct Node *insertElement(struct Node *tree, int val)
{
    struct Node *ptr, *parentPtr, *nodeptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (tree == NULL)
    {
       return ptr;
    }
    else
    {
        parentPtr = NULL;
        nodeptr = ptr;
        while (nodeptr != NULL)
        {
            parentPtr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentPtr->data)
        {
            parentPtr->left = ptr;
        }
        else
        {
            parentPtr->right = ptr;
        }
    }
    printf("\n %d is entered into tree", val);
    return tree;
}

void Preorder(struct Node *tree)
{
    if (tree != NULL)
    {
        printf("\t %d ", tree->data);
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Inorder(struct Node *tree)
{
    if (tree != NULL)
    {
        Inorder(tree->left);
        printf("\t %d ", tree->data);
        Inorder(tree->right);
    }
}

void Postorder(struct Node *tree)
{
    if (tree != NULL)
    {
        Postorder(tree->left);
        Postorder(tree->right);
        printf("\t %d ", tree->data);
    }
}

int main()
{
    struct Node *tree = create_tree();
    tree = insertElement(tree, 90);
    tree = insertElement(tree, 100);
    tree = insertElement(tree, 50);
    tree = insertElement(tree, 60);
    tree = insertElement(tree, 780);
    tree = insertElement(tree, 40);
    tree = insertElement(tree, 650);

    printf("Preorder: ");
    Preorder(tree);

    printf("\nInorder: ");
    Inorder(tree);

    printf("\nPostorder: ");
    Postorder(tree);

    return 0;
}
