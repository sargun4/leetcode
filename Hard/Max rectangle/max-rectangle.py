class Solution:
    def helper(self, heights):
        stack = []
        max_area = 0
        for index, height in enumerate(heights):
            start = index
            while stack and stack[-1][1] > height:
                i, h = stack.pop()
                max_area = max(max_area, h * (index - i))
                start = i
            stack.append([start, height])

        for i, h in stack:
            max_area = max(max_area, h * (len(heights) - i))
        return max_area

    def maxArea(self, M, n, m):
        max_area = 0
        h = [0 for _ in range(m)]
        for i in range(n):
            for j in range(m):
                if M[i][j] == 1:
                    h[j] += 1
                else:
                    h[j] = 0
            max_area = max(max_area, self.helper(h))
        return max_area

# class Solution:
#     def maxArea(self,M, n, m):
#         # code here
#         # Storing if current row is same as the previous row
#         sameHeightDiff={}
#         for j in range(len(M[0])):
#             for i in range(len(M)):
#                 if(i!=0 and i not in sameHeightDiff and M[i]==[1 for _ in range(len(M[0]))]):
#                     sameHeightDiff[i]=True
#                 M[i][j]=M[i][j] + M[i-1][j] if(i>0 and M[i][j]!=0 and M[i-1][j]!=0) else M[i][j]
                
#         prevSmallerLeft = None
#         prevSmallerRight = None
            
#         overallMaxSize = 0
#         for rowIndex, row in enumerate(M):
            
#             smallerLeft = [-1 for _ in range(len(row))]
#             smallerRight = [-1 for _ in range(len(row))]
            
#             if(rowIndex>0 and sameHeightDiff.get(rowIndex,False)):
#                 # Skipping computation
#                 smallerLeft = prevSmallerLeft
#                 smallerRight = prevSmallerRight
#             else:
#                 stack = []
#                 for i,x in enumerate(row):
#                     while(len(stack)>0 and stack[-1][1]>=x):
#                         stack.pop()
#                     if(len(stack)>0):
#                         smallerLeft[i]=stack[-1][0]
#                     stack.append((i,x))
            
#                 stack = []
#                 for i,x in enumerate(row):
#                     while(len(stack)>0 and stack[-1][1]>x):
#                         smallerRight[stack[-1][0]]=i
#                         stack.pop()
#                     stack.append((i,x))
                
#                 prevSmallerLeft = smallerLeft
#                 prevSmallerRight = smallerRight
            
#             maxSize = 0
#             for i,x in enumerate(row):
#                 left=smallerLeft[i]
#                 right=smallerRight[i] if(smallerRight[i]!=-1) else len(row)
#                 maxSize = max(maxSize, x*(right - left - 1))
#             overallMaxSize = max(maxSize, overallMaxSize)
            
#         return(overallMaxSize)

#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver Code 
if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        R,C = map(int, input().strip().split())
        A = []
        for i in range(R):
            line = [int(x) for x in input().strip().split()]
            A.append(line)
        print(Solution().maxArea(A, R, C)) 
	
# This code is contributed 
# by SHUBHAMSINGH10 

# } Driver Code Ends