// //Time : O(n), Space : O(n)
// class Solution {
// public:
//     //store count of subtrees of each node
//     long result_base_node = 0;
//     vector<int> count;
//     int N;
//     int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
//         int total_node = 1;
        
//         result_base_node += curr_depth;
        
//         for(int &child : adj[curr_node]) {
//             if(child == prev_node)
//                 continue;
            
//             total_node += dfsBase(adj, child, curr_node, curr_depth+1);
//         }
        
//         //store count of subtrees of each node
//         count[curr_node] = total_node;
        
//         return total_node;
//     }
    
//     void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& res) {
        
//         for(int &child : adj[parent_node]) {
//             if(child == prev_node)
//                 continue;
            
//             res[child] = res[parent_node] - count[child] + (N - count[child]);
//             DFS(adj, child, parent_node, res);
//         }
        
//     }
    
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> adj;
//         N = n;
//         count.resize(n, 0);
//         for(auto &vec : edges) {
//             int u = vec[0];
//             int v = vec[1];
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
        
//         result_base_node = 0;
        
//         dfsBase(adj, 0, -1, 0);
        
//         vector<int> res(n, 0);
        
//         res[0] = result_base_node;
        
//         DFS(adj, 0, -1, res);
        
//         return res;
//     }
// };

class Solution {
public:
    //dfs to compute:
    //1.dist sum from node 0 to all others (stored in res)
    //2.no of nodes in each subtree (stored in child)
    int dfs(int node, vector<vector<int>>&adj, vector<int> &child, vector<int> &vis, int &res, int level){
        vis[node] = 1;
        res += level;  //add dist from root to curr node
        int children = 0;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                //recursively process subtree and accumulate child counts
                children += dfs(neigh, adj, child, vis, res, level + 1);
            }
        }

        //total nodes in subtree = all children + the node itself
        return child[node] = children + 1;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        //undir grpah
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int res=0;//store ans for node 0 (sum of dists to all nodes)
        vector<int> child(n, 0);//child[i] = no of nodes in subtree rooted at i
        vector<int> vis(n, 0);

        //Step 1: Post-order DFS to compute `res` for node 0 and subtree sizes
        dfs(0, adj, child, vis, res, 0);

        // Step 2: BFS to compute res for all nodes
        vector<int> ans(n, 0);
        vector<int> vis1(n, 0);  //vis for second traversal

        queue<pair<int, int>> q;  //{node,parent}
        q.push({0, 0});
        vis1[0] = 1;
        while (!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            if (node == 0) {
                ans[node] = res;  //alr computed
            } else {
                //use parent res to compute this node's res
                int parent_val = ans[parent];
                int upper_nodes = n - child[node];

                ans[node] = parent_val - child[node] + upper_nodes;
            }
            for (auto neigh : adj[node]) {
                if (!vis1[neigh]) {
                    q.push({neigh, node});
                    vis1[neigh] = 1;
                }
            }
        }
        return ans;
    }
};
