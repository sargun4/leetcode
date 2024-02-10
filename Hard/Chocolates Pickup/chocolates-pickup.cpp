//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
#include <bits/stdc++.h>
using namespace std;
//tab
class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& grid){
        //int dp[n][m][m];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else  dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int r=-1;r<=1;r++){
                        for(int c=-1;c<=1;c++){
                            int val=0;
                            if(j1==j2) val=grid[i][j1];
                            else val=grid[i][j1]+grid[i][j2];
                            if(j1+r>=0 && j1+r<m && j2+c>=0 && j2+c<m)
                                val+=dp[i+1][j1+r][j2+c];
                            else
                                val+=-1e9;
                            maxi=max(maxi,val);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

// class Solution {
// public:
//     int f(int n,int m,int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
//         if(j1<0||j2<0||j1>=m||j2>=m){
//             return -1e8;
//         }
//         if(dp[i][j1][j2]!=-1){
//             return dp[i][j1][j2];
//         }
//         if(i==n-1){//reached last row
//             if(j1==j2){
//                 return grid[i][j1];
//             }else{
//                 return grid[i][j1]+grid[i][j2];
//             }
//         }
//         int maxi=-1e8;
//         for(int r=-1;r<=1;r++){
//             for(int c=-1;c<=1;c++){
//                 int val=0;
//                 if(j1==j2) val=grid[i][j1];
//                 else val=grid[i][j1]+grid[i][j2];
//                 val+=f(i+1,j1+r,j2+c,n,m,grid,dp);
//                 maxi=max(maxi,val);
//             }
//         }
//         return dp[i][j1][j2]=maxi;
//     }
//     int solve(int n, int m, vector<vector<int>>& grid){
//         //int dp[n][m][m];
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
//         return f(n-1,m-1,0,0,0,grid,dp);
//     }
// };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends