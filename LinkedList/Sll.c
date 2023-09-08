#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

// Function prototypes
struct Node *insertBeginning(struct Node *start, int data);
struct Node *insertEnd(struct Node *start, int data);
struct Node *insertBefore(struct Node *start, int data, int beforeData);
struct Node *insertAfter(struct Node *start, int data, int afterData);
struct Node *deleteBeginning(struct Node *start);
struct Node *deleteEnd(struct Node *start);
struct Node *deleteBefore(struct Node *start, int beforeData);
struct Node *deleteAfter(struct Node *start, int afterData);
void search(struct Node *start, int key);
void display(struct Node *start);

int main()
{
    int choice, data, beforeData, afterData;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a node\n");
        printf("4. Insert after a node\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete before a node\n");
        printf("8. Delete after a node\n");
        printf("9. Search\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            start = insertBeginning(start, data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            start = insertEnd(start, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter data before which to insert: ");
            scanf("%d", &beforeData);
            start = insertBefore(start, data, beforeData);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter data after which to insert: ");
            scanf("%d", &afterData);
            start = insertAfter(start, data, afterData);
            break;
        case 5:
            start = deleteBeginning(start);
            break;
        case 6:
            start = deleteEnd(start);
            break;
        case 7:
            printf("Enter data before which to delete: ");
            scanf("%d", &beforeData);
            start = deleteBefore(start, beforeData);
            break;
        case 8:
            printf("Enter data after which to delete: ");
            scanf("%d", &afterData);
            start = deleteAfter(start, afterData);
            break;
        case 9:
            printf("Enter data to search: ");
            scanf("%d", &data);
            search(start, data);
            break;
        case 10:
            display(start);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

struct Node *insertBeginning(struct Node *start, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = start;
    return newNode;
}

struct Node *insertEnd(struct Node *start, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL)
    {
        return newNode;
    }

    struct Node *current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    return start;
}

struct Node *insertBefore(struct Node *start, int data, int beforeData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (start == NULL)
    {
        printf("List is empty, cannot insert before a node.\n");
        return start;
    }

    if (start->data == beforeData)
    {
        newNode->next = start;
        return newNode;
    }

    struct Node *current = start;
    while (current->next != NULL && current->next->data != beforeData)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Value not found in the list.\n");
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
    }

    return start;
}

struct Node *insertAfter(struct Node *start, int data, int afterData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (start == NULL)
    {
        printf("List is empty, cannot insert after a node.\n");
        return start;
    }

    struct Node *current = start;
    while (current != NULL && current->data != afterData)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value not found in the list.\n");
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
    }

    return start;
}

struct Node *deleteBeginning(struct Node *start)
{
    if (start == NULL)
    {
        printf("List is empty, cannot delete from the beginning.\n");
        return start;
    }

    struct Node *temp = start;
    start = start->next;
    free(temp);
    return start;
}

struct Node *deleteEnd(struct Node *start)
{
    if (start == NULL)
    {
        printf("List is empty, cannot delete from the end.\n");
        return start;
    }

    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }

    struct Node *current = start;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return start;
}

struct Node *deleteBefore(struct Node *start, int beforeData)
{
    if (start == NULL || start->next == NULL)
    {
        printf("List is empty or has only one node, cannot delete before a node.\n");
        return start;
    }

    if (start->next->data == beforeData)
    {
        struct Node *temp = start->next;
        start->next = temp->next;
        free(temp);
        return start;
    }

    struct Node *current = start;
    while (current->next->next != NULL && current->next->next->data != beforeData)
    {
        current = current->next;
    }

    if (current->next->next == NULL)
    {
        printf("Value not found in the list.\n");
    }
    else
    {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return start;
}

struct Node *deleteAfter(struct Node *start, int afterData)
{
    if (start == NULL)
    {
        printf("List is empty, cannot delete after a node.\n");
        return start;
    }

    if (start->data == afterData)
    {
        struct Node *temp = start->next;
        start->next = temp->next;
        free(temp);
        return start;
    }

    struct Node *current = start;
    while (current != NULL && current->data != afterData)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Value not found in the list or it's the last node.\n");
    }
    else
    {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return start;
}

void search(struct Node *start, int key)
{
    struct Node *current = start;
    int position = 1;
    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

void display(struct Node *start)
{
    struct Node *current = start;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
