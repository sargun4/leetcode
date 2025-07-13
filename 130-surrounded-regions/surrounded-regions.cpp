class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<char>>& board){
        int m=board.size(); int n=board[0].size();
        vis[x][y]=1;///mark cell as vis
        //4dirns
        for(auto d:dirns){
            int nx=x+d[0];
            int ny=y+d[1];
            //if in bounds & not yet vis cell hving 'O'
            if(isValid(nx,ny,m,n) && !vis[nx][ny] && board[nx][ny]=='O'){
                dfs(nx,ny,vis,board);//explore it
            }
        }
    }
    void solve(vector<vector<char>>& board){
        int m=board.size(); int n=board[0].size();
        if (m == 0 || n == 0) return;
        vector<vector<int>> vis(m,vector<int>(n,0));
        //first, get all boundary 0s and their connected 0s
        for(int j=0;j<n;j++){//trav 1st row n last row
            if(!vis[0][j] && board[0][j]=='O'){//1st row
                dfs(0,j,vis,board);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){//last row
                dfs(m-1,j,vis,board);
            }
        }
        for(int i=0;i<m;i++){//trav 1st col n last col
            if(!vis[i][0] && board[i][0]=='O'){//1st col
                dfs(i,0,vis,board);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){//last col
                dfs(i,n-1,vis,board);
            }
        }
        //flip all unvis 'O's to 'X's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //an internal O whoch ahdsnt been vis yet-convert it to X
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        // return board;
    }
};