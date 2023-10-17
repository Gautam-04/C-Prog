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
    if (tree == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (val < tree->data)
        tree->left = insertElement(tree->left, val);
    else if (val > tree->data)
        tree->right = insertElement(tree->right, val);

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

void BFS(struct Node *tree)
{
    if (tree == NULL)
        return;

    struct Node *queue[1000]; // A queue to store nodes
    int front = -1, rear = -1;

    queue[++rear] = tree; // Enqueue the root node

    while (front != rear)
    {
        struct Node *current = queue[++front]; // Dequeue the front node
        printf("\t %d ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left; // Enqueue the left child

        if (current->right != NULL)
            queue[++rear] = current->right; // Enqueue the right child
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

    printf("\nBFS: ");
    BFS(tree);
    return 0;
}
