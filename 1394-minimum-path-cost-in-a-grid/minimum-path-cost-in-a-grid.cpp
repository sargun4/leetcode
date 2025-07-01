class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,INT_MAX));
        //minheap for dijkstra- {cost,x,y};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        //push all cells/nodes in the 1st row to pq
        for(int j=0;j<n;j++){
            pq.push({grid[0][j],0,j});
        }
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int cost=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(x==m-1){//reached final row
                return cost;
            }
            for(int dy=0;x+1<m && dy<n;dy++){
                //moveCost[val][dy] is the extra cost to move to column dy in the next row n add that to the val of cell we move to, i.e. grid[x+1][dy]
                int newcost=cost+moveCost[grid[x][y]][dy]+grid[x+1][dy];
                if(newcost<vis[x+1][dy]){//if newcost cheaper than prev,push into pq
                    vis[x+1][dy]=newcost;
                    pq.push({newcost,x+1,dy});
                }
            }
        }
        return -1;
    }
};