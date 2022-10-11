// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 

// such that for every directed edge uv, vertex u comes before v in the ordering.

//  Topological Sorting for a graph is not possible if the graph is not a DAG.

#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V]={0};
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return topo;
	}
};

int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	Solution obj;
    	vector<int> v=obj.topoSort(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}