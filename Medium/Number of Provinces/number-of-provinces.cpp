//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

 
class Solution {
  public:
    void dfs(unordered_map<int,vector<int>> &graph,int u,vector<bool> &vis){
        vis[u] = true;
        //visit neighbors
        for (int &v : graph[u]){
            if (!vis[v])
                dfs(graph,v,vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int n=V;
        vector<bool> vis(n,false);
        //make graph
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ctr=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis);
                ctr++;
            }
        }
        return ctr;
    }
};

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