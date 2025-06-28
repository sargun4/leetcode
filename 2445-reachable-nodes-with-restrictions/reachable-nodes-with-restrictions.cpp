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
        int ctr=1;//since node 0 is alwys reachable
        // set<int> restr;
        // for(int i:restricted){
        //     restr.insert(i);
        // }
        //OR
        unordered_set<int> restr(restricted.begin(), restricted.end());
        while(!q.empty()){//BFS to count reachable nodes from node 0
            int node=q.front(); q.pop();
        
            for(auto &neigh:adj[node]){
                //if neigh not yet vis n not in restriced nodes,visit and push
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