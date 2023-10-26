class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0
            
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1
        return count

    def dfs(self, grid, i, j):
        if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j] != '1':
            return
        grid[i][j] = '#'
        self.dfs(grid, i+1, j)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i, j-1)
 
# class Solution:
#     def numIslands(self, grid: List[List[str]]) -> int:
#         if not grid:
#             return 0
#         rows,cols=len(grid),len(grid[0])
#         vis=set()
#         islands=0
#         def bfs(r,c):
#             q=collections.deque()
#             vis.add((r,c))
#             q.append((r,c))
#             while(q):
#                 row,col=q.popleft()
#                 dirn=[[1,0],[-1,0],[0,1],[0,-1]]
#                 for dr,dc in dirn:
#                     r,c=row+dr,col+dc
#                     if(r in range(rows) and
#                        c in range(cols) and
#                        grid[r][c]=="1" and
#                        (r,c) not in vis):
#                         q.append((r,c))
#                         vis.add((r,c))
        
#         for r in range(rows):
#             for c in range(cols):
#                 if(grid[r][c]=="1" and (r,c) not in vis):
#                     bfs(r,c)
#                     islands+=1
#         return islands