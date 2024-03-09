#include <bits/stdc++.h>
using namespace std;
class Solution {//dijktsrtra
public:
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double>res(n,0);
        for(int i=0;i<edges.size();i++){//make adj list
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        priority_queue<P> pq;//max heap
        res[start_node]=1; //prob to reach start node is 1
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double currprob=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();
            for(auto &neigh:adj[currnode]){
                double adjprob=neigh.second;
                int adjnode=neigh.first;
                if(res[adjnode]<currprob*adjprob){
                    res[adjnode]=currprob*adjprob;
                    pq.push({res[adjnode],adjnode});
                }
            }
        }
        return res[end_node];
    }
};