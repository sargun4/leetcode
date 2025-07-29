// First, it iterates through the given matrix to mark obstacles (0s) and their adjacent cells as visited (-1s).
// Then, it initializes a queue to perform BFS and a boolean matrix to keep track of visited cells.
// Next, it starts BFS from the leftmost column. If there's a clear path (1) in the leftmost column, it pushes its coordinates
// and the step count (initialized as 1) into the queue.
// During BFS, it dequeues the front element and explores its neighboring cells (up, down, and right) if they are within the bounds
// of the matrix, are clear paths (1), and haven't been visited before. For each valid neighbor, it increments the step count and pushes its coordinates into the queue.
// The process continues until the queue becomes empty or until the rightmost column is reached. If the rightmost column is reached, it 
// returns the step count as the shortest path. If the queue becomes empty before reaching the rightmost column, it means there's no clear path from the leftmost to the rightmost column, so it returns -1
using p=pair<pair<int,int>,int>;
class Solution {
public:
    int n, m;
    //up, down, left, right
    vector<vector<int>> dirns = {{-1,0},{1,0},{0,-1},{0,1}};
    //check bounds
    bool isValid(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    //find shortest safe path
    int findShortestPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size(); 
        //Step 1: Mark unsafe cells-0s and their neighs as vis(-1)
        vector<vector<int>> unsafe=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    for(auto&d:dirns){
                        int ni=i+d[0];
                        int nj=j+d[1];
                        if(isValid(ni,nj) && mat[ni][nj]==1){
                            unsafe[ni][nj]=-1;//mark unsafe cell
                        }
                    }
                }
            }
        }
        //Step 2: BFS from all safe cells in the first column
        queue<p> q; // {row, col, distance}
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        //start BFS from all safe 1st col cells
        for(int i=0;i<n;i++){
            if(unsafe[i][0]==1){
                q.push({{i,0},1}); //start at {{row=i,col= 0},dist = 1} 
                vis[i][0]=true;
            }
        }
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x=curr.first.first;
            int y=curr.first.second;
            int steps=curr.second;
            vis[x][y]=true;
            if(y==m-1){//if reached rightmost col, return step count;
                return steps;
            }
            for(auto&d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny) && !vis[nx][ny] && unsafe[nx][ny]==1){
                    vis[nx][ny]=true;
                    q.push({{nx,ny},steps+1});
                }
            }
        }
        return -1;//no valid path found
    }
};
