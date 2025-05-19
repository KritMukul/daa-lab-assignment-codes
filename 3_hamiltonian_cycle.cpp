#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &graph, vector<int> &path, int pos, int v) {
    if(graph[path[pos - 1]][v] == 0) return false;

    if(find(path.begin(), path.end(), v) != path.end()) return false;

    return true;
}

bool hamCycle(vector<vector<bool>> &Graph, vector<int> &path, int pos, int v) {
    if(pos == v) {
        if(Graph[path[pos - 1]][path[0]] == 1) return true;
        else return false;
    }

    for (int i = 1; i < v; i++)
    {
        if(isSafe(Graph, path, pos, i)) {
            path[pos] = i;
            
            if(hamCycle(Graph, path, pos + 1, v) == true)
                return true;

            path[pos] = -1;
        } 
    }

    return false;
    
}

int main(){
    int v = 5;
    vector<int> path(v, -1);
    vector<vector<bool>> graph = {{0, 1, 0, 1, 0}, 
                        {1, 0, 1, 1, 1}, 
                        {0, 1, 0, 0, 1}, 
                        {1, 1, 0, 0, 1}, 
                        {0, 1, 1, 1, 0}}; 

    path[0] = 0;
    
    if (hamCycle(graph, path, 1, v))
        for(auto it : path) cout<<it<<" ";
    else
        cout<<"No hamiltonian cycle";
    
    return 0;
}