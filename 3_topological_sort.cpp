#include<bits/stdc++.h>
using namespace std;

void createAdj(vector<vector<int>> e, vector<vector<int>> & adj) {
    for(vector<int> v : e) {
        adj[v[0]].push_back(v[1]);
    }
}

vector<int> topoSort(vector<vector<int>> e, int V) {
    vector<vector<int>> adj(V);
    createAdj(e, adj);

    vector<int> inDegree(V);
    for (int i = 0; i < V; i++)
    {
        for(int al: adj[i]) {
            inDegree[al]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if(inDegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for (int it : adj[node])
        {
            inDegree[it]--;

            if(inDegree[it] == 0) q.push(it);
        }
        
    }

    if(ans.size() != V) {cout<<"CYCLE EXISTS"<<endl; return {};};
    
    return ans;
}

int main(){
    vector<vector<int>> e = {{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}};

    // topoSort(e, 6);

    for(int it : topoSort(e, 6)) {
        cout<<it<<" ";
    }
    return 0;
}