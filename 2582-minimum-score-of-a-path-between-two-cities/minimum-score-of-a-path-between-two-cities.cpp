#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it:roads){//undirected graph
            graph[it[0]].push_back({it[1],it[2]}); 
            graph[it[1]].push_back({it[0],it[2]});
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1); vis[1]=1; //1 is src
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:graph[node]){
                int v=it.first;
                int dist=it.second;
                ans=min(ans,dist);
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,int&res){
//         vis[u]=true;
//         //neighbour
//         for(auto&p:adj[u]){
//             int v=p.first;
//             int d=p.second;
//             res=min(res,d);
//             if(!vis[v]){
//                 dfs(v,adj,vis,res);
//             }
//         }
//     }
//     int minScore(int n, vector<vector<int>>& roads) {
//         unordered_map<int,vector<pair<int,int>>> adj;
//         for(auto &vec:roads){
//             int u=vec[0];
//             int v=vec[1];
//             int d=vec[2];
//             adj[u].push_back({v,d});
//             adj[v].push_back({u,d});
//         }
//         vector<bool> vis(n,false);
//         int res=INT_MAX;
//         dfs(1,adj,vis,res);
//         return res;
//     }
// };