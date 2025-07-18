# class Solution:
#     def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
#         rows, cols = len(matrix), len(matrix[0])
#         r = 0
#         for i in range(rows):
#             if target >= matrix[i][0] and target <= matrix[i][-1]:
#                 r = i
#                 break
#         for i in range(cols):
#             if (matrix[r][i] == target):
#                 return True
#         return False
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        rows, cols = len(matrix), len(matrix[0])
        left, right = 0, rows * cols - 1
        while left <= right:
            mid = (left + right) // 2
            midval = matrix[mid // cols][mid % cols]
            if midval == target:
                return True
            elif midval < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
