//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// if topo sort doesnt exist = cycle exists
// since topo sort exists only for DAG;
class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indeg(V,0);
        vector<int> res; //store topo sorted order
        // calculate in degree of each vertex and store in indeg arr
        for(int i=0;i<V;i++){
            for(auto &v:adj[i]){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        int ctr=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ctr++;
            res.push_back(node);
            for(auto neigh:adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0) 
                    q.push(neigh);
            }
        }
        //if ctr is not equal to V then there is a cycle present in the graph
        if(ctr == V){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends