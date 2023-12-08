class Solution {
    public void gameOfLife(int[][] board) {
        int r=board.length;
        int c=board[0].length;
        int[][] copyboard=new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                copyboard[i][j]=board[i][j];
            }
        }
        int[] dx={1,1,0,-1,-1,-1,0,1};
        int[] dy={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int livecounts=0;
                for(int k=0;k<8;k++){
                    int nrow=i+dx[k];
                    int ncol=j+dy[k];
                    if(isSafe(nrow,ncol,r,c) && copyboard[nrow][ncol]==1){
                        livecounts++;
                    }
                }
                if(copyboard[i][j]==0 && livecounts==3){
                    board[i][j]=1;
                }if(copyboard[i][j]==1 && livecounts<2 || livecounts>3){
                    board[i][j]=0;
                }
            }
        }
    }
    private boolean isSafe(int x,int y,int r,int c){
        return (x>=0 && x<r && y>=0 && y<c);
    }
}
