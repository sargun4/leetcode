class neighborSum {
public:
    vector<vector<int>> grid;
    int n;
    neighborSum(vector<vector<int>>& g) {
        grid=g;
        n=grid.size();
    }
    
    int adjacentSum(int value) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    int l=(j>0)? grid[i][j-1]:0;
                    int r=(j<n-1)? grid[i][j+1]:0;
                    int u=(i>0)? grid[i-1][j]:0;
                    int d=(i<n-1)? grid[i+1][j]:0;
                    return l+r+u+d;
                }
            }
        }
        return -1;
    }
    int diagonalSum(int value) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    int lu=(i>0 && j>0)? grid[i-1][j-1]:0;
                    int rd=(i<n-1 && j<n-1)? grid[i+1][j+1]:0;
                    int ld=(i<n-1 && j>0)? grid[i+1][j-1]:0;
                    int ru=(i>0 && j<n-1)? grid[i-1][j+1]:0;
                    return lu+rd+ld+ru;
                }
            }
        }
        return -1;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */