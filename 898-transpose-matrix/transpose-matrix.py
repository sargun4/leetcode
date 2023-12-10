# class Solution:
#     def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
#         for i in range(len(matrix)):
#             matrix[i]=matrix[i][::-1]#rev each row
#         #rotate by 90deg anticlockwise

# class Solution:
#     def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
#         return [[matrix[y][x] for y in range(len(matrix))] for x in range(len(matrix[0]))]

class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m,n=len(matrix),len(matrix[0])
        ans = [[0] * m for x in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][i]=matrix[i][j]
        
        return ans