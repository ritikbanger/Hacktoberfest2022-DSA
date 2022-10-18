// Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 
// A Gray code sequence must begin with 0.

// Input:
// N = 2
// Output: 
// 00 01 11 10


#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

    vector<int> codes(int n)
    {
        vector<int> v;
        int m=pow(2,n)-1;
        for(int i=0;i<=m;i++)
        {
            v.push_back(i^(i>>1));
        }
        return v;
    }
    vector<string> graycode(int n)
    {
        vector<string> ans;
        if(n==0)
        {
            string str="";
            ans.push_back(str);
            return ans;
        }
        vector<int> v=codes(n);
        for(int i=0;i<v.size();i++)
        {
            string str="";
            int c=0;
            while(v[i]!=0)
            {
                if(v[i]%2==0)
                str+='0';
                else
                str+='1';
                v[i]=v[i]/2;
                c++;
            }
            while(c!=n)
            {
                str+='0';
                c++;
            }
            reverse(str.begin(),str.end());
            ans.push_back(str);
        }
        return ans;
    }

    int main()
    {
        int n;
        vector<string> v=graycode(n);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        return 0;
    }