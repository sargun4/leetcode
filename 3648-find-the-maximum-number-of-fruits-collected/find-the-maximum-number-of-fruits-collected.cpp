class Solution {
public:
    int n;
    vector<vector<int>> dp;
    //child 1- Collects fruits along the main diag [i][i]
    int DiagChildCollect(vector<vector<int>>& fruits){
        int ctr=0;
        for(int i=0;i<n;i++){
            ctr+=fruits[i][i];//only diag collect
        }
        return ctr;
    }
    //child 2:Top right to bottom
    int child2Collect(int i,int j,vector<vector<int>>& fruits){
        if(i>=n || j<0 || j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;//dont collect cuz [n-1][n-1] was alr collectd by diag child
        }
        if(i==j || i>j){//diag or beyond it
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int bottomLeft=fruits[i][j]+child2Collect(i+1,j-1,fruits);
        int bottomDown=fruits[i][j]+child2Collect(i+1,j,fruits);
        int bottomRight=fruits[i][j]+child2Collect(i+1,j+1,fruits);

        return dp[i][j]= max({bottomLeft,bottomDown,bottomRight});
    }
    //child 3:bttoom left to right
    int child3Collect(int i, int j,vector<vector<int>>& fruits){
        if(i>=n || j<0 || j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;//cuz [n-1][n-1] was alr collectde by diag child
        }
        //skip diag or invalid region (child3)
        if(i==j || j>i){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int upRight=fruits[i][j]+child3Collect(i-1,j+1,fruits);
        int right=fruits[i][j]+child3Collect(i,j+1,fruits);
        int bottomRight=fruits[i][j]+child3Collect(i+1,j+1,fruits);

        return dp[i][j]=max({upRight,right,bottomRight});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        dp.resize(n,vector<int>(n,-1));
        int c1=DiagChildCollect(fruits);
        int c2=child2Collect(0,n-1,fruits);
        int c3=child3Collect(n-1,0,fruits);

        return c1+c2+c3;//total colectd
    }
};