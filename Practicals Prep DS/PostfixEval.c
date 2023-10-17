#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float data);
float pop(float st[]);
float EvalPostfix(char exp[]);

int main()
{
    float val;
    char exp[100];

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strlen(exp) - 1] = '\0';

    val = EvalPostfix(exp);
    printf("The value of expression is: %.2f\n", val);

    return 0;
}

float EvalPostfix(char exp[])
{
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (float)((int)op1 % (int)op2);
                break;
            default:
                break;
            }
            push(st, value);
        }
        i++;
    }

    return pop(st);
}

void push(float st[], float data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        st[top] = data;
    }
}

float pop(float st[])
{
    if (top == -1)
    {
        printf("Underflow\n");
        return 0.0; // Return a default value for underflow
    }
    else
    {
        float x = st[top];
        top--;
        return x;
    }
}
