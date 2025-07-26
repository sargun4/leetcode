//memo T-O(n^3)
// S-O(n^2):2d dp
class Solution {  
public:
    //dp[i][j]=min falling path sum frm row i to row n-1 when jth col chosen in ith row
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int col=0;col<n;col++){
            dp[n-1][col]=mat[n-1][col];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                int ans=INT_MAX;
                for(int nextCol=0;nextCol<n;nextCol++){
                    if(nextCol!=col){
                        ans=min(ans,dp[row+1][nextCol]);
                    }
                }
                dp[row][col]=mat[row][col]+ans;
            }
        }
        int res=INT_MAX;
        for(int col=0;col<n;col++){
            res=min(res,dp[0][col]);
        }
        return res;
    }
};
// //memo T-O(n^3)
// // S-O(n^2):2d dp
// class Solution {  
// public:
//     int n;
//     int dp[201][201];
//     int solve(int col,int row,vector<vector<int>>&mat){
//         if(row==n-1){
//             return mat[row][col];
//         }
//         if(dp[row][col]!=-1){
//             return dp[row][col];
//         }
//         int ans=INT_MIN;
//         for(int nextcol=0;nextcol<n;nextcol++){
//             if(nextcol!=col){//nextcol shdnt be = curr col
//                 ans=min(ans,solve(nextcol,row+1,mat));
//             }
//         }
//         return dp[row][col]=ans+mat[row][col];
//     }
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         n=mat.size();
//         memset(dp,-1,sizeof(dp));
//         int res=INT_MAX;
//         for(int col=0;col<n;col++){//choose the col to start with
//             res=min(res,solve(col,0,mat));
//         }
//         return res;
//     }
// };