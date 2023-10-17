#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


struct Node *start = NULL;
struct Node *insertBegin(struct Node *start, int data);
struct Node *insertEnd(struct Node *start, int data);
struct Node *insertBefore(struct Node *start, int data, int beforeData);
struct Node *insertAfter(struct Node *start, int data, int afterData);
struct Node *deleteBeginning(struct Node *start);
struct Node *deleteEnd(struct Node *start);
struct Node *deleteBefore(struct Node *start, int beforeData);
struct Node *deleteAfter(struct Node *start, int afterData);
void search(struct Node *start, int key);
void display(struct Node *start);

struct Node *deleteSearch(struct Node *start,int searchdata){
    if(start == NULL){
        printf("List is empty");
    }
    struct Node *ptr = start;
    struct Node *preptr = start;
    while(ptr->data != searchdata){
preptr = ptr;
ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

int main(){
start = insertBegin(start , 45);
start = insertEnd(start,90);
start = insertBefore(start,54,90);
start = insertAfter(start,9,90);
display(start);
// start = deleteBeginning(start);
// start = deleteEnd(start);
// start = deleteBefore(start,90);
// start = deleteAfter(start,54);
start = deleteSearch(start,90);

display(start);
search(start,90);
    return 0;
}

struct Node *insertBegin(struct Node *start, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = start;
    printf("%d Added new data" , newNode->data);
    return newNode;
}

struct Node *insertEnd(struct Node *start,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(start == NULL){
        return newNode;
    }

    struct Node *currentNode = start;
    while(currentNode->next != NULL){
currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    printf("\n%d Added new data\n", newNode->data);
    return start;
}

void display(struct Node *start){

    struct Node *currentNode = start;
    if (currentNode == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while(currentNode != NULL){
        printf("\t%d", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\tNull");
}

void search(struct Node *start, int key){
    struct Node *current = start;
    if(current == NULL){
        printf("List is empty");
        return;
    }else{
        while (current != NULL)
        {
            if (current->data == key)
            {
                printf("\nElement found");
                return;
            }
            current = current->next;
        }
        
    }
}

struct Node *insertBefore(struct Node *start, int data, int beforeData){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if(start == NULL){
        printf("List is empty");
    }
    if(start->data == beforeData){
        newNode->next = start;
        return newNode;
    }

    struct Node *ptr = start;
while(ptr->next != NULL && ptr->next->data != beforeData){
    ptr= ptr->next;
}

if(ptr->next  ==    NULL){
    printf("Value not found in the list.\n");
}else{
newNode->next = ptr->next;
ptr->next = newNode;
}
printf("%d Added new data", data);
return start;
}

struct Node *insertAfter(struct Node *start, int data, int afterData){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if(start == NULL){
        printf("List is empty,cannnot enter after a node");
    }

    struct Node *prePtr = start;
    while(prePtr != NULL && prePtr->data != afterData){
        prePtr = prePtr->next;
    }
    if (prePtr == NULL)
    {
        printf("Value not found in the list");
    }
    else
    {
        newNode->next = prePtr->next;
        prePtr->next = newNode;
    }
    printf("%d Added new data", data);
    return start;
}

struct Node *deleteBeginning(struct Node *start){
if(start == NULL){
    printf("No list exists");
    return start;
}
struct Node *temp = start;
int x = temp->data;
    start = start->next;
free(temp);
printf("\n%d deleted from the list",x );
return start;
}


struct Node *deleteEnd(struct Node *start){
    if(start == NULL){
        printf("Element cannot be deleted since no element");
    }
    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }

    struct Node *current = start;
    while(current->next->next != NULL){
        current = current->next;
    }
    int x = current->next->data;
    free(current->next);
    current->next = NULL;
    printf("\n%d deleted from the list", x);
    return start;
}

struct Node *deleteBefore(struct Node *start, int beforeData)
{
    if (start == NULL || start->next == NULL)
    {
        printf("Error");
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

    int x = current->next->data;

    if (current->next->next == NULL)
    {
        printf("The element does not exist");
    }
    else
    {
        struct Node *temp = current->next;
        current->next = temp->next; // Corrected the assignment here
        free(temp);
    }

    printf("\n%d deleted from the list", x);
    return start;
}

struct Node *deleteAfter(struct Node *start, int afterData){
    struct Node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    while (preptr->data != afterData)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}