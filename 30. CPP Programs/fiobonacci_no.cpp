#include <iostream>
using namespace std;
int main()
{
int i=1, n, f, f1, f2;
cout<<"Enter Number of Fibonacci Values Needed";
cin>>n;
f=0;
f1=1;
f2=1;
do
{
    i++;
    cout<<f<<endl;
    f1=f2;
    f2=f;
    f=f1+f2;
}
while (i<=n);
return 0;
}
