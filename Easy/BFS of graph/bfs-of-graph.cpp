//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//  O(V+E)
class Solution {
  public:
    void BFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &vis,vector<int> &res){
        queue<int> q;
        q.push(u);
        vis[u]=true;
        res.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    res.push_back(v);
                }
            }
        }

    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<V;i++){
            for(auto it=mp[i].begin();it!=mp[i].end();it++){
                adj[i].push_back(*it);
            }
        }
        vector<bool> vis(V,false);
        vector<int> res;
        BFS(adj,0,vis,res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends