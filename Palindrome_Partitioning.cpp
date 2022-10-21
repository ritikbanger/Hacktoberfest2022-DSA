class Solution {
    vector<vector<string>> res;
public:
    bool isPalin(const string s){
        int lo=0, hi=s.size()-1;
        while(lo < hi){
            if(s[lo++] != s[hi--]) return false;
        }
        return true;
    }
    void helper(int inx, const string s, vector<string> &temp){
        if(inx == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=inx; i<s.size(); i++){
            string palin = s.substr(inx, i-inx+1);
            if(!isPalin(palin)) continue;
            temp.push_back(palin);
            helper(i+1, s, temp);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(0, s, temp);
        return res;
    }
};
