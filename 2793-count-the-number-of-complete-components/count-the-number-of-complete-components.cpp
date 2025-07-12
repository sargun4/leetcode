// For a component with k vertices to be complete, every vertex must have exactly k - 1 edges connecting it to the other vertices within the component.
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
        for(int i=0;i<n;i++){//go over all nodes
            if(!vis[i]){
                vector<int> comp;//store all nodes in this component
                bfs(i,adj,comp,vis);//bfs to fill this componen
                bool iscomp=true;//is component complete?
                for(auto neigh:comp){
                    //in a complete component w k nodes, each node has degree k - 1
        //in a complete graph: each node connects to every other node in the component. So, in a k-node component, every node must have k-1 edges.
                    if(adj[neigh].size()!=comp.size()-1){
                        iscomp=false;
                        break;
                    }
                }
                if(iscomp) ans++;//complete comp
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