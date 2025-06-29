class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> comp;
                bfs(i,adj,comp,vis);
                bool iscomp=true;
                for(auto neigh:comp){
                    if(adj[neigh].size()!=comp.size()-1){
                        iscomp=false;
                        break;
                    }
                }
                if(iscomp) ans++;
            }
        }
        return ans;
    }
    void bfs(int node,vector<vector<int>>&adj,vector<int>&comp,vector<bool>&vis){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            comp.push_back(curr);
            for(auto neigh:adj[curr]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh]=true;
                }
            }
        }
    }
};