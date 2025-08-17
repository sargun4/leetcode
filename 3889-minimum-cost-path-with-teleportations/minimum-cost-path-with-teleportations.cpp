// Normal grid moves cost = cell values
// Teleports cost = 0 but consume 1 teleport
// Multi-state Dijkstra
// Sorting takes O(mn log(mn))
// Each cell processed ≤ k times = O(k·mn log(mn))
class Solution {
public:
    using t=tuple<int,int,int,int>;//{cost,i,j,usedTeleports_ctr}
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(); int n=grid[0].size();
        vector<tuple<int,int,int>> vals;
        //flatten cells into (val,r,c) tuples
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vals.push_back({grid[i][j],i,j});
            }
        }
        sort(vals.rbegin(),vals.rend());//largest to smallest;
//available[t] = list of teleport dests still usable when we hv t teleports left
        //available teleport destinations by "remaining teleports"
        vector<vector<tuple<int,int,int>>> available(k, vals);

        //store dists
        vector<vector<vector<int>>> dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX))); //{i,j,usedTeleports_ctr};
        dist[0][0][0]=0;
        priority_queue<t,vector<t>,greater<t>> pq;
        pq.push({0,0,0,0});
        while(!pq.empty()){
            auto [cost,i,j,t]=pq.top();
            pq.pop();
            if(cost!=dist[i][j][t]){//skip if not optimal
                continue;
            }
            if(i==m-1 && j==n-1){//reaced dest
                return cost;
            }
            if(i+1<m){
                int newcost=cost+grid[i+1][j];
                if(newcost< dist[i+1][j][t]){
                    dist[i+1][j][t]=newcost;
                    pq.push({dist[i+1][j][t],i+1,j,t});
                }
            }
            if(j+1<n){
                int newcost=cost+grid[i][j+1];
                if(newcost< dist[i][j+1][t]){
                    dist[i][j+1][t]=newcost;
                    pq.push({dist[i][j+1][t],i,j+1,t});
                }
            }
            
            if(t < k){ //can teleprt since we hv teleportsstill left
    //unlock teleport targets w val<=curr cell val
                while(!available[t].empty() && get<0>(available[t].back()) <= grid[i][j]){
                    auto [val, ni, nj] = available[t].back();
        //teleport cost = same as curr cost (free move)
                    if(cost < dist[ni][nj][t + 1]) {
                        dist[ni][nj][t + 1]=cost;
                        pq.push({cost,ni,nj,t+1});
                    }
                    available[t].pop_back();
                }
                //cleanup future lists
                for(int p=t+1;p<k;p++) {
                    while(!available[p].empty() && get<0>(available[p].back()) <= grid[i][j]) {
                        available[p].pop_back();
                    }
                }
            }
        }
        return -1;//dest unreacheble
    }
};