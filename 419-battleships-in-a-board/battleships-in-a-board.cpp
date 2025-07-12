class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& board){
        int m=board.size(); int n=board[0].size();
        //out of bounds or alr visited or water cell
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || board[i][j]!='X') return;
        vis[i][j]=1;//mark it as vis
        //explore 4 dirns
        dfs(i+1,j,vis,board);
        dfs(i-1,j,vis,board);
        dfs(i,j+1,vis,board);
        dfs(i,j-1,vis,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        //get no of connected components
        int m=board.size(); int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ctr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if its not water cell and not yet been vis
                if(board[i][j]=='X' && !vis[i][j]){
                    dfs(i,j,vis,board);
                    ctr++;//1 more ship found
                }
            }
        }
        return ctr;
    }
};