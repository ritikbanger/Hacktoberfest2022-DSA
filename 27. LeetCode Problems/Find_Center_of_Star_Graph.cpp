/*

Leetcode - Find Center of Star Graph

There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 
edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center 
of the given star graph.



Solution:
Intuition
Give the conditions, we only need to compare edges[0] and edges[1]


Complexity
Time O(1)
Space O(1)


Check if e[0][0] == e[1][0] or e[0][0] == e[1][1]





*/



int findCenter(vector<vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];

}






