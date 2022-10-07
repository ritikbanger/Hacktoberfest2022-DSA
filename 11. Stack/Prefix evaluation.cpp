#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
using namespace std;
stack<int> st;

void push(int data){
    cout<<data<<" pushed to stack\n";
    st.push(data);
}

int pop(){
    int data = st.top();
    cout<<data<<" popped from stack\n";
    st.pop();
    return data;
}
int evalPrefix(char* exp){
    int i,op1,op2;
  	int len = strlen(exp);
	for ( i = len-1; i>=0 ; i--)
    {
      char c = exp[i];
      if (isdigit(c))
        push(c-'0');

      else
      {
        op1 = pop();
        op2 = pop();
        switch(c)
        {
          case '+': push(op1 + op2); break;
          case '-': push(op1 - op2); break;
          case '*': push(op1 * op2); break;
          case '/': push(op1 / op2); break;
          case '^':push(pow(op1,op2)); break;
        }
      }
    }
 	return pop();
}

int main(){
    char *expr = "+6*+237";
    cout<<"The value of prefix expression "<<expr<<" is "<<evalPrefix(expr)<<'\n';
   return 0;
}
