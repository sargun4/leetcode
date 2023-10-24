
class Solution {
    public boolean exist(char[][] board, String word) {
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(word.charAt(0)==board[i][j] && exist(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    private boolean exist(char[][] board, int x, int y,String word,int pos){
        if(pos==word.length()) return true;
        if(x<0 || y<0 || x>=board.length || y>=board[0].length){
            return false;
        }
        if(word.charAt(pos)!=board[x][y]) return false;
        char temp = board[x][y];    
        board[x][y]='*';
        if(exist(board, x+1, y, word, pos+1) 
        || exist(board, x-1, y, word, pos+1)
        || exist(board, x, y+1, word, pos+1)
        || exist(board, x, y-1, word, pos+1)) return true;
        //backtrack
        board[x][y]=temp;
        return false;
    }
}