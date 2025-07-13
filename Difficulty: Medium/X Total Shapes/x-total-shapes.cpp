class Solution{
    public:
    //Function to find the number of 'X' total shapes.
    void f(int i , int j , vector<vector<char>> &grid , vector<vector<int>> &visited , int n , int m  ){
        if(i<0 || j < 0 || i>=n || j>=m || visited[i][j] != 0 || grid[i][j] == 'O' ) return;
        visited[i][j] = 1;
        f(i+1,j , grid,  visited , n , m );
        f(i-1 , j, grid,  visited , n , m );
        f(i,j-1, grid,  visited , n , m );
        f(i,j+1, grid,  visited , n , m );
    }
    int xShape(vector<vector<char>>& grid) {
        int ctr = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m,0));
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 'X' && !visited[i][j]){
                    ctr++;
                    f(i,j , grid  , visited , n , m );
                }
            }
        }
        return ctr;
    }
};