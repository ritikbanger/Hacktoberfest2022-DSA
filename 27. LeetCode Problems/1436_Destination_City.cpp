class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        for(auto &i: paths)
            s.insert(i[1]);
        for(auto &i: paths) {
            if(s.find(i[0]) != s.end())
                s.erase(i[0]);
        }
        return *s.begin();
    }
};