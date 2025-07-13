// User function Template for C++

class Solution {
public:
    bool isValid(int i, int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }  
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<char>>& mat){
        int m=mat.size(); int n=mat[0].size();
        vis[x][y]=1;
        for(auto d:dirns){
            int nx=x+d[0];
            int ny=y+d[1];
            //if in bounds, not yet vis and 'O'
            if(isValid(nx,ny,m,n) && !vis[nx][ny] && mat[nx][ny]=='O'){
                dfs(nx,ny,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(vector<vector<char>>& mat){
        int m=mat.size(); int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //firstly, mark all boundary cells, as vis
        for(int j=0;j<n;j++){
            if(!vis[0][j] && mat[0][j]=='O'){//1st row
                dfs(0,j,vis,mat);
            }
            if(!vis[m-1][j] && mat[m-1][j]=='O'){//last row
                dfs(m-1,j,vis,mat);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && mat[i][0]=='O'){//1st col
                dfs(i,0,vis,mat);
            }
            if(!vis[i][n-1] && mat[i][n-1]=='O'){//last col
                dfs(i,n-1,vis,mat);
            }
        }
        //now flip the remaining 'O's to 'X's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //unvis & internal 'O'
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};