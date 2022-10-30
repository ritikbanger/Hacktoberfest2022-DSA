#include<iostream>
#include<stdio.h>
using namespace std;
class Bank
{
    private:   string name;
               string address;
                int accno,bal,arr[1000],c=0;
    public:    int input(int n)
                {
                     c+=arr[n];
                    cout<<"Enter Name"<<endl;
                    getline(cin,name);
                    cout<<"Enter Address"<<endl;
                    getline(cin,address);
                    if(accno<=1000)
                    {
                        cout<<"Enter Account number(Starting=1001)"<<endl;
                        cin>>accno;
                    }
                    else
                    {
                        accno++;
                        cout<<accno;
                    }
                    cout<<"Enter Balance amount"<<endl;
                    cin>>bal;
                    return accno;
                } 
                void print(int n)
                {  
                    if(n==accno)
                    {
                    cout<<"Name = "<<name;
                    cout<<"Address = "<<address;
                    cout<<"Account number = "<<n;
                    cout<<"Balance amount = "<<bal;
                    }
                }

};

int main()
{
    Bank ob;
    int n,accno,faccno;
    cout<<"Enter no of users"<<endl;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
    accno=ob.input(n);
    }
    cout<<"Enter the account number to find"<<endl;
    cin>>faccno;
    ob.print(faccno);
    return 0;
}