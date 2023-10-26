# You are given a m x n 2D grid initialized with these three possible values.

# -1 - A wall or an obstacle.
# 0 - A gate.
# INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
# Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

from collections import deque
class Solution: #bfs-O(m*n)
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    def walls_and_gates(self, rooms: List[List[int]]):
        rows,cols=len(rooms),len(rooms[0])
        visit=set()
        q=deque()
        def addroom(r,c):
            if (r<0 or r==rows or c<0 or c==cols or (r,c) in visit or rooms[r][c]==-1):
                return 
            visit.add((r,c))
            q.append([r,c])
        for r in range(rows):
            for c in range(cols):
                if(rooms[r][c]==0):
                    q.append([r,c])
                    visit.add((r,c))
        dist=0
        while q:
            for i in range(len(q)):
                r,c=q.popleft()
                rooms[r][c]=dist
                addroom(r+1,c)
                addroom(r-1,c)
                addroom(r,c+1)
                addroom(r,c-1)
            dist+=1
