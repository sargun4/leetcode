class Solution {
public:
    // DFS to check if v is reachable from u
    bool dfs(unordered_map<int,vector<int>> &adj,int u,int v, vector<bool>&vis){
        vis[u]=true;//mark curr node u as vis to avoid revisiting
        if(u==v) return true;//if we have reached v starting from u, then a path exists
        //explore all neighbors of the current node u
        for(int &neigh:adj[u]){
        //if neigh not vis,perform dfs for it
            if(vis[neigh]) continue;
            //if v i reachable thru this neigh
            if(dfs(adj,neigh,v,vis)){
                return true;
            }
        }
        return false;//no path frm u to v found in dfs path
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<bool>vis(n,false);
        // Check if adding this edge (u,v) creates a cycle:
        // - If both u and v already exist in adj and a path from u to v exists,
        //   adding this edge would close the cycle.
        //if both u and v exist & r connected, this edge is redundant
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj,u,v,vis)){
                return edges[i];//redudnant, return it
            }
        //else add edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};//wont reach here as problem guarantees a redundant edge
    }
};