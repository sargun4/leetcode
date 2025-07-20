class Solution {
public:
//dfs
    int getMaxFrmEachComp(unordered_map<int,vector<int>> &adj,int curr,vector<bool>&vis,vector<int>&lvls){
        int maxgrp=lvls[curr];
        vis[curr]=true;
        for(int &neigh:adj[curr]){
            if(!vis[neigh]){
                maxgrp=max(maxgrp,getMaxFrmEachComp(adj,neigh,vis,lvls));
            }
        }
        return maxgrp;
    }
    bool isBipartite(unordered_map<int,vector<int>> &adj,int node,vector<int>&colors,int currcolor){
        colors[node]=currcolor;
        for(int &neigh:adj[node]){
            if(colors[neigh]==colors[node]){
                return false;
            }
            if(colors[neigh]==-1){
                if(isBipartite(adj,neigh,colors,1-currcolor)==false){
                    return false;
                }
            }
        }
        return true;//is bipartite
    }
    int bfs(unordered_map<int,vector<int>> &adj,int currnode,int n){
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(currnode);
        vis[currnode]=true;
        int lvl=1;//max grps in that component of graph
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int node=q.front(); q.pop();
                for(int&neigh:adj[node]){
                    if(!vis[neigh]){
                        vis[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
            lvl++;
        }
        return lvl-1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto&e:edges){
            int u=e[0]-1;//converting to 0 based-idxing
            int v=e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //bipartite check
        vector<int> colors(n,-1);//initally all nodes uncolored
        for(int node=0;node<n;node++){
            if(colors[node]==-1){//not yet colored
                if(isBipartite(adj,node,colors,1)==false){
                    return -1;
                }
            }
        }
        //bfs to get max lvls for each node
        vector<int> lvls(n,0);
        
        for(int node=0;node<n;node++){//going over all nodes n bfs frm each- O(V*(V+E))
            lvls[node]=bfs(adj,node,n);
        }
        int maxGrpsFrmEachComp=0;
        vector<bool> vis(n,false);
        for(int node=0;node<n;node++){
            if(!vis[node]){
                maxGrpsFrmEachComp+=getMaxFrmEachComp(adj,node,vis,lvls);
            }
        }
        return maxGrpsFrmEachComp;
    }
};