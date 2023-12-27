# class Solution:
#     def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
#         m=len(mat)
#         n=len(mat[0])
#         row=0
#         col=0
#         l=[]
#         while(row<m):
#             res=[]
#             i=0
#             j=0
#             while(i+row<m and j<n):
#                 res.append(mat[i+row][j])
#                 i+=1
#                 j+=1
#             l.append(res)
#             row+=1
#             print(l)
       
#         while(col<n-1):
#             res=[]
#             i=0
#             j=1
#             while(i<m and j+col<n):
#             # for k in range(col):
#                 res.append(mat[i][j+col])
#                 i+=1
#                 j+=1
#             l.append(res)
#             col+=1
#             print(l)
#         # for i in l:
#         #     i.sort()
#         # print(l)
#         return l



# from typing import List

# class Solution:
#     def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
#         m, n = len(mat), len(mat[0])
#         diagonals = {}

#         for i in range(m):
#             for j in range(n):
#                 if i - j not in diagonals:
#                     diagonals[i - j] = []
#                 diagonals[i - j].append(mat[i][j])

#         for diagonal in diagonals.values():
#             diagonal.sort()

#         for i in range(m):
#             for j in range(n):
#                 mat[i][j] = diagonals[i - j].pop(0)

#         return mat


class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
 
        l = []
        for i in range(m):
            for j in range(n):
                diag_diff = i - j
                l.append([diag_diff, mat[i][j]])

        #grping elmnt by diag diff in a dict
        d = {}
        for pair in l:
            key = pair[0]
            val = pair[1]
            if key not in d:
                d[key] = [val]
            else:
                d[key].append(val)

        #sort the arrays in dict based on diag diff 
        arr = sorted(d, reverse=True)
        sortedarrs = [sorted(d[i]) for i in arr]

        #update res matrix with the sorted elements
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                diag_diff = i - j
                for k in range(len(arr)):
                    if diag_diff == arr[k]:
                        res[i][j] = sortedarrs[k].pop(0)

        return res


