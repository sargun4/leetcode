#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2];
            adj[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        adj[u].push_back({v,cost});
    }
    
        
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(N,INT_MAX);
        res[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjnode=vec.first;
                int dist=vec.second;
                if(dist+d<res[adjnode]){
                    res[adjnode]=dist+d;
                    pq.push({d+dist,adjnode});
                }
            }
        }
        return res[node2]==INT_MAX ?-1:res[node2]; //shortest dist frm src(node1) to node2
    }
};
 
// edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.