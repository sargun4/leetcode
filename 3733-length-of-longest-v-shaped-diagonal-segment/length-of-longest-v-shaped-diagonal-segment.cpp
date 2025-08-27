class Solution {
public:
    vector<vector<int>> dirns={{1,1},{1,-1},{-1,-1},{-1,1}};
    //next dirn got after rotating 90deg
    int m,n;
    int solve(int i,int j,int d,bool canTurn,int val,vector<vector<int>>&grid){
        int nx=i+dirns[d][0];
        int ny=j+dirns[d][1];
        if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]!=val){
            return 0;
        }
        //alt bw 2 and 0. if val is alr 2 then make it 0 to check for the next grid cell
        int ans=0;
        int keepMovingSameDirn=1+solve(nx,ny,d,canTurn, val == 2 ? 0:2 ,grid);
        ans=max(ans,keepMovingSameDirn);
        if(canTurn){
            int turnNmove=max(keepMovingSameDirn,1+solve(nx,ny,(d+1)%4,false,val == 2 ? 0:2 ,grid));
            ans=max(turnNmove,ans);
        }
        return ans; 
    }
    int lenOfVDiagonal(vector<vector<int>>& grid){
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){//start with 1
                    for(int d=0;d<4;d++){
                        ans=max(ans,1+solve(i,j,d,true,2,grid));
                        //canTurn=true- only once we can turn 90deg, start with 2
                    }
                }
            }
        }
        return ans;
    }
};