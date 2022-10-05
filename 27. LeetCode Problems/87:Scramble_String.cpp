class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2){
        string key = s1 + '_' + s2;

        if(s1.length() != s2.length())
            return false;

        if(s1.length() == 0)
            return true;

        if(s1 == s2)
            return true;

        if(dp.count(key))
            return dp[key];

        int n = s1.length();
        bool flag = false;
        for(int i = 1; i < s1.length(); i++){
            bool left = isScramble(s1.substr(0, i), s2.substr(n-i, i)) &&
                        isScramble(s1.substr(i, n-i), s2.substr(0, n-i));

            bool right = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                         isScramble(s1.substr(i, n-i), s2.substr(i, n-i));

            if(left || right){
                flag = true;
                break;
            }

        }

        dp[key] = flag;
        return dp[key];
    }
};
