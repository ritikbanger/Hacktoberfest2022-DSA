class Solution {
public:
    bool ispalin(string ans)
    {
        int l=0;
        int h=ans.length()-1;
        while(l<=h)
        {
            if(ans[l++]!=ans[h--])
                return false;
        }
        return true;
    }
    string breakPalindrome(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            string k=s;
            if(k[i]=='a')
                k[i]='b';
            else
                k[i]='a';
            if(ispalin(k)==false)
            {
                if(ans=="")
                    ans=k;
                else
                    ans=min(ans,k);
            }
        }
        return ans;
        
    }
};
