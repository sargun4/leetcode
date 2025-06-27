class Solution {
public:
    //dfs to compute:
    //1.dist sum frm node 0 to all others (stored in res)
    //2.no of nodes in each subtree (stored in child)
    int dfs(int node, vector<vector<int>>&adj, vector<int> &child, vector<int> &vis, int &res, int lvl){
        vis[node] = 1;//vis this node
        res += lvl;//add dist frm root to curr node
        int children = 0;//no of nodes in the subtree
        for (auto neigh:adj[node]){
            if (!vis[neigh]){
                //recursively process subtree and accumulate child counts
                children += dfs(neigh, adj, child, vis, res, lvl + 1);
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
        vector<int> vis(n, 0);//for dfs-1st trav on root

        //Step 1:Post-order dfs to compute `res` for node 0 and subtree sizes
        dfs(0, adj, child, vis, res, 0);

        //Step 2: bfs to compute res for all nodes
        vector<int> ans(n, 0);
        vector<int> vis1(n, 0);//vis1 for second traversal

        queue<pair<int, int>> q;//{node,parent}
        q.push({0, 0});
        vis1[0]=1;//root node 0 been vis alr,so mark
        while(!q.empty()){
            auto [node,parent] = q.front(); q.pop();
            if(node==0){
                ans[node]=res;  //alr computed
            } else{
                // When we move our root from one node to its connected node,one part of nodes get closer, one the other part get further.
                //use parent res to compute this node's res
                int parent_val=ans[parent];
                int upper_nodes=n-child[node];//nodes not falling in subtree of node
                //if we move the root from parent to node:
                // -subtree of node moves 1 closer (child[node] nodes)
                // -All other nodes move 1 farther (n - child[node])                
                ans[node] = parent_val - child[node] + upper_nodes;
            }
            for (auto neigh : adj[node]) {
                if (!vis1[neigh]){
                    q.push({neigh, node});
                    vis1[neigh] = 1;
                }
            }
        }
        return ans;
    }
};
