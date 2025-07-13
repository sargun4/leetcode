class Solution {
public:
//bfs Toposort-KAHN's algo
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        vector<vector<int>> adjRev(n);//rev all edges in graph
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){//go over all nodes to handle disconnected graph
            for(auto it:graph[i]){//rev edge to make reverse adjList: it->i
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){//terminal node
                q.push(i);
            }
        }
        vector<int> safenodes;
        while(!q.empty()){
            int node=q.front(); q.pop();
            safenodes.push_back(node);
            for(int neigh:adjRev[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        sort(begin(safenodes),end(safenodes));
        return safenodes;
    }
};

// //dfs
// class Solution {
// private:
//     bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& check) {
//         vis[node] = 1;
//         check[node] = 0;
//         for (int it : graph[node]) {
//             if (!vis[it]) {
//                 if (dfsCheck(it, graph, vis, check)) {
//                     check[node] = 0;
//                     return true;
//                 }
//             }
//             else if (check[it] == 0) {
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         check[node] = 1;
//         return false;
//     }
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> vis(n, 0);
//         vector<int> check(n, -1); // -1 for unvisited, 0 for unsafe, 1 for safe
//         vector<int> safeNodes;

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 dfsCheck(i, graph, vis, check);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             if (check[i] == 1)
//                 safeNodes.push_back(i);
//         }

//         return safeNodes;
//     }
// };
