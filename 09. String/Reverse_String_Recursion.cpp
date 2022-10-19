#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void reverse(vector<char>& s, int start, int end){
        if(start>end)
            return;
        swap(s[start],s[end]);
        start++;
        end--;
        reverse(s,start,end);
    }
    
    void reverseString(vector<char>& s) {
        int n=s.size();
        reverse(s,0,n-1);
        return;
    }
    
    void print(vector<char>& s){
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }    
};

int main (){
     vector<char> str = {'a','b','c','d','e'};
     Solution obj;
     obj.reverseString(str);
     obj.print(str);
     return 0;
}
