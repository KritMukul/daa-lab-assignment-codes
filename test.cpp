#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent) {
    int V = rGraph.size();
    vector<bool> vis(V, false);
    
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if(vis[v] == false && rGraph[u][v] > 0) {
                if(v == t){
                    parent[v] = u;
                    return true;
                }

                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
        
    }
    return false;
    
    
}

int fordFulkerson(vector<vector<int>> graph, int s, int t) {
    int V = graph.size(), i, j;

    vector<vector<int>> rGraph(V, vector<int> (V));

    for(i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            rGraph[i][j] = graph[i][j];
        }
    }

    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int pathFlow = INT_MAX;

        for ( i = t; i != s; i = parent[i])
        {
            j = parent[i];
            pathFlow = min(pathFlow, rGraph[j][i]);
        }

        for ( i = t; i != s; i = parent[i])
        {
            j = parent[i];
            rGraph[j][i] -= pathFlow;
            rGraph[i][j] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
    
}

int main(){
    vector<vector<int>> graph = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };

    cout<<"The maximum possible flow is : " << fordFulkerson(graph, 0, 5);
    return 0;
}