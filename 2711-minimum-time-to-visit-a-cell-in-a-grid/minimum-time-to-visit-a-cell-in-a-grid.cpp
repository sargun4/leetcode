class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 &&j<n) 
            return true;
        return false;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //if both initial moves require > 1 sec, impossible togo fwd
        if(grid[0][1]>1 && grid[1][0]>1){
            return -1;
        }
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        //pq ordered by minimum time to reach each cell
        //dijkstras algo
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;//{time,row,col};
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int time=curr[0];
            int x=curr[1];
            int y=curr[2];
            //check if we reached bottom right cell
            if(x==m-1 && y==n-1){
                return time;
            }
            //skip if cell alr vis
            if(vis[x][y]){
                continue;
            }
            vis[x][y]=true;//now visited

            for(auto &d:dirns){
                int nr=x+d[0];
                int nc=y+d[1];
                if(!isvalid(nr,nc,m,n)){
                    continue;
                }
                //calc wait time req to move to next cell
                int waitTime;
                if((grid[nr][nc]-time)%2==0){
                    waitTime=1;//if even 
                }else{
                    waitTime=0;
                }
                int nextTime=max(grid[nr][nc]+waitTime,time+1);
                pq.push({nextTime,nr,nc});
            }
        }
        return -1;
    }
};