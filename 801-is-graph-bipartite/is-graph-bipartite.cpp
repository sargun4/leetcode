#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int u,vector<int> &color,int currcolor){
        color[u]=currcolor;
        for(int &v:adj[u]){
            if(color[v]==color[u]){//adj node is same color as node u-NOT bipartite
                return false;
            }else if(color[v]==-1){//not yet vis, mark it w alt color
                color[v]=1-color[u];
                if(dfs(adj,v,color,!currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n, -1); //ALL Uncolored initially
        //red=1; green=0; 
        for(int i=0;i<n;i++){
            if(color[i]==-1){//if not yet vis
                if(dfs(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
// //BFS
// #include <bits/stdc++.h> 
// using namespace std; 
// class Solution {
// public:
//     bool bfs(vector<vector<int>>& adj,int curr,vector<int> &color,int currcolor){
//         queue<int> q;
//         q.push(curr);
//         color[curr]=currcolor;
//         while(!q.empty()){
//             int u=q.front();
//             q.pop();
//             for(int &v:adj[u]){
//             //adj node is same color as node u-NOT bipartite
//                 if(color[v]==color[u])
//                     return false;
//                 else if(color[v]==-1){//not vis yet,mark it w alt color
//                     color[v]=1-color[u];
//                     q.push(v);
//                 }
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& adj) {
//         int n=adj.size();
//         vector<int> color(n, -1); //ALL Uncolored initially
//         //red=1; green=0; 
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){//if not yet vis
//                 if(bfs(adj,i,color,1)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };