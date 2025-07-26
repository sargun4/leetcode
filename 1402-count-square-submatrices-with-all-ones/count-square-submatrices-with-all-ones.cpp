//rec+memo
class Solution {
public:
    int m,n;
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i>=m || j>=n) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(i,j+1,matrix,dp);
        int diag=solve(i+1,j+1,matrix,dp);
        int down=solve(i+1,j,matrix,dp);

        return dp[i][j]= 1+min({right,diag,down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int res=0;//tot no of sq submatirces hving only 1s
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    res+=solve(i,j,matrix,dp);
                }
            }
        }
        return res;
    }
};
//Tabultion
// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,0));
//         for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
//         for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];
//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//                 if(matrix[i][j]==0)
//                     dp[i][j]=0;
//                 else if(matrix[i][j]==1)
//                     dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
//             }
//         }
//         int sum=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 sum+=dp[i][j];
//             }
//         }
//         return sum;
//     }
// };