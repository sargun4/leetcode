class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //minheap-{cost,row,col}
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0,0});
        //track min cost to reach each cell
        vector<vector<int>> mincost(m,vector<int>(n,INT_MAX));
        mincost[0][0]=0;
        //dijsktra
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int cost=curr[0];
            int x=curr[1];
            int y=curr[2];
            //if weve found a better path to this cell,skip
            if(mincost[x][y]!=cost) continue;
            //4dirns
            for(int dirn=0;dirn<4;dirn++){
                int nx=x+dirns[dirn][0];
                int ny=y+dirns[dirn][1];
                //if in bounds
                if(isValid(nx,ny,m,n)){
                    //add cost=1,incase we hv to change dirn of arrow
                    int newcost=cost+(dirn!=(grid[x][y]-1) ? 1:0);
                    //update if we got a better path
                    if(mincost[nx][ny]>newcost){
                        mincost[nx][ny]=newcost;
                        pq.push({newcost,nx,ny});
                    }
                }
            }
        }
        return mincost[m-1][n-1];
    }
};