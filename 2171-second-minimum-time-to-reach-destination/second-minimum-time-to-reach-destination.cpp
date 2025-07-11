#define p pair<int,int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n+1,INT_MAX);//shortest time to reach node
        vector<int> d2(n+1,INT_MAX);//2nd shortest time to reach node

        //dijkstra
        priority_queue<p,vector<p>,greater<p>> pq; //minheap-{time,ndoe}
        pq.push({0,1});//start with time=0 frm node 1
        d1[1]=0;
        while(!pq.empty()){
            auto [timepassed,node]=pq.top();
            pq.pop();

            if(node==n && d2[n]!=INT_MAX){
                return d2[n];//once 2nd min time to destination is found
            }
            int div=timepassed/change;
            if(div%2==1){//odd-red light-wait
                timepassed=(div+1)*change;
            }
            for(auto &neigh:adj[node]){//trav all reachable nodes frm node
                if(d1[neigh]>timepassed+time){//if curr path is lesser than prev recorded one
                    d2[neigh]=d1[neigh];//shift prev best to 2nd best
                    d1[neigh]=timepassed+time;//set new best(shortest time)
                    pq.push({timepassed+time,neigh});//add to pq
                }
    //if the curr path doesn't improve shortest time (d1) but can improve the second shortest (d2), we update d2.
                else if(d2[neigh]>timepassed+time && d1[neigh]!=timepassed+time){
                    d2[neigh]=timepassed+time;
                    pq.push({timepassed+time,neigh});
                }
            }
        }
        return -1;
    }
};