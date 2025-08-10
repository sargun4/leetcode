class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid,int x,int y,int k){
        for(int i=0;i<k/2;i++){
            //the submatrix boundaries
            int top = x + i;
            int bottom = x + k - 1 - i;
            for(int j=y;j<y+k;j++){
                swap(grid[top][j], grid[bottom][j]);
            }
        }
        return grid;
    }
};