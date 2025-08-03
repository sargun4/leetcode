typedef pair<double,int> p;
class Solution {//dijktsrtra
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;//{node:{neigh,prob}}
        vector<double>ans(n,0);
        for(int i=0;i<edges.size();i++){//make adj list
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        priority_queue<p> pq;//max heap
        ans[start_node]=1; //prob to reach start node is 1
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto curr=pq.top();
            double prob=curr.first;
            int node=curr.second;
            pq.pop();
            for(auto &neigh:adj[node]){
                double adjprob=neigh.second;
                int adjnode=neigh.first;
                if(ans[adjnode]<prob*adjprob){
                    ans[adjnode]=prob*adjprob;
                    pq.push({ans[adjnode],adjnode});
                }
            }
        }
        return ans[end_node];
    }
};