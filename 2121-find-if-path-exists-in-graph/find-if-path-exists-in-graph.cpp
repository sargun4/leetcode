#include <bits/stdc++.h>
using namespace std;
  
//dfs
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool>vis;
    void dfs(int node){
        if(vis[node]) 
            return;
        vis[node]=true;
        for(auto child : graph[node]){
            if(!vis[child])
                dfs(child);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        // Create a graph from the input given and
        vis=vector<bool>(n, false);
        graph= vector<vector<int>>(n);
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(src);
        return vis[dest];
    }
};