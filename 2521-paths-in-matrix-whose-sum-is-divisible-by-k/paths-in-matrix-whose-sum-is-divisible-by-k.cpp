class Solution {
public:
    int mod = 1e9 + 7, m, n, K;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size(), K = k;
        //dp[i][j][rem] = no of paths frm (i,j) with remainder rem
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return dfs(0, 0, 0, grid, dp);//start from (0,0) with sum = 0
    }
    int dfs(int i,int j,int sum,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        if(i==m||j==n) return 0;//out of bounds
        if(i==m-1 && j==n-1){//reached dest-check if final sum%k==0
            return ((sum+grid[i][j]) % K)==0;
        }
        if(dp[i][j][sum]!=-1) 
            return dp[i][j][sum];
        //update the new sum mod K
        int newSum = (sum + grid[i][j]) % K;
        //Down and Right paths rec
        int down = dfs(i+1,j,newSum,grid,dp);
        int right = dfs(i,j+1,newSum,grid,dp);
        //store n return res
        return dp[i][j][sum]=(down+right)%mod;
    }
};