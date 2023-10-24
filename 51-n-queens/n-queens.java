class Solution {
    public List<List<String>> solveNQueens(int n) {
        char[][] chess = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                chess[i][j] = '.';
            }
        }
        List<List<String>> res = new ArrayList<List<String>>();

        solve(res, chess, 0);
        return res;
    }
    private void solve(List<List<String>> res, char[][] chess, int row) {
        if (row == chess.length) {
            res.add(construct(chess));
            return;
        }
        for (int col = 0; col < chess.length; col++) {
            if (valid(chess, row, col)) {
                chess[row][col] = 'Q';
                solve(res, chess, row + 1);
                chess[row][col] = '.';
            }
        }
    }
    private boolean valid(char[][] chess, int row, int col) {
        // check all cols
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') {
                return false;
            }
        }
        //check 45 degree
        for (int i = row - 1, j = col + 1; i >= 0 && j < chess.length; i--, j++) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        //check 135
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    private List<String> construct(char[][] chess) {
        List<String> path = new ArrayList<>();
        for (int i = 0; i < chess.length; i++) {
            path.add(new String(chess[i]));
        }
        return path;
    }
}

// class Solution {
//     private boolean issafe(char[][] board, int row, int col) {
//         int n=board.length;
//         //check row
//         for(int j=0;j<n;j++){
//             if(board[row][j]=='Q') return false;
//         }
//         //check col
//         for(int i=0;i<n;i++){
//             if(board[i][col]=='Q') return false;
//         }
//         //check NE northeast
//         int i=row; int j=col;
//         while(i>=0&&j<n){
//             if(board[i][j]=='Q') return false;
//             i--;
//             j++;
//         }
//         //check SE
//         i=row; j=col;
//         while(i<n && j<n){
//             if(board[i][j]=='Q') return false;
//             i++;
//             j++;
//         }
//         //check SW
//         i=row;j=col;
//         while (i<n &&j>=0){
//             if(board[i][j]=='Q' ) return false;
//             i++;
//             j--;
//         }
//         //check NW
//         i=row;j=col;
//         while (i>=0 &&j>=0){
//             if(board[i][j]=='Q' ) return false;
//             i--;
//             j--;
//         }
//         return true;
//     }
//     private void nqueen(char[][] board, int row,List<List<String>>ans) {
//         int n=board.length;
//         if(row==n){//base case
//            //copy 2D arr into list of strings
//            List<String> l=new ArrayList<>();
//            for(int i=0;i<n;i++){
//                String str="";
//                for(int j=0;j<n;j++){
//                    str+=board[i][j];
//                }
//                l.add(str);
//            }
//            ans.add(l);
//            return;
//         }
//         for(int j=0;j<n;j++){
//             if(issafe(board,row,j)){
//                 board[row][j]='Q';
//                 nqueen(board,row+1,ans);
//                 //backtrack
//                 board[row][j]='.';
//             }
//         }
//     }
//     public List<List<String>> solveNQueens(int n) {
//         char[][] board=new char[n][n];
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 board[i][j]='.';
//             }
//         }
//         List<List<String>> ans=new ArrayList<>();
//         nqueen(board,0,ans);
//         return ans;
//     }
// }


// class Solution {
//     public List<List<String>> solveNQueens(int n) {
//         char[][] board=new char[n][n];
//         for(int i=0;i<n;i++){
//             Arrays.fill(board[i],'.');
//         }
//         List<List<String>> res=new ArrayList<>();
//         backtrack(n,board,0,res);
//         return res;
//     }
//     private void backtrack(int n,char[][] board, int row, List<List<String>> res){
//         if(row==n){
//             res.add(constructboard(board));
//             return ;
//         }
//         //try to place a queen in each column
//         for(int col=0;col<n;col++){
//             if(isSafe(n,board,row,col)){
//                 board[row][col]='Q';//place the queen
//                 backtrack(n,board,row+1,res);
//                 board[row][col]='.';//backtrack
//             }
//         }
//     }
//     private boolean isSafe(int n,char[][] board,int row,int col){
//         for(int r=row-1;r>=0;r--)
//             if(board[r][col]=='Q')
//                 return false;
//         /*check main diagonal*/
//         for(int r=row-1,c=col-1; r>=0 && c>=0; r--,c--)
//             if(board[r][c]=='Q')
//                 return false;
        
//         /* check anti diagonal*/
//         for(int r=row-1,c=col+1; r>=0 && c<board.length; r--,c++)
//             if(board[r][c]=='Q')
//                 return false;

//         return true;
        
//     }
//     private List<String> constructboard(char[][] board){
//         List<String> ans = new ArrayList<>();
//         for (char[] arr : board) {
//             ans.add(String.valueOf(arr));
//         }
//         return ans;
//         }
// }