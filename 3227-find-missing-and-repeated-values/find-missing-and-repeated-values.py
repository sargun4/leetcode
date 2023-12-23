class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n=len(grid)
        l=[]
        for i in range(n):
            for j in range(n):
                l.append(grid[i][j])
        x=[]
        for i in range(1,n*n+1):
            if(l.count(i)==2):
                x.append(i) #a
        for i in range(1,n*n+1):
            if(i not in l):
                x.append(i) #b
        return x