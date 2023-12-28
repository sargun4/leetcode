class Solution: 
    def spirallyTraverse(self,matrix, r, c):  
        lst=[]
        left,right,top,bottom=0,c-1,0,r-1
        while left<=right and top<=bottom:
            for i in range(left,right+1):
                lst.append(matrix[top][i])
            top+=1
            for i in range(top,bottom+1):
                lst.append(matrix[i][right])
            right-=1
            if top<=bottom:
                for i in range(right,left-1,-1):
                    lst.append(matrix[bottom][i])
                bottom-=1
            if left<=right:
                for i in range(bottom,top-1,-1):
                    lst.append(matrix[i][left])
                left+=1
            
        return(lst)
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r,c = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(r):
            row=[]
            for j in range(c):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj = Solution()
        ans = obj.spirallyTraverse(matrix,r,c)
        for i in ans:
            print(i,end=" ")
        print()

# } Driver Code Ends