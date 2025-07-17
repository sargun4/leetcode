using p=pair<long long,int>;//{time,node}
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        //adj[i]={neigh,travel_time};
        for(auto &e:roads){
            int u=e[0]; int v=e[1]; int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        //minheap
        priority_queue<p,vector<p>,greater<>> pq;//{time,node}
        vector<long long> shortestTime(n,LLONG_MAX);//dist arr
        //no of ways to reach each node in shortest time
        vector<long long> pathCount(n,0);
        shortestTime[0]=0;
        pathCount[0]=1;//1 way to reach node 0
        pq.push({0,0});//
        while(!pq.empty()){
            auto [currtime,currnode]=pq.top(); pq.pop();
            // Skip outdated distances
            if (currtime>shortestTime[currnode]) continue;

//if traveling through curr node provides a shorter path(shortestTime[u]+wt) to a neighboring node than stored(shortestTime[v])
            for(auto &[neigh,roadtime]:adj[currnode]){
                //found a new shortest path, so update it and reset path count
                if(shortestTime[neigh]>currtime+roadtime){
                    shortestTime[neigh]=currtime+roadtime;
                    pathCount[neigh]=pathCount[currnode];
                    pq.push({shortestTime[neigh],neigh});
                }
                //found path w same shortest time- add to path count
                else if(currtime+roadtime==shortestTime[neigh]){
                    // Found another shortest path so add ways
                    pathCount[neigh]=(pathCount[currnode]+pathCount[neigh])%MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};