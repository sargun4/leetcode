class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m=len(grid)
        n=len(grid[0])
        
        row=0
        row1s_arr=[]
        row0s_arr=[]
        while(row<m):
            row1s=0
            row0s=0
            for j in range(n):
                if(grid[row][j]==1):
                    row1s+=1
                else:
                    row0s+=1
            row1s_arr.append(row1s)
            row0s_arr.append(row0s)
            row+=1
        # print(row0s_arr,row1s_arr)
        col=0
        col1s_arr=[]
        col0s_arr=[]
        while(col<n):
            col1s=0
            col0s=0
            for i in range(m):
                if(grid[i][col]==1):
                    col1s+=1
                else:
                    col0s+=1
            col1s_arr.append(col1s)
            col0s_arr.append(col0s)
            col+=1
        # print(col0s_arr,col1s_arr)
        diff=[[0 for i in range(n)] for i in range(m)]
    
        for i in range(m):
            for j in range(n):
                diff[i][j]=(row1s_arr[i]-row0s_arr[i]) + (col1s_arr[j]- col0s_arr[j])
        
        return diff 