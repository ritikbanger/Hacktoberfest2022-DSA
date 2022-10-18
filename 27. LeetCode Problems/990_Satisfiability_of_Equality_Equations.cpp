https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    int findParent(int g,vector<int> &p){
        if(p[g] == g){
            return g;
        }
        return p[g] = findParent(p[g],p);
    }
    void unionn(int a,int b,vector<int> &p,vector<int> &rank){
        if(p[a] == p[b])    return;
        
        int pa = findParent(a,p);
        int pb = findParent(b,p);
        
        if(pa == pb)    return;
        if(rank[pa] == rank[pb]){
            p[pb] = pa;
            rank[pa]++;
        }
        else if(rank[pa] < rank[pb]){
            p[pa] = pb;
        }
        else{
            p[pb] = pa;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> p(26), rank(26,0);
        for(int i=0; i<26; i++) p[i]=i;
        
        for(auto x: equations){
            if(x[1] == '='){
                unionn(x[0]-'a', x[3]-'a', p, rank);
            }
        }
        for(auto x: equations){
            if(x[1] == '!'){
                int a = findParent(x[0]-'a',p);
                int b = findParent(x[3]-'a',p);
                if(a == b)    return false;
            }
        }
        return true;
    }
};
