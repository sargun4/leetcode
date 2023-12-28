
from typing import List
class Solution:
    def findAllPossiblePaths(self, n: int, m: int, grid: List[List[int]]) -> List[List[int]]:
        def solve(i, j):
            if i == n - 1 and j == m - 1:
                return [[grid[i][j]]]

            paths = []
            if i + 1 < n:
                paths.extend([[grid[i][j]] + path for path in solve(i + 1, j)])
            if j + 1 < m:
                paths.extend([[grid[i][j]] + path for path in solve(i, j + 1)])

            return paths
        return solve(0, 0)
        
#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=IntArray().Input(2)
        
        
        grid=IntMatrix().Input(a[0], a[1])
        
        obj = Solution()
        res = obj.findAllPossiblePaths(a[0],a[1], grid)
        
        IntMatrix().Print(res)
        

# } Driver Code Ends