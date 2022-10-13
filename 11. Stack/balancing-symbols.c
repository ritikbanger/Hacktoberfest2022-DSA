// balancing symbols using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_STACK_SIZE 100

struct stack {
    char data[MAX_STACK_SIZE];
    int top;
};

struct stack *create_stack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

void push(struct stack *s, char c)
{
    if (s->top == MAX_STACK_SIZE - 1)
        return;
    s->top++;
    s->data[s->top] = c;
}

int pop(struct stack *s)
{
    if (s->top == -1)
        return -1;
    s->top--;
    return s->top + 1;
}

int is_empty(struct stack *s)
{
    if (s->top == -1)
        return 1;
}

int balanced_symbols(char *s)
{
    struct stack *s1 = create_stack();
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(s1, s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (is_empty(s1))
                return 0;//NULL;
            char c = s1->data[pop(s1)];
            if (s[i] == ')' && c != '(')
                return 0;//NULL;
            if (s[i] == ']' && c != '[')
                return 0;//NULL;
            if (s[i] == '}' && c != '{')
                return 0;//NULL;
        }
        i++;
    }
    if (is_empty(s1)){
        return 1;//s2;
    }
    return 0;//NULL;
}

int main()
{
    char s[MAX_LEN] = "([{}])";
    int s1 = balanced_symbols(s);
    if (s1 == 0)// && *s1->data[s1->top] != 'b')
        printf("Not Balanced\n");
    else if(s1 == 1)
        printf("Balanced\n");
    return 0;
}