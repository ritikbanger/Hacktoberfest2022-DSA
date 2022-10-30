/* Name - Satyam Gupta
    Roll no -32
    CST
    STACK*/
#include<iostream>
#define MAX 10
using namespace std;
class stack
{
private:
    int arr[MAX], top, *d = NULL, d_size;

public:
    stack()
    {
        top = -1;
    }
    void push()
    {
        if (top == MAX - 1)
        {
            cout << "Stack is full." << endl;
        }
        else
        {
            top++;
            cout << "Enter element in stack : ";
            cin >> arr[top];
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << arr[top] << " is deleted." << endl;
            top--;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top element of stack is " << arr[top] << "." << endl;
        }
    }
    void display()
    {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else
        {
            for (int i = top; i > -1; i--)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }

    void dyn_size()
    {
        cout << "Enter the size of stack : ";
        cin >> d_size;

        d = new int[d_size];
    }
    void dyn_push()
    {
        if (top == d_size - 1)
        {
            cout << "Stack is full." << endl;
        }
        else
        {
            top++;
            cout << "Enter element in stack : ";
            cin >> *(d + top);
        }
    }
    void dyn_pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << *(d + top) << " is deleted." << endl;
            top--;
        }
    }
    void dyn_peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << *(d + top) << "is top element in stack" << endl;
        }
    }
    void dyn_display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            for (int i = top; i > -1; i--)
            {
                cout << *(d + i) << "\t";
            }
            cout << endl;
        }
    }
};
int main()
{
    stack s1;
    int ch, x;
    cout << "1.Static Stack\n2.Dynamic Stack\n3.Exit" << endl;
    cout << "Enter choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        while (1)
        {
            cout << "1.Push an element\n2.Pop an element\n3.Peek\n4.Display\n5.Exit" << endl;
            cout << "Enter valid choice : ";
            cin >> x;
            switch (x)
            {
            case 1:
                s1.push();
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.peek();
                break;
            case 4:
                s1.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Enetred choice is wrong" << endl;
                break;
            }
        }
        break;
    case 2:
        s1.dyn_size();
        while (1)
        {
            cout << "1.Push an element\n2.Pop an element\n3.Peek\n4.Display\n5.Exit" << endl;
            cout << "Enter valid choice : ";
            cin >> x;
            switch (x)
            {
            case 1:
                s1.dyn_push();
                break;
            case 2:
                s1.dyn_pop();
                break;
            case 3:
                s1.dyn_peek();
                break;
            case 4:
                s1.dyn_display();
                break;
            case 5:
                return 0;
            default:
                cout << "Enetred choice is wrong" << endl;
                break;
            }
        }
        break;
    case 3:
        return 0;

    default:
        cout << "Entered wrong choice" << endl;
        break;
    }
}