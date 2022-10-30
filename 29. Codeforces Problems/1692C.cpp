#include<iostream>
using namespace std;
int index(string ch)
{
    for(int x=0;x<=7;x++)
    {
        if(ch[x]=='#')
        {
            return x;
        }
    }
    return -1;
}
int count(string ch)
{
    int c=0;
    for(int x=0;x<=7;x++)
    {
        if(ch[x]=='#')
        {
            c++;
        }
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //char character;
        //cin>>character;
        int ar[8];
        int column[8];
        for(int x=0;x<=7;x++)
        {
            string str;
            cin >> str;
            ar[x]=count(str);
            if(ar[x]==1)
            {
                column[x]=index(str);
            }
            /*else{
                column[x]=0;
            }*/
        }

        for(int x=1;x<=6;x++)
        {
            if(ar[x-1]==2 && ar[x+1]==2 && ar[x]==1)
            {
                cout<<(x+1)<<" "<<(column[x]+1)<<endl;
                break;
            }
        }
        //cin>>character;
    }
}