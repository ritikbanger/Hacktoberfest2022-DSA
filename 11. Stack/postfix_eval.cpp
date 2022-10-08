#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
int Stack[SIZE], top=-1;

int isFull()
{
  return (top==(SIZE-1));
}
int isEmpty()
{
  return (top==-1);
}
int push(int item)
{
  if (isFull())
  {
    return -1;
  }
  Stack[++top] = item;
}

int pop()
{
  int temp;
  if (isEmpty())
  {
    return -1;
  }
  temp=Stack[top--];
  return temp;
}
int evaluatePostfix(char* exp)
{
  int i, op1, op2, answer;
  for (i = 0; exp[i]; ++i)
  {
    // If the scanned character is an operand (number here), push it to the stack.
    if (isdigit(exp[i]))
      push(exp[i] - '0');

    // If the scanned character is an operator, pop two elements from stack apply the operator
    else
    {
      op2 = pop();
      op1 = pop();
      switch (exp[i])
      {
        case '+': push(op1 + op2); break;
        case '-': push(op1 - op2); break;
        case '*': push(op1 * op2); break;
        case '/': push(op1 / op2); break;
      }
    }
  }
  answer = pop();
  return answer;
}

int main()
{
  char expression[] = "632+7*+";
  printf("Value of %s postfix expression is %d", expression, evaluatePostfix(expression));
  return 0;
}
