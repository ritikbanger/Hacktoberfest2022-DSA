#include<iostream>
#include<conio.h>
using namespace std;

int stack[100], n=100, top=-1;

//declare functions here below:

void push();
void pop();
void display();
void isEmpty();
void isFull();


int main()
{
    long int a,b;
    again:
    cout<<"\n Enter the number of that operation that you want to perform:\n";
    cout<<"1:\tCheck Stack is Empty or not\n";
    cout<<"2:\tInsertion into stack (push)\n";
    cout<<"3:\tDeletion into stack (pop)\n";
    cout<<"4:\tDisplay the elements of stack (traversing)\n";
    cout<<"5:\tCheck the stack is full\n";
    cout<<"6:\tExit\n";
    cin>>a;

    switch(a)
    {
        case 0: goto endst;
        case 1: isEmpty(); break;
        case 2: push(); break;
        case 3: pop(); break;
        case 4: display(); break;
        case 5: isFull(); break;
        case 6: goto endst; break;
        

        default: cout<<"\n Enter a valid number:";
    }
    end:
    cout<<"\n Do you want to Continue then press 1 for Yes and 0 for No:";
    cin>>b;
    if(b==1){
        goto again;
    }else if(b==0){
        endst:
        exit(7);
    }else{
        cout<<"\n PLease Enter Valid number";
        goto end;
    }    
getch();
}

void isFull()
{
   if(top>=n-1)
   {
   cout<<"Stack is Full"<<endl;
   }
   else
   {
      cout<<"Stack is not Full";
   }
}

void isEmpty()
{
      if(top<=-1)
   cout<<"Stack is Empty"<<endl;
}

void push() {
   int val;
   cout<<"Enter value to be Insert:"<<endl;
   cin>>val;
   if(top>=n-1)
   {
   cout<<"Stack Overflow"<<endl;
   }
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
