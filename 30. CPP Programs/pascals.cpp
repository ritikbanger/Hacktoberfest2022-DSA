#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n=5;
    vector<int> p(n);
    int c=1,s=n-1,r=1;
    for(int i=0;i<n;i++)
    {
        if(i!=0 && i!=n-1)
        {
            r=(r*s)/c;
            p[i]=r;
            s--;
            c++;
        }
        else
        {
            p[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }

}