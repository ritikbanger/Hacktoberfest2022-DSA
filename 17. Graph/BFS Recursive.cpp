#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int source, destination;
};

class Graph
{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges)
        {
            adjList[edge.source].push_back(edge.destination);
            adjList[edge.destination].push_back(edge.source);
        }
    }
};
void recursiveBFS(Graph const &graph, queue<int> &a, vector<bool> &found)
{
    if (a.empty()) {
        return;
    }
    int x = a.front();
    a.pop();
    cout << x << " ";
    for (int y: graph.adjList[x])
    {
        if (!found[y])
        {
            found[y] = true;
            a.push(y);
        }
    }
 
    recursiveBFS(graph, a, found);
}
 
int main()
{
    vector<Edge> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6},{4, 7}, {4, 8},
    };

    int n = 10;
    Graph graph(edges, n);
    vector<bool> found(n, false);
    queue<int> a;
    for (int i = 0; i < n; i++)
    {
        if (found[i] == false)
        {
            found[i] = true;
            a.push(i);
            recursiveBFS(graph, a, found);
        }
    }
 
    return 0;
}