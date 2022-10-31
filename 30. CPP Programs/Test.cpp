#include<iostream>
using namespace std;
class Test
{
    private: 
                int n1,n2,n3;
    public: 
                void setvalue(int a,int b,int c)
                {
                    n1=a;
                    n2=b;
                    n3=c;
                }    
    friend void biggest(Test);
};
void biggest(Test ob)
{
    int n=ob.n1;
    if(ob.n1>=ob.n2)
    {
        if(ob.n1>=ob.n3)
        cout<<"The biggest number is: "<<ob.n1;
        else
        cout<<"The biggest number is: "<<ob.n3;
    }
    else
    {
        if(ob.n2>=ob.n3)
        cout<<"The biggest number is: "<<ob.n2;
        else
        cout<<"The biggest number is: "<<ob.n3;
    }
}

int main()
{
    Test ob;
    ob.setvalue(1,7,5);
    biggest(ob);
    return 0;
}

