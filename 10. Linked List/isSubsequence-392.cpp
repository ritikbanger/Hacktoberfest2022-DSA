//-- Approach 1 -- By Two Pointer Approach --- https://leetcode.com/problems/is-subsequence/submissions/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr=0;
        int tptr=0;
        
        while(sptr<s.length() && tptr<t.length())
        {
            int flag=0;
            for(int i=tptr;i<t.length();i++)
            {
                if(s[sptr]==t[i])
                {
                    sptr++;
                    tptr=i+1;
                    flag=1;
                   // cout<<sptr<<" "<<tptr<<endl;
                    break;
                }
            }
            
            if(flag) continue;
            else
            {
               // cout<<"h"<<endl;
                return false;
            }
        }
       // cout<<sptr<<" "<<tptr<<endl;
        if(sptr >= s.length()) return true;
         
        return false;
    }
};

//--- Hashing --- Approach 2

