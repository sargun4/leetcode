class Solution {
public:
//dfs-compute how many nodes (ppl) are in the subtree rooted at each node
    void countChild(int idx,vector<vector<int>>&adj,vector<int>&child){
        child[idx]=1;
        for(auto&neigh:adj[idx]){
            if(child[neigh]==0){//not yet vis
                countChild(neigh,adj,child);
                child[idx]+=child[neigh];
            }
        }
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adj(n+1);
        for(auto e:roads){
            int u=e[0]; int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //child[i]=no of nodes in the subtree rooted at node i
        vector<int> child(n+1,0);
        vector<int> vis(n+1,0);
        countChild(0,adj,child);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        long long minfuel=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto&neigh:adj[node]){
                if(!vis[neigh]){
                    int ctr=child[neigh];//no of ppl in subtree rooted at this neigh
                    minfuel+= ctr/seats;//no of full cars req
                    if(ctr%seats){//if rem, 1more car req
                        minfuel++;
                    }
                    q.push(neigh);
                    vis[neigh]=1;
                }
            }
        }
        return minfuel;
    }
};