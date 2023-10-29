class Solution {
    public int totalNQueens(int n) {
        char[][] board=new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }
        List<List<String>> ans=new ArrayList<>();
        nqueen(board,0,ans);
        return ans.size();
    }

    private boolean issafe(char[][] board, int row, int col) {
        int n=board.length;
        //check row
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q') return false;
        }
        //check col
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //check NE northeast
        int i=row; int j=col;
        while(i>=0&&j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        //check SE
        i=row; j=col;
        while(i<n && j<n){
            if(board[i][j]=='Q') return false;
            i++;
            j++;
        }
        //check SW
        i=row;j=col;
        while (i<n &&j>=0){
            if(board[i][j]=='Q' ) return false;
            i++;
            j--;
        }
        //check NW
        i=row;j=col;
        while (i>=0 &&j>=0){
            if(board[i][j]=='Q' ) return false;
            i--;
            j--;
        }
        return true;
    }
    private void nqueen(char[][] board, int row,List<List<String>>ans) {
        int n=board.length;
        if(row==n){//base case
           //copy 2D arr into list of strings
           List<String> l=new ArrayList<>();
           for(int i=0;i<n;i++){
               String str="";
               for(int j=0;j<n;j++){
                   str+=board[i][j];
               }
               l.add(str);
           }
           ans.add(l);
           return;
        }
        for(int j=0;j<n;j++){
            if(issafe(board,row,j)){
                board[row][j]='Q';
                nqueen(board,row+1,ans);
                //backtrack
                board[row][j]='.';
            }
        }
    }

}
