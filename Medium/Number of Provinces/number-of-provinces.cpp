//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bfs(vector<vector<int>>&adj,int u,vector<bool>&vis){
        int V=adj.size();
        queue<int>q;
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int v=0;v<V;v++){
                if(!vis[v] && adj[u][v]==1){
                    bfs(adj,v,vis);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>vis(V,false);
        int ctr=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(adj,i,vis);
                ctr++;
            }
        }
        return ctr;
    }
};
#include <bits/stdc++.h>
using namespace std;
// class Solution {
//   public:
//     int n;
//     void dfs(vector<vector<int>> &adj,int u,vector<bool> &vis){
//         vis[u] = true;
//         //visit neighbors
//         for (int v=0;v<n;v++){
//             if (!vis[v] && adj[u][v]==1)
//                 dfs(adj,v,vis);
//         }
//     }
//     int numProvinces(vector<vector<int>> adj, int V) {
//         n=V;
//         vector<bool> vis(n,false);
         
//         int ctr=0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(adj,i,vis);
//                 ctr++;
//             }
//         }
//         return ctr;
//     }
// };
// // class Solution {
// //   public:
// //     void dfs(unordered_map<int,vector<int>> &graph,int u,vector<bool> &vis){
// //         vis[u] = true;
// //         //visit neighbors
// //         for (int &v : graph[u]){
// //             if (!vis[v])
// //                 dfs(graph,v,vis);
// //         }
// //     }
// //     int numProvinces(vector<vector<int>> adj, int V) {
// //         int n=V;
// //         vector<bool> vis(n,false);
// //         //make graph
// //         unordered_map<int,vector<int>> graph;
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<n;j++){
// //                 if(adj[i][j]==1){
// //                     graph[i].push_back(j);
// //                     graph[j].push_back(i);
// //                 }
// //             }
// //         }
// //         int ctr=0;
// //         for(int i=0;i<n;i++){
// //             if(!vis[i]){
// //                 dfs(graph,i,vis);
// //                 ctr++;
// //             }
// //         }
// //         return ctr;
// //     }
// // };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends