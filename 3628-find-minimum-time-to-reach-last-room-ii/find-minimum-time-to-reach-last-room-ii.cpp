class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();//rows
        int m=moveTime[0].size();//cols
        //dp[i][j][flag]=min time req to reach (i,j) cell with the flag alt bw 1/2 secs
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,INT_MAX)));//3d
        //flag- to alternate bw 1sec and 2secs
        using T=tuple<int,int,int,int>;//{time,x,y,flag};
        priority_queue<T,vector<T>,greater<>> pq;//min heap
        int startTime=max(0,moveTime[0][0]);
        pq.push({0,0,0,1});
        dp[0][0][1]=startTime;
        while(!pq.empty()){
            auto [time,x,y,flag]=pq.top(); pq.pop();
            // int time=curr[0];
            // int x=curr[1];
            // int y=curr[2];
            // int flag=curr[3];
            if(time>dp[x][y][flag]){
                continue;
            }
            // dp[x][y][flag]=time;
            if(x==n-1 && y==m-1){//reached bottom right cell
                return time;
            }
            int movecost=flag ? 1:2;
            for(auto &d:dirns){
                int nr=x+d[0];
                int nc=y+d[1];
                if(isvalid(nr,nc,n,m)){
                    // nextTime=max(nextTime,moveTime[nr][nc])+1;
                    int waitTime = max(time, moveTime[nr][nc]);  // wait first
                    int nextTime = waitTime + movecost; 
                    int nextStep=1-flag;
                    if(nextTime<dp[nr][nc][nextStep]){
                        dp[nr][nc][nextStep]=nextTime;
                        pq.push({nextTime,nr,nc,nextStep});
                    }
                }
            }
        }
        return -1;
    }
};