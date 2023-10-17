#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100

typedef struct
{
    char items[MAX_STACK];
    int top;
} Stack;

void initialize(Stack *s);
void push(Stack *s, char val);
char pop(Stack *s);
int getPriority(char op);
void infixToPostfix(const char source[], char target[]);

int main()
{
    char infix[100], postfix[100];

    printf("Enter any infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    infixToPostfix(infix, postfix);

    printf("The corresponding postfix expression is: %s\n", postfix);

    return 0;
}

void initialize(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, char val)
{
    if (s->top == MAX_STACK - 1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = val;
    }
}

char pop(Stack *s)
{
    char val = ' ';
    if (s->top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        val = s->items[s->top];
        s->top--;
    }
    return val;
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    return -1; // Default case
}

void infixToPostfix(const char source[], char target[])
{
    Stack st;
    initialize(&st);
    int i = 0, j = 0;

    while (source[i] != '\0')
    {
        char ch = source[i];

        if (isalnum(ch))
        {
            target[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(&st, ch);
        }
        else if (ch == ')')
        {
            while (st.top != -1 && st.items[st.top] != '(')
            {
                target[j] = pop(&st);
                j++;
            }
            if (st.top == -1)
            {
                printf("INCORRECT EXPRESSION\n");
                return;
            }
            pop(&st); // Remove the '(' from the stack
        }
        else
        { // Operators
            while (st.top != -1 && st.items[st.top] != '(' &&
                   getPriority(st.items[st.top]) >= getPriority(ch))
            {
                target[j] = pop(&st);
                j++;
            }
            push(&st, ch);
        }

        i++;
    }

    while (st.top != -1 && st.items[st.top] != '(')
    {
        target[j] = pop(&st);
        j++;
    }

    target[j] = '\0';
}