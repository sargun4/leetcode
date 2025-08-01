//// dfs+dfs
// class Solution {
// public:
// // If a player reaches a node first, they collect the full value of that node
// // If both players arrive at the same node at the same time, they split the value equally
// // If a node was previously visited by the other player, no income is collected
// // Bob only has one possible path to node 0-dfs 
//     unordered_map<int,vector<int>> adj;
//     //store bob's arrival time to each node
//     unordered_map<int,int> bobMap;//{node,time to reach it} for bob
//     int aliceIncome;
// //finds the unique path from bob to node 0
//     bool dfsBob(int node,int t,vector<bool>&vis){
//         vis[node]=true;
//         bobMap[node]=t;//record th time bob takes to reach the node
//         if(node==0){//reached target node=0
//             return true;
//         }
//         for(auto&neigh:adj[node]){
//             if(!vis[neigh]){
//                 if(dfsBob(neigh,t+1,vis)==true){
//                     return true;
//                 }
//             }
//         }
//         //if path to 0 not found through this node, remove it
//         bobMap.erase(node);
//         return false;
//     }
//     //alice explores all possible paths starting from 0.
//     void dfsAlice(int node,int t,int income,vector<bool>&vis,vector<int>&amount){
//         vis[node]=true;
//         //if bob hasnt reached the node(cudnt find it in bobMap) or alice reached earlier than bob on that node 
//         if(bobMap.find(node)==bobMap.end() || t<bobMap[node]){
//             income+=amount[node];//so alice will get full amt of that node
//         }else if(t==bobMap[node]){//bob and alice reach at same time on that node
//             income+=(amount[node]/2);//so alice n bob will get half amt each of that node
//         }
//         // If Bob already visited earlier, Alice gets 0.

//         //if alice reached leaf node excluding 0 cuz thats the dest
//         if(adj[node].size()==1 && node!=0){
//             aliceIncome=max(aliceIncome,income);
//         }
//         for(int&neigh:adj[node]){
//             if(!vis[neigh]){
//                 dfsAlice(neigh,t+1,income,vis,amount);
//             }
//         }
//     }
//     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
//         int n=amount.size();
//         aliceIncome=INT_MIN;
//         for(auto&e:edges){//undir graph
//             int u=e[0]; int v=e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int time=0;
//         vector<bool> vis(n,false);
//         //dfs on bob for finding time to reach each node till 0
//         dfsBob(bob,time,vis);
//         int income=0;
//         vis.assign(n,false);
//         dfsAlice(0,0,income,vis,amount);
//         return aliceIncome;
//     }
// };

// BFS+DFS
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
    unordered_map<int,int> bobPath;//{node,time to reach it} for bob
    //dfs to find bob path
    bool findBobPath(int bobNode,int time){
        bobPath[bobNode]=time;
        vis[bobNode]=true;
        if(bobNode==0) return true;//bob reached 0
        //trav neighs
        for(int neigh:adj[bobNode]){
            if(!vis[neigh] && findBobPath(neigh,time+1)){
                return true;
            }
        }
        //if node 0 isnt reached,remove node ndoe frm path
        bobPath.erase(bobNode);
        return false;
    }
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
            auto node=q.front();
            int src=node[0];
            int time=node[1];
            int income=node[2]; 
            vis[src]=true;//mark it vis
            q.pop();
            //alice reaches the node first
            if(bobPath.find(src)==bobPath.end() || time<bobPath[src]){//either bob isnt able to reach that node or time req by alice to reach that node is lesser than bob's time to reach it
                income+=amount[src];
            }
            else if(time==bobPath[src]){//alice n bob reach node at same time;
                income+=(amount[src]/2);//they get half each
            }
            //else bob was earlier-income unchanged-alice gets nothing

            //update max val if node node is a new leaf;
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
};