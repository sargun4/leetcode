class Solution {
    public List<List<String>> solveNQueens(int n) {
        char[][] board=new char[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(board[i],'.');
        }
        List<List<String>> res=new ArrayList<>();
        backtrack(n,board,0,res);
        return res;
    }
    private void backtrack(int n,char[][] board, int row, List<List<String>> res){
        if(row==n){
            res.add(constructboard(board));
            return ;
        }
        //try to place a queen in each column
        for(int col=0;col<n;col++){
            if(isSafe(n,board,row,col)){
                board[row][col]='Q';//place the queen
                backtrack(n,board,row+1,res);
                board[row][col]='.';//backtrack
            }
        }
    }
    private boolean isSafe(int n,char[][] board,int row,int col){
        for(int r=row-1;r>=0;r--)
            if(board[r][col]=='Q')
                return false;
        /*check main diagonal*/
        for(int r=row-1,c=col-1; r>=0 && c>=0; r--,c--)
            if(board[r][c]=='Q')
                return false;
        
        /* check anti diagonal*/
        for(int r=row-1,c=col+1; r>=0 && c<board.length; r--,c++)
            if(board[r][c]=='Q')
                return false;

        return true;
        
    }
    private List<String> constructboard(char[][] board){
        List<String> ans = new ArrayList<>();
        for (char[] arr : board) {
            ans.add(String.valueOf(arr));
        }
        return ans;
        }
}