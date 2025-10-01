class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int nj=(j+k)%n; //(j+no of cols added)%m
                int ni=(i+(j+k)/n)%m; //(i+no of rows added)%n
                ans[ni][nj]=grid[i][j];
            }
        }
        return ans;
    }
};