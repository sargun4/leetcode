
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int u,unordered_map<int,vector<int>> &adj,vector<bool>&vis,long long &size){
        queue<int> q;
        q.push(u);
        vis[u]=true;
        size++;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int &v:adj[node]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    size++;
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<bool> vis(n,false);
        long long ans=0;
        long long remnodes=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long size=0;
                bfs(i,adj,vis,size);
                ans+=(size)*(remnodes-size);
                remnodes-=size;
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool>&vis,long long &size){
//         vis[u]=1;
//         size++;
//         for(auto &v:adj[u]){
//             if(vis[v]==0){
//                 dfs(v,adj,vis,size);
//             }
//         }
//     }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         unordered_map<int,vector<int>> adj;
//         for(int i=0;i<n;i++){
//             adj[vec[0]].push_back(vec[1]);
//             adj[vec[1]].push_back(vec[0]);
//         }
//         vector<bool> vis(n,false);
//         long long ans=0;
//         long long remnodes=n;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 long long size=0;
//                 dfs(i,adj,vis,size);
//                 ans+=(size)*(remnodes-size);
//                 remnodes-=size;
//             }
//         }
//         return ans;
//     }
// };