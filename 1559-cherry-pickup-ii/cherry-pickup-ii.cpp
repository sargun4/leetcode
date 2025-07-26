class Solution {
public:
    int m,n;
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& grid){
        m=grid.size(); //no of rows
        n=grid[0].size();//cols
        //dp[r][c1][c2]=max cherries collected till (r,c1) by R1 & (r,c2) by R2
        int dp[71][71][71]={0};
        if(n==1){//only 1 col, so both robots on same cell- 
            dp[0][0][n-1]=grid[0][0];//so add cherries only once
        }else{
            dp[0][0][n-1]=grid[0][0]+grid[0][n-1];
        }
        for(int row=1;row<m;row++){
            for(int c1=0;c1<=min(n-1,row);c1++){
                for(int c2=max(0,n-row-1);c2<n;c2++){
                    int prevRowMax=0;
                    //9 possibilites to reach to curr c1,c2
                    for(int prevCol1=max(0,c1-1);prevCol1<=min(n-1,c1+1);prevCol1++){//robot1
                        for(int prevCol2=max(0,c2-1);prevCol2<=min(n-1,c2+1);prevCol2++){//robot2
                            prevRowMax=max(prevRowMax,dp[row-1][prevCol1][prevCol2]);
                        }
                    }
                    dp[row][c1][c2];
                    if(c1==c2){
                        dp[row][c1][c2]=prevRowMax+grid[row][c1];
                    }else{
                        dp[row][c1][c2]=prevRowMax+grid[row][c1]+grid[row][c2];
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //r1 at (0,0), r2 at (0,n-1)
                res=max(res,dp[m-1][i][j]);
            }
        }
        return res;
    }
};


// //memo
// // T-O(m*n*n*9) 
// // S-O(m*n*n) fro 3d dp
// class Solution {
// public:
//     int m,n;
//     int dp[71][71][71];
//     int solve(vector<vector<int>>& grid,int r,int c1,int c2){
//         if(r>=m){//no cheries-since out of bounds
//             return 0;
//         }
//      dp[r][c1][c2]=max cherries collected till (r,c1) by R1 & (r,c2) by R2
//         if(dp[r][c1][c2]!=-1){
//             return dp[r][c1][c2];
//         }
//         int cherry=grid[r][c1];//for same cell
//         if(c1!=c2){//not same- so get both cherries frm diff cells in same row
//             cherry+=grid[r][c2];
//         }
//         int ans=0;
//         for(int i=-1;i<=1;i++){ //for robot1
//             for(int j=-1;j<=1;j++){ //for robot2
//                 int newr=r+1;
//                 int newc1=c1+i;
//                 int newc2=c2+j;
//                 if(newc1>=0 && newc1<n && newc2>=0 && newc2<n)//safe cols
//                     ans=max(ans,solve(grid,newr,newc1,newc2));
//             }
//         }
//         return dp[r][c1][c2]=cherry+ans;
//     }
//     int cherryPickup(vector<vector<int>>& grid){
//         m=grid.size(); //no of rows
//         n=grid[0].size();//cols
//         memset(dp,-1,sizeof(dp));
//         return solve(grid,0,0,n-1);//r1 at (0,0), r2 at (0,n-1)
//     }
// };