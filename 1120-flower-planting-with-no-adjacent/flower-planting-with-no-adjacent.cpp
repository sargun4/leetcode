class Solution {
public:
    vector<int> ans;
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto e:paths){
            int u=e[0]; int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0);
        ans=vector<int>(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bfs(adj,vis,n,i);
            }
        }
        //remove 0th idx as gardens r 1idxed
        ans.erase(ans.begin());
        return ans;
    }
    void bfs(vector<vector<int>> &adj,vector<int>&vis,int n,int src){
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node=q.front(); q.pop();
            //track which flower types are used by neighs
            bool used[5]={false};//0 unused, 1-4 flowers
            for(int neigh:adj[node]){
                if(ans[neigh]!=0){
                    used[ans[neigh]]=true;
                }
            }
            //assign 1st avalble flower(1-4) not used by neighs
            for(int color=1;color<=4;color++){
                if(!used[color]){
                    ans[node]=color;
                    break;
                }
            }
            //visit unvis neighs
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh]=true;
                }
            }
        }
    }
};