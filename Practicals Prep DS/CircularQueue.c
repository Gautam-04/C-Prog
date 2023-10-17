#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int queue[], int data);
int delete(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int main(){
insert(queue,78);
insert(queue,87);
insert(queue,90);

display(queue);
delete(queue);
peek(queue);
display(queue);
return 0;
}

void insert(int queue[], int data){
if(front == 0 && rear == MAX-1){
    printf("overflow");
}else if(front == -1 && rear == -1){
front = rear=0;
queue[rear] = data;
}else if(rear == MAX-1&& front == 0){
rear = 0;
queue[rear] = data;
}else{
rear++;
queue[rear] = data;
}
}


int delete(int queue[]){
int val = -1;
if(front == -1 && rear == -1){
    printf("underflow");
}
val = queue[front];
if(front == rear){
    front = rear = -1;
}else{
    if(front == MAX -1){
    front = 0;
    }else{
        front++;
    }
    printf("\ndeleted val = %d\n" , val);
return val;
}
}

int peek(int queue[]){
    int val = 0;
    if(front == rear == -1){
        printf("Underflow");
    }else{
        val = queue[front];
    }
    printf("Front val = %d", val);
    return val;
}

void display(int queue[]){
    if(front ==  rear == -1){
        printf("Queue is empty");
    } else{
        for (int  i = front; i <= rear; i++)
        {
            printf("%d\t" , queue[i]);
        }
        printf("\n");
    }
}