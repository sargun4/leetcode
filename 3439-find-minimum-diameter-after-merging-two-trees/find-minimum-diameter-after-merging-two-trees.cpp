class Solution {
public:
    vector<vector<int>> buildAdjList(int size,vector<vector<int>>& edges){
        vector<vector<int>> adj(size);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj1=buildAdjList(n,edges1);
        vector<vector<int>>adj2=buildAdjList(m,edges2);

        int diam1=findDiam(n, adj1);
        int diam2=findDiam(m, adj2);

        int combinedDiameter=(diam1 + 1) / 2 + (diam2 + 1) / 2 + 1;//longest path spanning across 2 trees after merging them
        return max({diam1, diam2, combinedDiameter});
    }
    int findDiam(int size,vector<vector<int>>&adj){//diam of tree using 2 bfs calls
        //1st bfs to find farthest node frm any node like 0
        auto [farthestNode, _ ]=findFarthestNode(size,adj,0);
        //2nd bfs to find farthest node frm the above calc farthest node to get diam;
        auto [_,diam]=findFarthestNode(size,adj,farthestNode);
        return diam;
    }
    //bfs
    pair<int,int> findFarthestNode(int size,vector<vector<int>>&adj,int src){
        queue<int> q;
        vector<bool> vis(size,false);
        q.push(src);
        vis[src]=true;
        int maxdist=0;  int farthestNode=src;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int node=q.front(); q.pop();
                farthestNode=node;//farthest node is last one to get popped out of q
                for(int neigh:adj[node]){
                    if(!vis[neigh]){
                        vis[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
            if(!q.empty()) maxdist++;
        }
        return {farthestNode,maxdist};
    }
};