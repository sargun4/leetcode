//make directed weighted graph frm special roads
class Solution {
public:
//coords- nodes in graph
//edges- special roads
//Dijkstra-finding the shortest/min cost path in a directed graph.
    int ManhtnDist(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx=start[0], sy=start[1], tx=target[0], ty=target[1];
        map<pair<int,int>,int> dist;//{{x,y}:mindist}
        dist[{sx,sy}]=0;
        //filtered list of roads that have cost less than their manhattan
        vector<vector<int>> filteredRoads;
        //directed edge frm (x1,y1)to(x2,y2) with wt=cost
        for(auto &road:specialRoads){
            int x1 = road[0], y1 = road[1];
            int x2 = road[2], y2 = road[3];
            int cost = road[4];
            if(cost < ManhtnDist(x1,y1,x2,y2)){//special road cost lesser/better than actual dist
                filteredRoads.push_back({x1,y1,x2,y2,cost});
                dist[{x2,y2}]=ManhtnDist(sx,sy,x2,y2);
            }
        }
        //dijkstra-minheap to get min dist
        using T=tuple<int, int, int>;
        priority_queue<T,vector<T>,greater<>> pq;//{dist,x,y}
        pq.push({0,sx,sy});
        while(!pq.empty()){
            auto [currCost,x,y]=pq.top(); pq.pop();
            //if we already visited (x, y) with a better cost, skip it
            if(currCost > dist[{x,y}]) continue;
            //move via each filtered special road
            for(auto&road:filteredRoads){
                int x1 = road[0], y1 = road[1];
                int x2 = road[2], y2 = road[3];
                int cost = road[4];
//totalCost: move from (x,y) to (x1,y1) normally + take special road to (x2,y2)
                int totalCost=currCost+ManhtnDist(x,y,x1,y1)+cost;
            //if this path improves dist to (x2,y2), update and add to pq
                if (totalCost < dist[{x2,y2}]) {
                    dist[{x2,y2}]=totalCost;
                    pq.push({totalCost,x2,y2});
                }
            }
        }
        //now we hv minmost dist to reach every end pt of spcl roads 
        int ans=ManhtnDist(sx,sy,tx,ty);
        //min ans is either direct Manhattan or best cost via a special road
        for (auto &[p, d]:dist){
            int x=p.first, y=p.second;
            int totalCost=d+ManhtnDist(x, y, tx, ty);
            ans=min(ans,totalCost);
            // cout<<dist[{c,d}]<<"\n";
        }
        return ans;
    }
};