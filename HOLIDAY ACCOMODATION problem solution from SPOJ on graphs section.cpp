#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph{

int V;
list<pair<ll,ll>> *adj;
public:
Graph(int V)
{
this->V=V;
adj=new list<pair<ll,ll>>[V+1];
}

void addEdge(ll u,ll v,ll wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}


int dfs_helper(ll node,bool *vis,ll *count, ll &cost)
{
  
    vis[node]=true;
    count[node]=1; 
   

    for(auto nbr_pair:adj[node])
    {
        ll nbr=nbr_pair.first;
        ll wt=nbr_pair.second;

        if(vis[nbr]==false)
        { 
           
            count[node]+=dfs_helper(nbr,vis,count,cost);

           

          
            ll nodes_part1=count[nbr];
            ll nodes_part2=V-nodes_part1;

            ll contribute=2*min(nodes_part1,nodes_part2)*wt;

            cost+=contribute;
          
        }
    }


    return count[node];
}



ll dfs()
{
    bool *vis=new bool[V+1];
    ll *count=new ll[V+1]; 
    
    for(ll i=1;i<=V;i++)
    {
        vis[i]=false; 
        count[i]=0;
    }



    ll src=1; 
               
    ll cost=0;
    dfs_helper(src,vis,count,cost);
    
    return cost;
   
}
};

int main()
{
int t=1,T; cin>>T;

while(t<=T)
{
    int u,v,wt,V; cin>>V;

   
   
    Graph g(V);
    pair<int,int>p;

    for(int i=0;i<V-1;i++)
    {
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt);
      
    }


int cost=g.dfs();
  
    cout<<"Case #"<<t<<": "<<cost<<"\n";
    t++;
}
}
