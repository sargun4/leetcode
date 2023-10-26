class Solution:  #//O(n*m)
    def solve(self, board: List[List[str]]) -> None:
        m,n=len(board),len(board[0])
        def capture(r,c): # we'll run this func only for the border O's
            if(r<0 or c<0 or r==m or c==n or board[r][c]!="O"):
                return
            board[r][c]="T"
            capture(r+1,c)
            capture(r-1,c)
            capture(r,c+1)
            capture(r,c-1)
        # dfs-capture unsurrounded regions (O->T) = O's on the borders
        for r in range(m):
            for c in range(n):
                if(board[r][c]=="O" and (r in [0,m-1] or c in [0,n-1])):
                    capture(r,c)   

        for r in range(m):
            for c in range(n):
                if board[r][c] == "O":   # capture surrounded regions (O->X); = O's not on the borders 
                    board[r][c] = "X" 

        for r in range(m):
            for c in range(n): 
                if board[r][c] == "T": # uncapture unsurrounded regions (T->O)
                    board[r][c] = "O" 
        
        