// Implement Stack ADT using an array.
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int st[MAX], top = -1;
void push(int st[], int data);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    push(st, 9);
    push(st, 98);
    push(st, 65);
    pop(st);
    peek(st);
    display(st);
    return 0;
}

void display(int st[])
{
    printf("\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ~> \t", st[i]);
    }
}

void push(int st[], int data)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow");
    }
    else
    {
        top++;
        st[top] = data;
        printf("\n%d added to the stack", data);
    }
}

int pop(int st[])
{
    int x;
    if (top == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        x = st[top];
        top--;
        printf("\n%d is removed from the stack", x);
        return x;
    }
}

int peek(int st[])
{
    if (top == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        int x = st[top];
        printf("\n%d is Top most in the stack", x);
        return x;
    }
}