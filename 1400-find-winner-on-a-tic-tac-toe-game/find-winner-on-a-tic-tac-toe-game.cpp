class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        //even indx for A- places X
        // odd index for B- places O
        vector<vector<char>> board(3,vector<char>(3,' '));
        int n=moves.size();
        for(int i=0;i<n;i++){
            vector<int> posn=moves[i];
            int x=posn[0];
            int y=posn[1];
            if(i%2==0){//A places X on board
                board[x][y]='X';
            }else{
                board[x][y]='O';
            }
        }
        // check rows n cols
        for(int i=0;i<3;i++){
            if(board[i][0]!=' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                if(board[i][0]=='X'){
                    return "A";
                }else{
                    return "B";
                }
            }
            if(board[0][i]!=' ' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
                if(board[0][i]=='X'){
                    return "A";
                }else{
                    return "B";
                }
            }
        }
        //check diagnols
        if(board[1][1]!=' ' &&
            ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) ||
             (board[0][2]==board[1][1] && board[1][1]==board[2][0]) )){
                return board[1][1]=='X' ? "A":"B";       
        }
        return moves.size()==9 ? "Draw" : "Pending";
    }
};