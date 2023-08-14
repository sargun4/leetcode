from collections import deque
from typing import List
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        length=len(board)
        board.reverse()
        def intToPosition(cell):
            r=(cell-1)//length
            c=(cell-1)%length
            if(r%2):
                c=length-1-c
            return [r,c]
        q=deque()
        q.append([1,0]) #[cell,moves]
        visit=set()
        while(q):
            cell,moves=q.popleft()
            for i in range(1,7):
                nextcell=cell+i
                r,c=intToPosition(nextcell)
                if(board[r][c]!=-1):
                    nextcell=board[r][c]
                if nextcell==length*length:
                    return moves+1
                if nextcell not in visit:
                    visit.add(nextcell)
                    q.append([nextcell,moves+1])
        return -1
