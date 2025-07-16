#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int src=0;
        int target=n;
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto g:graph[i]){
                adj[i].push_back(g);
            }
        }
        queue<vector<int>>q;//stores diff paths
        vector<int> path;
        q.push({0});
        while(!q.empty()){
            path=q.front();
            q.pop();
            if(path.back()==n-1){
                ans.push_back(path);
            }
            for(auto neigh:adj[path.back()]){
                vector<int> temp=path;
                temp.push_back(neigh);
                q.push(temp);
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     void dfs(vector<vector<int>>& graph,int u,int target,vector<vector<int>>&res,vector<int>&temp){
//         temp.push_back(u);
//         if(u==target){
//             res.push_back(temp);
//         }else{
//             for(int &v:graph[u]){
//                 dfs(graph,v,target,res,temp);
//             }
//         }
//         temp.pop_back();
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         int n=graph.size();
//         int src=0;
//         int target=n-1;
//         vector<vector<int>> res;
//         vector<int> temp;
//         dfs(graph,src,target,res,temp);
//         return res;
//     }
// };