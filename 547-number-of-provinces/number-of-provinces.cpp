#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int n;
    void bfs(vector<vector<int>>& isConnected,int u,vector<bool>&vis){
        queue<int> q;
        vis[u]=true;
        q.push(u);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            //neighbors
            for(int neigh=0;neigh<n;neigh++){
                if(!vis[neigh] && isConnected[u][neigh]==1){
                    bfs(isConnected,neigh,vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();

        vector<bool> vis(n,false);
        int ctr=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(isConnected,i,vis);
                ctr++;
            }
        }
        return ctr;
    }
};
// class Solution {
// public:
//     void bfs(unordered_map<int,vector<int>> &adj,int u,vector<bool>&vis){
//         queue<int> q;
//         vis[u]=true;
//         q.push(u);
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(int &neigh:adj[node]){
//                 if(!vis[neigh]){
//                     bfs(adj,neigh,vis);
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         unordered_map<int,vector<int>> adj;
//         //make graph
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool> vis(n,false);
//         int ctr=0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 bfs(adj,i,vis);
//                 ctr++;
//             }
//         }
//         return ctr;
//     }
// };
// //dfs
// class Solution {
//     void dfs(unordered_map<int,vector<int>> &adj,int u,vector<bool> &vis){
//         vis[u]=true;
//         for(int &v:adj[u]){
//             if(!vis[v]){
//                 dfs(adj,v,vis);
//             }
//         }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected){
//         int n=isConnected.size();
//         unordered_map<int,vector<int>> adj;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool> vis(n,false);
//         int ctr=0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 ctr++;
//                 dfs(adj,i,vis);
//             }
//         }
//         return ctr;
//     }
// };
// // //bfs
// // class Solution {
// // public:
// //     int findCircleNum(vector<vector<int>>& M) {
// //         int n=M.size();
// //         if(n==0)return n;
// //         int circles=0;
// //         vector<bool> visited(n,false);  
// //         for(int i=0;i<n;i++){
// //             if(visited[i])continue;
// //             queue<int> q1;
// //             q1.push(i);
// //             circles++;
// //            while(!q1.empty()){               
// //            int cur=q1.front();
// //            q1.pop();
// //            visited[cur]=true;
// //                for(int j=0;j<M[cur].size();j++){
// //                     if(visited[j]==false&&M[cur][j]==1){
// //                     q1.push(j);
// //                     visited[j]=true;
// //                     }
// //                }
// //             }
// //         }
// //         return circles;
// //     }
// // };
// // // Time complexity:
// // // DFS - O(N+M)
// // // BFS - O(N+M)
// // // N - Number of Vertices.
// // // M - Number of Edges.

// // // Space complexity:
// // // DFS - O(H)
// // // BFS - O(W)
// // // H - Maximum Height of the Graph
// // // W - Maximum Width of the Graph
// // // //dfs
// // // class Solution {
// // // public:
// // // void soln(vector<int>adj[],int node,vector<bool>&vis){
// // //     vis[node] = 1;
// // //     for(auto i:adj[node]){
// // //         if(!vis[i]){
// // //             soln(adj,i,vis);
// // //         }
// // //     }
// // // }
// // //     int findCircleNum(vector<vector<int>>& isConnected) {
// // //         int n = isConnected.size();
// // //         vector<int>adj[n];
// // //         for(int i = 0;i<n;i++){
// // //             for(int j = 0;j<n;j++){
// // //                 if(isConnected[i][j]){
// // //                 adj[i].push_back(j);
// // //                 adj[j].push_back(i);
// // //                 }
// // //             }
// // //         }
// // //         vector<bool>vis(n,0);
// // //         int ans= 0;
// // //         for(int i = 0;i<n;i++){
// // //             if(!vis[i]){
// // //                 soln(adj,i,vis);
// // //                 ans++;
// // //             }
// // //         }
// // //         return ans;
// // //     }
// // // };

// // // class Solution {
// // // public:
// // //     //It will be use to store groups
// // //     vector<int> v;    
// // //     //Find the leader of any group in which x lies
// // //     //if not lie in any group then it is self leader
// // //     int parent(int x){
// // //         //self leader
// // //         if(v[x]==-1) return x; 
// // //         //find the leader of self parent
// // //         return v[x]=parent(v[x]);
// // //     }
// // //     //Adding 2 friends in a group
// // //     void _union(int a,int b){
// // //         //find the leader of both a and b
// // //         int p_a=parent(a),p_b=parent(b);
// // //         //if already in same group, i.e leader of both of them are same then return
// // //         if(p_a==p_b) return; 
// // //         /*
// // //          if both of them are from different group then add both the groups 
// // //          and make a single common group
// // //          We can do this by -> leader of 1st group is member of 2nd group 
// // //          and now main leader of whole group is leader of 2nd member
// // //         */ 
// // //         v[p_a]=p_b; //v[p_a] will store the index of leader of whole group
// // //     }
// // //     int findCircleNum(vector<vector<int>>& M) { 
// // //         int n=M.size();
// // //         v=vector<int> (n,-1);//there will be maximum n group, mark all as a leader   
// // //         //making group
// // //         for(int i=0;i<n;i++){
// // //             for(int j=0;j<n;j++){
// // //                 if(M[i][j]){  //if i is friend of j, add them in a group{ 
// // //                     //if i is in any group then add j in that group
// // //                     //or vice-versa
// // //                     _union(i,j);  //Add them in a group
// // //                 }
// // //             }
// // //         }
// // //         int c=0; 
// // //         //counting group
// // //         for(int i=0;i<n;i++){
// // //             if(v[i]==-1) c++; //counting total number of parents
// // //         }
// // //         return c; 
// // //     }
// // // };