#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    int i;
    bool is_prime = true;

    
    if (n == 0 || n == 1)
    {
        is_prime = false;
    }

    for (i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    vector<int>v;
    for(int j=2;j<=n;j++)
    {
        if(isprime(j) && isprime(n-j))
        {
            v.push_back(j);
            v.push_back(n-j);
            break;
        }
    }
    cout<<"Number can be expressed as sum of :"<<endl;
   for(int j=0;j<v.size();j++)
   {
    cout<<v[j]<<" ";
   }
}