class Solution {
public:
    #define p pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);
        //dijkstra
        priority_queue<p,vector<p>,greater<p>> pq; //{time,ndoe}
        pq.push({0,1});
        d1[1]=0;
        while(!pq.empty()){
            auto [timepassed,node]=pq.top();
            pq.pop();

            if(node==n && d2[n]!=INT_MAX){
                return d2[n];
            }
            int div=timepassed/change;
            if(div%2==1){//odd-red light
                timepassed=(div+1)*change;
            }
            for(auto &neigh:adj[node]){
                if(d1[neigh]>timepassed+time){
                    d2[neigh]=d1[neigh];
                    d1[neigh]=timepassed+time;
                    pq.push({timepassed+time,neigh});
                }else if(d2[neigh]>timepassed+time && d1[neigh]!=timepassed+time){
                    d2[neigh]=timepassed+time;
                    pq.push({timepassed+time,neigh});
                }
            }
        }
        return -1;
    }
};