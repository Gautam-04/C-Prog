#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *insertBeg(struct Node *,int data);
struct Node *insertEnd(struct Node *, int data);
struct Node *deletebeg(struct Node *);
struct Node *deleteEnd(struct Node *);
struct Node *deleteAfter(struct Node *);
void display(struct Node *);

int main(){
display(start);
    return 0;
}

struct Node *insertBeg(struct Node *start, int data)
{

}

void display(struct Node *start){
    struct Node *ptr = start;
    if(start == NULL){
        printf("The link is empty");
    }
do{
    printf("\t %d ",ptr->data);
    ptr=ptr->next;
}while(ptr != start);

printf("\n");
}

struct Node *insertEnd(struct Node *start, int data){}
struct Node *deletebeg(struct Node *start) {}
struct Node *deleteEnd(struct Node *start) {}
struct Node *deleteAfter(struct Node *start) {}