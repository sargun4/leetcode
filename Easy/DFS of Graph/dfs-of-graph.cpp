//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
class Solution {
  public:
    void DFS(unordered_map<int,vector<int>> &adj,int u,vector<bool>&vis,vector<int>&res){
        if(vis[u]==true){
            return ;
        }
        vis[u]=true;
        res.push_back(u);
        for(int &v:adj[u]){
            if(!vis[v]){
                DFS(adj,v,vis,res);
            }
        }

    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> map[]) {
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<V;u++){
            for(auto v=map[u].begin();v!=map[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        vector<int> res;
        vector<bool> visited(V,false);
        DFS(adj,0, visited, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends