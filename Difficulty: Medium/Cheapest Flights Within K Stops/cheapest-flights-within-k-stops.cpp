class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //q= {stops,{node,dist}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        //T-O(E)=flights.size()
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>K) continue; 
            for(auto iter: adj[node]){
                int adjnode=iter.first;
                int edgeWt=iter.second;
                if(cost+edgeWt<dist[adjnode] && stops<=K){ //relaxation and check at most k stops
                dist[adjnode]=cost+edgeWt;
                q.push({stops+1,{adjnode,cost+edgeWt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;//never reached
        return dist[dst];
    }
};


