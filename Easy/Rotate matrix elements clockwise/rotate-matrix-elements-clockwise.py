class Solution:
    def rotateMatrix(self, M, N, Mat):
        top = 0
        left = 0
        right = N-1
        bottom = M-1
        while top < bottom and left < right:
            prev = Mat[top+1][left]
            for i in range(left, right+1):
                cur = Mat[top][i]
                Mat[top][i] = prev
                prev = cur
            top += 1

            for i in range(top, bottom+1):
                cur = Mat[i][right]
                Mat[i][right] = prev
                prev = cur
            right -= 1

            for i in range(right, left-1, -1):
                cur = Mat[bottom][i]
                Mat[bottom][i] = prev
                prev = cur
            bottom -= 1

            for i in range(bottom, top-1, -1):
                cur = Mat[i][left]
                Mat[i][left] = prev
                prev = cur
            left += 1

        return Mat 

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        A=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            A.append(B)
        ob=Solution()
        ans=ob.rotateMatrix(N,M,A)
        for i in range(N):
            for j in range(M):
                print(ans[i][j],end=" ")
            print()    
# } Driver Code Ends