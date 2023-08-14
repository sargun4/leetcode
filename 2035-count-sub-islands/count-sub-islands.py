from typing import List
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m,n=len(grid1),len(grid1[0])
        visit=set()
        def dfs(r,c):
            #if out of bounds or grid2 cell is not island or already been visited
            if(r<0 or c<0 or r==m or c==n or grid2[r][c]==0 or (r,c) in visit):
                return True
            visit.add((r,c))
            res=True
            #not island cell
            if(grid1[r][c]==0):
                res=False
            #4 dirn
            res=dfs(r-1,c) and res
            res=dfs(r+1,c) and res
            res=dfs(r,c-1) and res
            res=dfs(r,c+1) and res
            return res
        ctr=0
        for r in range(m):
            for c in range(n):
                #if island cell and not yet been vis and dfs is true
                if(grid2[r][c]==1 and (r,c) not in visit and dfs(r,c)==True):
                    ctr+=1
        return ctr