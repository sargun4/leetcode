from collections import deque
from typing import List
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n=len(grid)
        dirn=[[0,1],[0,-1],[1,0],[-1,0]]
        def invalid(r,c):
            return r<0 or c<0 or r==n or c==n
        visit=set()
        def dfs(r,c):
            if(invalid(r,c) or not grid[r][c] or (r,c) in visit):
                return
            visit.add((r,c))
            for dr,dc in dirn:
                dfs(r+dr,c+dc)
        def bfs():
            res,q=0,deque(visit)
            while(q):
                for i in range(len(q)):
                    r,c=q.popleft()
                    for dr,dc in dirn:
                        currow,curcol=r+dr,c+dc
                        if invalid(currow,curcol) or (currow,curcol) in visit:
                            continue
                        if(grid[currow][curcol]):
                            return res
                        q.append([currow,curcol])
                        visit.add((currow,curcol))
                res+=1
        for r in range(n):
            for c in range(n):
                if(grid[r][c]):
                    dfs(r,c)
                    return bfs()