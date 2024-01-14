//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//using DFS
class Solution{
	public:
    void dfs(vector<int> adj[],int u,vector<bool> &vis,stack<int>&st){
        vis[u] = true;
        //first add u's children to stack
        for (int&v:adj[u]){
            if (!vis[v])
                dfs(adj, v, vis, st);
        }
        //then add u to stack
        st.push(u);
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,st);
            }
        }
        vector<int> res;
        while(!st.empty()){
            int t = st.top();
            res.push_back(t);
            st.pop();
        }
        return res;
	}
};
//using BFS
// class Solution{
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) {
// 	    vector<int> indegree(V,0);
//         vector<int> ans;
//         queue<int> q;
//         for(int i=0;i<V;i++){
//             for(auto neigh : adj[i]){
//                 indegree[neigh]++;
//             }
//         }
//         // Push all the vertex with no incoming edge to the queue
//         for(int i=0;i<V;i++) 
//             if (indegree[i] == 0) q.push(i);

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);
//             // Reduce in-degree of adjacent vertices by one and if it becomes zero then push it to the queue
//             for(auto neigh : adj[node]){
//                 indegree[neigh]--;
//                 if(indegree[neigh]==0) q.push(neigh);
//             }
//         }
//         return ans;
// 	}
// };

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends