//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<char>>& grid , vector<vector<bool>>&visited , int i , int j){
        int rows=grid.size();
        int column=grid[0].size();
        visited[i][j]=true;
        if(i-1 >= 0 && j+1 < column && grid[i-1][j+1]=='1' && visited[i-1][j+1]==false){
            dfs(grid , visited , i-1 , j+1);
        }
        if(i+1 < rows && j-1 >= 0 && grid[i+1][j-1]=='1' && visited[i+1][j-1]==false){
            dfs(grid , visited , i+1 , j-1);
        }
        if(i+1 < rows && j+1 < column && grid[i+1][j+1]=='1' && visited[i+1][j+1]==false){
            dfs(grid , visited , i+1 , j+1);
        }
        if(i+1 < rows && j < column && grid[i+1][j]=='1' && visited[i+1][j]==false){
            dfs(grid , visited , i+1 , j);
        }
        if(j+1 < column && grid[i][j+1]=='1' && visited[i][j+1]==false){
            dfs(grid , visited , i , j+1);
        }
        if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1]=='1' && visited[i-1][j-1]==false){
            dfs(grid , visited , i-1 , j-1);
        }
        if(i-1 >= 0  && grid[i-1][j]=='1' && visited[i-1][j]==false){
            dfs(grid , visited , i-1 , j);
        }
        if(j-1 >= 0 && grid[i][j-1]=='1' && visited[i][j-1]==false){
            dfs(grid , visited , i , j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int column = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(column,false));
        int ans=0;
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j< column ; j++){
                if(visited[i][j]==false && grid[i][j]=='1'){
                    dfs(grid , visited , i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends