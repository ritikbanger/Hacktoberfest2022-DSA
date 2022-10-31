// There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

// You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

// Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<int> &q,int x,vector<int> &res) {
        if(res[x]==-1) {
            res[x] = x;
            
            for(auto u:adj[x]) {
                int c = dfs(adj,q,u,res);
                
                if(q[c]<q[res[x]])
                    res[x] = c;
            }
            
            
        }
        return res[x];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& v, vector<int>& q) {
        int n = q.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<v.size();i++) {
            adj[v[i][1]].push_back(v[i][0]);
        }
        
        vector<int> res(n,-1);
        
        for(int i=0;i<n;i++) {
            dfs(adj,q,i,res);
        }
        
        return res;
    }
};