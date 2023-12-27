#User function Template for python3

# class Solution:
#     def sortedMatrix(self,N,Mat):
#         # N=len(Mat)
#         arr=[]
#         for i in range(N):
#             for j in range(N):
#                 arr.append(Mat[i][j])
#         # print(arr)
#         l=sorted(arr)
#         # print(l) 
#         for i in range(N):
#             for j in range(N):
#                 Mat[i][j]=(l.pop(0))
#         return(Mat)

class Solution:
    def sortedMatrix(self,N,Mat):
        k,ans=0,[]
        for i in Mat: ans.extend(i)
        ans.sort()
        for i in range(N):
            for j in range(N):
                Mat[i][j]=ans[k]
                k+=1
        return Mat
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        v=[]
        for i in range(N):
            a=list(map(int,input().strip().split()))
            v.append(a)
        ob=Solution()
        ans=ob.sortedMatrix(N,v)
        for i in range(N):
            for j in range(N):
                print(ans[i][j],end=" ")
            print()
# } Driver Code Ends