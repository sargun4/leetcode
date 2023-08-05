class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visit=set()
        def dfs(r,c):
            if(r<0 or r==m or c<0 or c==n or grid[r][c]==0 or (r,c) in visit):
                return 0
            visit.add((r,c))
            return (1+ dfs(r+1,c)+dfs(r-1,c)+dfs(r,c+1)+dfs(r,c-1))
        area=0
        for r in range(m):
            for c in range(n):
                area=max(area,dfs(r,c))
        return area
# Time:     O(n * m),     Iterates through grid once.
# Space:    O(n * m),     Uses set to keep track of visited indices.
# # dfs
# class Solution:
# def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
#     row, col = len(grid), len(grid[0])
#     max_area = 0

#     def dfs(x,y):
#         cur_area= 1
#         for nx,ny in [[x+1,y],[x-1,y],[x,y+1],[x,y-1]]:
#             if 0<=nx<row and 0<=ny<col and grid[nx][ny]==1: 
#                 grid[nx][ny]=2
#                 cur_area += dfs(nx,ny)

#         return cur_area

#     for x in range(row):
#         for y in range(col):
#             if grid[x][y]==1:
#                 grid[x][y]=2
#                 max_area=max(max_area,dfs(x,y))

#     return max_area

# # bfs
# class Solution:
# def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
#     row, col = len(grid),len(grid[0])
#     queue, max_area = deque([]), 0
	
#     def bfs(queue):
#         cur_area = 1
#         while queue:
#             x,y = queue.popleft()
#             for nx, ny in [[x+1,y], [x-1,y], [x,y+1], [x,y-1]]:
#                 if 0<=nx<row and 0<=ny<col and grid[nx][ny]==1:
#                     grid[nx][ny]=2
#                     cur_area+=1
#                     queue.append((nx,ny))
#         return cur_area
    
#     for x in range(row):
#         for y in range(col):
#             if grid[x][y]==1:
#                 grid[x][y]=2
#                 queue.append((x,y))
#                 max_area = max(max_area,bfs(queue))
#     return max_area