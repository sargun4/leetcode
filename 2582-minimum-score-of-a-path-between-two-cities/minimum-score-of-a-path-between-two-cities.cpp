#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,int&res){
        vis[u]=true;
        //neighbour
        for(auto&p:adj[u]){
            int v=p.first;
            int d=p.second;
            res=min(res,d);
            if(!vis[v]){
                dfs(v,adj,vis,res);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec:roads){
            int u=vec[0];
            int v=vec[1];
            int d=vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool> vis(n,false);
        int res=INT_MAX;
        dfs(1,adj,vis,res);
        return res;
    }
};