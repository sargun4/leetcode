class Solution {
public:
// If a player reaches a node first, they collect the full value of that node
// If both players arrive at the same node at the same time, they split the value equally
// If a node was previously visited by the other player, no income is collected

// Bob only has one possible path to node 0-dfs
// Unlike Bob, Alice has multiple choices since a tree can have multiple leaves. This means we need to considers all possible paths-bfs lvl by lvl
    vector<vector<int>> adj;
    vector<bool> vis;
    int maxincome=INT_MIN;
    unordered_map<int,int> bobPath;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        adj.resize(n);
        vis.assign(n,false);
        
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        //path and time bob takes to reach node 0 
        findBobPath(bob,0);

        //alice's optimal path-bfs
        vis.assign(n,false);
        queue<vector<int>> q;//{node,time,income};
        q.push({0,0,0});
        while(!q.empty()){
            auto curr=q.front();
            int src=curr[0];
            int time=curr[1];
            int income=curr[2];
                        //mark n remove curr nde
            vis[src]=true;
            q.pop();
            // /alice reaches the node first
            if(bobPath.find(src)==bobPath.end() || time<bobPath[src]){
                income+=amount[src];
            }
            //alice n bob reach node at same time;
            else if(time==bobPath[src]){
                income+=(amount[src]/2);
            }
            //update max val if curr node is a new leaf;
            if(adj[src].size()==1 && src!=0){
                maxincome=max(maxincome,income);
            }
            //neigh nodes visit
            for(int neigh:adj[src]){
                if(!vis[neigh]){
                    q.push({neigh,time+1,income});
                }
            }

        }

        return maxincome;
    }
    //dfs
    bool findBobPath(int bobNode,int time){
        bobPath[bobNode]=time;
        vis[bobNode]=true;
        if(bobNode==0) return true;//reached 0
        //trav
        for(int neigh:adj[bobNode]){
            if(!vis[neigh] && findBobPath(neigh,time+1)){
                return true;
            }
        }
        //if node 0 isnt reached,remove curr ndoe frm path
        bobPath.erase(bobNode);
        return false;
    }
};