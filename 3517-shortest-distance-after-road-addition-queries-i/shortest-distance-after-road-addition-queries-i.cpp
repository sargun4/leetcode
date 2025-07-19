using p=pair<int,int>;//{wt,node}
class Solution {
public:
    unordered_map<int,vector<p>> adj;//{u:{v,wt=1}}
    //O(Elog(V))
    int dijkstra(int n){
        vector<int> res(n,INT_MAX);//res[i]=shortest dist frm src to ith node
        res[0]=0;
        priority_queue<p,vector<p>,greater<p>> pq;//minheap -{dist,node}
        pq.push({0,0});
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int dist=curr.first;
            int node=curr.second;
            if(node==n-1){//reached dest node
                return res[n-1];
            }
            for(auto &[neigh,wt]:adj[node]){
                if(dist+wt<res[neigh]){
                    res[neigh]=dist+wt;
                    pq.push({dist+wt,neigh});
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1}); //treating each edge et as 1
        }
        int q=queries.size();
        vector<int> res;
        for(auto&q:queries){//O(q*Elog(V))
            int u=q[0]; int v=q[1];
            adj[u].push_back({v,1});
            int d=dijkstra(n);
            res.push_back(d);
        }
        return res;
    }
};
//bfs
// class Solution {
// public:
//     unordered_map<int,vector<int>> adj;
//     int bfs(int n){
//         queue<int> q;
//         q.push(0);//src node
//         vector<int> vis(n,0);
//         vis[0]=0;
//         int lvl=0;
//         while(!q.empty()){
//             int len=q.size();
//             while(len--){
//                 int node=q.front(); q.pop();
//                 if(node==n-1){//reached dest
//                     return lvl;
//                 }
//                 for(int&neigh:adj[node]){
//                     if(!vis[neigh]){
//                         q.push(neigh);
//                         vis[neigh]=1;
//                     }
//                 }
//             }
//             lvl++;
//         }
//         return -1;//unreachble
//     }
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         for(int i=0;i<n-1;i++){
//             adj[i].push_back(i+1);
//         }
//         int q=queries.size();
//         vector<int> res;
//         for(auto&q:queries){
//             int u=q[0]; int v=q[1];
//             adj[u].push_back(v);
//             int d=bfs(n);
//             res.push_back(d);
//         }
//         return res;
//     }
// };