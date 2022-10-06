#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});


        }
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stops>k){
                continue;
            }
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edW=iter.second;
                if(cost+edW<dis[adjNode] && stops<=k){
                    dis[adjNode]=cost+edW;
                    q.push({stops+1,{adjNode,cost+edW}});

                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
            
};

int main(){
    Solution obj1;

    vector<vector<int>>flights = [[0,1,100],[1,2,100],[0,2,500]];
   int  n = 3, src = 0, dst = 2, k = 1;

   cout<<"The Minimum Cost To reach Destination With K Stops"<<obj1.findCheapestPrice(n,flights,src,dst,k);
}