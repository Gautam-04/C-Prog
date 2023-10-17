#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int queue[], int data);
int delete(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int main()
{
    insert(queue, 45);
    insert(queue, 95);
    insert(queue, 75);
    int y = peek(queue);
    printf("\n%d is returned element", y);
    delete(queue);
    
    display(queue);
    return 0;
}
int delete(int queue[])
{
    if (front == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        int deletedItem = queue[front];

        if (front == rear)
        {
            // If there's only one element in the queue, reset front and rear.
            front = rear = -1;
        }
        else
        {
            // Move front to the next element in the queue.
            front = (front + 1) % MAX;
        }

        printf("\n%d has been deleted from the queue", deletedItem);
        return deletedItem;
    }
}

void display(int queue[])
{
    printf("\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ~> \t", queue[i]);
    }
}

int peek(int queue[])
{
    if (front == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void insert(int queue[], int data)
{
    if (rear == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        if (front == -1)
        {
            front = 0; // Initialize the front pointer if it's the first element.
        }
        rear = (rear + 1) % MAX; // Circularly update the rear pointer.
        queue[rear] = data;
        printf("\n%d the data have been added", data);
    }
}
