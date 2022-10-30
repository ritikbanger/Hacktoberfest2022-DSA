#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int bigger=max(x,y);
        int ans=(x+y)/2;
        for(int i=1;i<=bigger;i++)
        {
            int find=max(abs(x-i),abs(y-i));
            if(find<ans)
                ans=find;
        }
        cout<<ans<<endl;
    }
}