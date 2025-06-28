class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int ctr=1;
        set<int> restr;
        for(int i:restricted){
            restr.insert(i);
        }
        while(!q.empty()){
            int node=q.front(); q.pop();
            //ctr+=1;
            for(auto &neigh:adj[node]){
                //neigh not yet vis n not in restriced nodes
                if(!vis[neigh] && restr.find(neigh)==restr.end()){
                    vis[neigh]=true;
                    q.push(neigh);
                    ctr+=1;
                }
            }
        }
        return ctr;
    }
};