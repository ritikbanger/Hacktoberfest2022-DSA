/*

Leetcode - Maximal Network Rank

There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a 
bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected 
to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.



Solution:

Build the graph (adjacency list).
Compute network rank of all pairs of cities.
Simply compute the sum of neighbors (connected cities) of both cities.
Decrement 1 from the computed sum if the cities under consideration are connected to each other.
(Otherwise the road between those 2 cities will be double counted)
Update the maximal network rank if the network rank computed is greater than the current value.


Note:
Note:
Used unordered_set in the graph to track neighbors (connected cities) in order to speed up the look up.
(Required to check if the 2 cities under consideration are connected or not)




*/




// since graph is undirectional, we need to find no. of cities adjacent to every city
// for every pair of cities a,b ans = cities adj to a + cities adj to b
// ans-- if there is a connection bw a and b cuz that connection got counted twice
// iterate over every pair of cities and find their rank. Update max rank if it exceeds

int maximalNetworkRank(int n, vector<vector<int>>& roads){
    // 2D vector stores if city a is adjacent to city b
    vector<vector<int>> isAdjacent(n, vector<int>(n,0));
    
    // 1D vector to store no. of cities adj to ith city
    vector<int> numAdjacent(n, 0);
    
    // iterate over all roads and fill isAdjacent and numAdjacent
    for(int i=0; i<roads.size(); i++){
        int citya = roads[i][0];
        int cityb = roads[i][1];
        
        numAdjacent[citya]++;
        numAdjacent[cityb]++;
        
        isAdjacent[citya][cityb] = 1;
        isAdjacent[cityb][citya] = 1;
        
    }
    
    // iterate over every pair of city and find the pair with max rank
    int max_rank = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int rank = numAdjacent[i] + numAdjacent[j];
            if(isAdjacent[i][j] == 1){
                rank--;
            }
            
            max_rank = max(max_rank, rank);
            
        }
    }
    
    return max_rank;
    
}





