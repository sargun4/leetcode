class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //track min cost to reach each cell
        vector<vector<int>> mincost(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>> deque;
        deque.push_front({0,0});
        mincost[0][0]=0;
        //0-1 bfs- add 0 cost moves to front of deque and cost=1 to back
        while(!deque.empty()){
            auto [x,y]=deque.front();
            deque.pop_front();
            //4dirns
            for(int dir=0;dir<4;dir++){
                int nx=x+dirns[dir][0];
                int ny=y+dirns[dir][1];
                int cost=(grid[x][y] != (dir+1)) ? 1:0;
                //if posn is valid and its abetter path
                if(isValid(nx,ny,m,n) && mincost[x][y]+cost<mincost[nx][ny]){
                    mincost[nx][ny]=mincost[x][y]+cost;
                    //add to back incase cost=1
                    if(cost==1){
                        deque.push_back({nx,ny});
                    }else{//to front
                        deque.push_front({nx,ny});
                    }
                }
            }
        }
        return mincost[m-1][n-1];
    }
};