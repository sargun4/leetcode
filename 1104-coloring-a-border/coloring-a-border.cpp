class Solution {
public:
//1st BFS : Get all the cells which have the same color ogColor. Thisll be the connected component we hv to consider
//2nd BFS : Identify which cells from the first BFS are on the border of the connected component. If the color of the child is different than parent, it means parent is a border cell. Similarly, if the parent itself is on the border of the grid, it is a border cell. Change the color of these border cells
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirns={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size(); int n=grid[0].size();
        int ogColor=grid[row][col];

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        queue<pair<int,int>> component;//stores all cells in curr connectd component
        
        q.push({row,col});
        vis[row][col]=true;
    //1st BFS to find all connected cells with the same color starting frm (row, col)
        while(!q.empty()){
            auto node=q.front(); q.pop();
            component.push(node);//saving curr cell in component
            int x=node.first;
            int y=node.second;
            for(auto&d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny,m,n) && !vis[nx][ny] && grid[nx][ny]==ogColor){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        //2nd BFS to identify n color the border cells of the component
        vis=vector<vector<bool>>(m, vector<bool>(n, false));

        while(!component.empty()){
            auto node=component.front(); 
            component.pop();
            int x=node.first;
            int y=node.second;
            vis[x][y]=true;
            //a cell is a border if it's on the grid boundary or adjacent to a diff color
            bool border=false;
            if(x==0||y==0||x==m-1||y==n-1){//boundary pts
                border=true;
            }
            //check if it's adjacent to any cell with a different color
            for(auto&d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                //if not valid or already part of the component, skip
                if(!isValid(nx,ny,m,n)) continue;
                if(vis[nx][ny]) continue;
                //either it's out of bounds or not part of the component                
                if(grid[nx][ny]!=ogColor){
                    border=true; 
                    break;
                }
            }
            //recolor only if its a border cell
            if(border){
                grid[x][y]=color;
            }
        }
        return grid;
    }
};