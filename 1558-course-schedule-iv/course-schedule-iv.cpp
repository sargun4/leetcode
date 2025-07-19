class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int src,int dest,vector<bool> &vis){
        vis[src]=true;
        if(src==dest) return true;//we hv reached dest
        bool isReachable=false;
        for(auto&neigh:adj[src]){
            if(!vis[neigh]){
                isReachable=isReachable|| dfs(adj,neigh,dest,vis);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto &e:prerequisites){//directed unweighted graph
            int u=e[0];int v=e[1];
            adj[u].push_back(v);
        }
        int q=queries.size();
        vector<bool> res(q);
        for(int i=0;i<q;i++){
            int u=queries[i][0];//src
            int v=queries[i][1];//dest
            vector<bool> vis(numCourses,false);
            res[i]=dfs(adj,u,v,vis);
        }
        return res;
    }
};