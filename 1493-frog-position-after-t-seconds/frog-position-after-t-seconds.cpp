// - Start BFS from node 1 at time 0, with prob 1.0
// - At each step:
//   - Count unvis children
//   - Divide prob equally among children
// - If time t is reached:
//   - If current node is target → return current prob
//   - Else, continue processing (but we skip enqueuing further neighs)
// - If the frog reaches a dead-end (no unvis children) before time t, it stays in place

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
        queue<tuple<int,int,double>> q; //{node, time, prob}
        q.push({1,0,1.0});//start at node=1, w time=0 and prob=1.0
        vis[1]=1;//mark node 1 as vis
        //bfs
        while(!q.empty()){
            auto [node,time,prob]=q.front(); q.pop();
            if(time==t){//reached time limit t
                if(node==target)//reached target
                    return prob;
                continue;//else, skip furthr trav
            }
            int unvisChildren=0;
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    unvisChildren++;
                }
            }
            // If no unvis children,
            if(unvisChildren==0){//dead end-frog stays at curr node
                if(node==target) return prob;
                continue;
            }
            //push unvis neighs into the queue with divided prob
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push({neigh,time+1,prob/unvisChildren});
                }
            }
        }        
        return 0.0;//if target is never reached
    }
};