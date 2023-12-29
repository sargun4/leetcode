class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle=[]
        n=numRows
        for i in range(n):
            row=[1]*(i+1)
            for j in range(1,i):
                row[j]=triangle[i-1][j]+triangle[i-1][j-1]
            triangle.append(row)
        return triangle 
# # class Solution:
# #     def generate(self, numRows: int) -> List[List[int]]:
# #         finalNums=[]
# #         finalNums.append([1])
# #         for i in range(numRows-1):
# #             newRow=[1]
# #             for j in range(i):
# #                 newRow.append(finalNums[i][j]+finalNums[i][j+1])
# #             newRow.append(1)
# #             finalNums.append(newRow)
# #         return finalNums
# class Solution:
#     def generate(self, numRows: int) -> List[List[int]]:
#         list1=[]
#         for i in range(numRows):
#             level=[]
#             for j in range(i+1):
#                 if j==0 or j==i:
#                     level.append(1)
#                 else:
#                     level.append(list1[i-1][j-1]+list1[i-1][j])
#             list1.append(level)
#         return list1