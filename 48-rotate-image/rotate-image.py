# class Solution:
#     def rotate(self, mat: List[List[int]]) -> None:
#         n=len(mat[0])
#         for row in range(n):
#             for col in range(row,n):
#                 mat[col][row],mat[row][col]=mat[row][col],mat[col][row]
#         for i in range(n):
#             mat[i].reverse()
#         return mat
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        #rev each row
        l = 0
        r = len(matrix)-1
        while l < r:
            matrix[l], matrix[r] = matrix[r], matrix[l]
            l += 1
            r -= 1
        #transpose
        n=len(matrix)
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        # print(matrix)
        