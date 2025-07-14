using p=pair<int,int>;
class Solution {
  public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto d:dependency){
            int u=d.first;
            int v=d.second;
            adj[u].push_back(v);//directed graph
            indeg[v]++;
        }
        priority_queue<p,vector<p>,greater<>> pq;//minheap-{duration,node}
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){//start w these nodes
                pq.push({duration[i],i});
            }
        }
       int t=0, ctr=0;
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int time=curr.first;
            int node=curr.second;
            ctr++;
            t=time;
            for(int neigh:adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0){
                    pq.push({time+duration[neigh],neigh});
                }
            }
        }
        return (ctr==n) ? t:-1;
    }
};
