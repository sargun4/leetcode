class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        res=[]
        left,right=0,len(matrix[0])
        top,bottom=0,len(matrix)
        while(left<right and top<bottom):
            for j in range(left,right):
                res.append(matrix[top][j])
            top+=1
            for i in range(top,bottom):
                res.append(matrix[i][right-1])
            right-=1
            if not(left<right and top<bottom):
                break
            for j in range(right-1,left-1,-1):
                res.append(matrix[bottom-1][j])
            bottom-=1
            for i in range(bottom-1,top-1,-1):
                res.append(matrix[i][left])
            left+=1
        return res
            
# class Solution:
#     def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
#         if not matrix:
#             return []
#         rowbegin=0
#         rowend=len(matrix)
#         colbegin=0
#         colend=len(matrix[0])
#         res=[]
#         while rowend>rowbegin and colend>colbegin:
#             for i in range(colbegin,colend):
#                 res.append(matrix[rowbegin][i])
#             for i in range(rowbegin+1,rowend-1):
#                 res.append(matrix[i][colend-1])
#             if rowend !=rowbegin+1:
#                 for i in range(colend-1,colbegin-1,-1):
#                     res.append(matrix[rowend-1][i])
#             if colbegin!=colend-1:
#                 for i in range(rowend-2,rowbegin,-1):
#                     res.append(matrix[i][colbegin])
#             rowbegin+=1
#             rowend-=1
#             colbegin+=1
#             colend-=1
#         return res