# class Solution:
#     def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
#         rows, cols = len(matrix), len(matrix[0])
#         for i in range(rows):
#             for j in range(cols):
#                 if(target==matrix[i][j]):
#                     return True
#         return False

class Solution:
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:  
        m=len(mat)
        n=len(mat[0])        
        i=m-1
        j=0        
        while i>=0 and j<n:
            if mat[i][j]==target:
                return True
            elif mat[i][j]<target:
                j+=1
            else:
                i-=1                
        return False
# class Solution:
#     def searchMatrix(self, mat: List[List[int]], target: int) -> bool:        
#         m=len(mat)
#         n=len(mat[0])
#         for i in range(m):
#             if mat[i][0]<=target and mat[i][-1]>=target:
#                 lo=0
#                 hi=n
#                 while (lo<hi):
#                     mid=(lo+hi)//2                
#                     if mat[i][mid]==target:
#                         return True
#                     elif mat[i][mid]<target:
#                         lo = mid + 1
#                     else:
#                         hi = mid                        
#         return False