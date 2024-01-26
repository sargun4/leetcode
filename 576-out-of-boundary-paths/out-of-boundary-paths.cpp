#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int M,N;
    int MOD=1e9+7;
    vector<vector<int>> dirns{{0,1},{0,-1},{1,0},{-1,0}};
    int dp[51][51][51];
    int solve(int startRow,int startCol,int maxMove){
        if(startRow<0 || startRow>=M || startCol<0 || startCol>=N){
            return 1; //found 1 out of bound path
        } 
        if(maxMove<=0){
            return 0;
        }
        if(dp[startRow][startCol][maxMove]!=-1)
            return dp[startRow][startCol][maxMove];
        
        int res=0;
        for(vector<int>&dir:dirns){ //dfs
            int newR = startRow + dir[0];  
            int newC = startCol + dir[1];
            res = (res+ solve(newR,newC,maxMove-1))%MOD;
        }
        return dp[startRow][startCol][maxMove]=res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        M=m; N=n;
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startCol,maxMove);
    }
};