class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        for(auto e:edges){//undir grph
            int u=e[0]; int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0);
        queue<tuple<int,int,double>> q; //{node, time, probability}
        q.push({1,0,1.0});//start at node=1, w time=0 and prob=1.0
        vis[1]=1;
        while(!q.empty()){
            auto [node,time,prob]=q.front(); q.pop();
            if(time==t){
                if(node==target) return prob;
                continue;
            }
            int unvisChildren=0;
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    unvisChildren++;
                }
            }
            if(unvisChildren==0){//dead end-frog stays here
                if(node==target) return prob;
                continue;
            }
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push({neigh,time+1,prob/unvisChildren});
                }
            }
        }
        return 0.0;
    }
};