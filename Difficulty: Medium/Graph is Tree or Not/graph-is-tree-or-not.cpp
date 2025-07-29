class Solution {
public:
    bool isCyclic(int node, int parent, vector<int> graph[], vector<int>& vis) {
        vis[node] = 1;
        for(auto neigh: graph[node]) {
            if(!vis[neigh]) {
                if(isCyclic(neigh, node, graph, vis)) return true;
            }
            else if(neigh != parent)   
                return true; // neigh is vis except parent
        }
        return false;
    }
 
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<int> graph[n], vis(n, 0);
        for(auto &v: adj) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        int components = 0; // connected-component
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                components++;
                if(isCyclic(i, -1, graph, vis))  return false;
            }
        }
        return (components == 1);
    }
};