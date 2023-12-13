# class Solution:
#     def numSpecial(self, mat: List[List[int]]) -> int:
#         def get_column_sum(col_idx):
#             return sum(row[col_idx] for row in mat)

#         special = 0
#         for row in mat:
#             if sum(row) == 1:
#                 col_idx = row.index(1)
#                 special += get_column_sum(col_idx) == 1

#         return special
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0
        m = len(mat)
        n = len(mat[0])
        
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 0:
                    continue
                    
                good = True
                for r in range(m):
                    if r != row and mat[r][col] == 1:
                        good = False
                        break
                
                for c in range(n):
                    if c != col and mat[row][c] == 1:
                        good = False
                        break
                
                if good:
                    ans += 1
        
        return ans
