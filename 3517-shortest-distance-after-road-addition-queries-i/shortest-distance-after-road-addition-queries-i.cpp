class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int bfs(int n){
        queue<int> q;
        q.push(0);//src node
        vector<int> vis(n,0);
        vis[0]=0;
        int lvl=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int node=q.front(); q.pop();
                if(node==n-1){//reached dest
                    return lvl;
                }
                for(int&neigh:adj[node]){
                    if(!vis[neigh]){
                        q.push(neigh);
                        vis[neigh]=1;
                    }
                }
            }
            lvl++;
        }
        return -1;//unreachble
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        int q=queries.size();
        vector<int> res;
        for(auto&q:queries){
            int u=q[0]; int v=q[1];
            adj[u].push_back(v);
            int d=bfs(n);
            res.push_back(d);
        }
        return res;
    }
};