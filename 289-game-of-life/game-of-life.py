class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        
        def countNeighbours(r,c):
            nei=0
            for i in range(r-1,r+2):
                for j in range(c-1,c+2):
                    if((i==r and j==c) or i<0 or j<0 or i==rows or j==cols):
                        continue
                    if(board[i][j] in [1,3]):
                        nei+=1
            return nei;

        rows,cols=len(board),len(board[0])
        for r in range(rows):
            for c in range(cols):
                nei=countNeighbours(r,c)
                if board[r][c]==1:
                    if nei in [2,3]:
                        board[r][c]=3
                elif nei==3:
                        board[r][c]=2

        for r in range(rows):
            for c in range(cols):
                if(board[r][c]==1):
                    board[r][c]=0
                elif board[r][c] in [2,3]:
                    board[r][c]=1