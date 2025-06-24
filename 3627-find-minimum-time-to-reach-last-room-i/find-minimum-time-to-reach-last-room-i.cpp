// class Solution {
// public:
//     bool isvalid(int i, int j, int n, int m){
//         if(i>=0 && i<n && j>=0 &&j<m) 
//             return true;
//         return false;
//     }
//     vector<vector<int>> dirns={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     int minTimeToReach(vector<vector<int>>& moveTime) {
//         int n=moveTime.size();
//         int m=moveTime[0].size();
//         //dp[i][j]=min time to reach cell (i, j)        
//         vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
//         // min heap
//         priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;//{time,x,y}
//         moveTime[0][0]=0;
//         pq.push({moveTime[0][0],0,0});
//         while(!pq.empty()){
//             auto curr=pq.top(); pq.pop();
//             int time=curr[0];
//             int x=curr[1];
//             int y=curr[2];
//             //if we alr found a shorter path to (x, y), skip it
//             if (time>=dp[x][y]) 
//                 continue;
//             dp[x][y]=time;
//             //check if we reached bottom right cell
//             if(x==n-1 && y==m-1){
//                 return time;
//             }
//             for(auto &d:dirns){//all 4dirns
//                 int nr=x+d[0];
//                 int nc=y+d[1];
//                 if(isvalid(nr,nc,n,m)){//in bound
//                     int nextTime=max(moveTime[nr][nc],time)+1;
//                     if(nextTime<dp[nr][nc]){//only if nexTime lesser than the one stored
//                         pq.push({nextTime,nr,nc});
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };



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
        //dp[i][j]=min time req to reach cell (i,j)
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;//{time,row,col}
        moveTime[0][0]=0;
        pq.push({moveTime[0][0],0,0});
        //dijkstra algo
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int time=curr[0];
            int x=curr[1];
            int y=curr[2];
            //if we alr found a shorter path(lesser time),skip it
            if(time>=dp[x][y]){
                continue;
            }
            dp[x][y]=time;
            //check if we alr bottomright cell
            if(x==n-1 && y==m-1){
                return time;
            }
            for(auto &d:dirns){//visit all 4dirns
                int nr=x+d[0];
                int nc=y+d[1];
                if(isvalid(nr,nc,n,m)){//in bounds
                    int nextTime=max(moveTime[nr][nc],time)+1;
                    if(nextTime < dp[nr][nc]) //if the nextTime is less than the one stored
                        pq.push({nextTime,nr,nc});
                }
            }
        }
        return -1;
    }
};