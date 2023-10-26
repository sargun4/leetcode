class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q=deque()
        m, n = len(grid), len(grid[0])
        time,fresh=0,0
        for r in range(m):
            for c in range(n):
                if(grid[r][c]==1):
                    fresh+=1
                if(grid[r][c]==2):
                    q.append([r,c])
        dirn=[[0,1],[0,-1],[1,0],[-1,0]]
        while(q and fresh>0):
            for i in range(len(q)):
                r,c=q.popleft()
                for dr,dc in dirn:
                    row,col=dr+r,dc+c
                    # if in bounds and fresh- then rot it
                    if(row<0 or row==len(grid) or col<0 or col==len(grid[0]) or grid[row][col]!=1):
                        continue
                    grid[row][col]=2
                    q.append([row,col])
                    fresh-=1
            time+=1
        return time if fresh==0 else -1
# # Similar Pattern Problems:
# # As Far from Land as Possible - https://leetcode.com/problems/as-far-from-land-as-possible/description/
# # Shortest Distance from All Buildings - https://leetcode.com/problems/shortest-distance-from-all-buildings/description/
# class Solution:
#     def orangesRotting(self, grid: List[List[int]]) -> int:
#         m, n = len(grid), len(grid[0])
#         visited = grid
#         q = collections.deque()
#         freshctr = 0
#         for i in range(m):
#             for j in range(n):
#                 if visited[i][j] == 2:
#                     q.append((i, j))
#                 if visited[i][j] == 1:
#                     freshctr += 1
#         if freshctr == 0:
#             return 0
#         if not q:
#             return -1
#         time = -1
#         dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
#         while q:
#             size = len(q)
#             while size > 0:
#                 x, y = q.popleft()
#                 size -= 1
#                 for dx, dy in dirs:
#                     i, j = x + dx, y + dy
#                     if 0 <= i < m and 0 <= j < n and visited[i][j] == 1:
#                         visited[i][j] = 2
#                         freshctr -= 1
#                         q.append((i, j))
#             time += 1
#         if freshctr == 0:
#             return time
#         return -1
# # from collections import deque
# # # T: O(m * n) -> each cell is visited at least once
# # # S: O(m * n) -> in the worst case if all the oranges are rotten they will be added to the queue
# # class Solution:
# #     def orangesRotting(self, grid: List[List[int]]) -> int:
# #         m = len(grid)
# #         if m == 0:  # check if grid is empty
# #             return -1        
# #         n = len(grid[0])
# #         # keep track of fresh oranges
# #         freshctr = 0
# #         # queue with rotten oranges (for BFS)
# #         rotten = deque()        
# #         # visit each cell in the grid
# #         for r in range(m):
# #             for c in range(n):
# #                 if grid[r][c] == 2:
# #                     # add the rotten orange coordinates to the queue
# #                     rotten.append((r, c))
# #                 elif grid[r][c] == 1:
# #                     # update fresh oranges count
# #                     freshctr += 1
# #         time = 0
# #         # If there are rotten oranges in the queue and there are still fresh oranges in the grid keep looping
# #         while rotten and freshctr > 0:
# #             # update the number of time passed
# #             # it is safe to update the time by 1, since we visit oranges level by level in BFS traversal.
# #             time += 1
# #             # process rotten oranges on the current level
# #             for _ in range(len(rotten)):
# #                 x, y = rotten.popleft()
# #                 # visit all the adjacent cells
# #                 for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
# #                     # calculate the coordinates of the adjacent cell
# #                     nrow, ncol = x + dx, y + dy
# #                     # ignore the cell if it is out of the grid boundary
# #                     if nrow < 0 or nrow == m or ncol < 0 or ncol == n:
# #                         continue
# #                     # ignore the cell if it is empty '0' or visited before '2'
# #                     if grid[nrow][ncol] == 0 or grid[nrow][ncol] == 2:
# #                         continue
# #                     # update the fresh oranges count
# #                     freshctr -= 1
# #                     # mark the current fresh orange as rotten
# #                     grid[nrow][ncol] = 2
# #                     # add the current rotten to the queue
# #                     rotten.append((nrow, ncol))
# #         # return the number of time taken to make all the fresh oranges to be rotten
# #         # return -1 if there are fresh oranges left in the grid (there were no adjacent rotten oranges to make them rotten)
# #         return time if freshctr == 0 else -1
