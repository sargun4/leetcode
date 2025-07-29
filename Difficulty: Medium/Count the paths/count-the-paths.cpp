//kahn's toposort bfs
class Solution {
public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<long long> dist(V, 0);  
        dist[src]=1;
        queue<int> q;
        for(int i=0;i<V;i++){
            if (indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                dist[v] += dist[u];
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return dist[dest];
    }
};