class Solution:
    def kthGrammar(self,n: int, k: int) -> int:
        if n == 1:
            return 0
        # Calculate the midpoint of the previous row
        mid = 2 ** (n - 2)
        if k <= mid:
            # The kth symbol is in the first half of the previous row
            return self.kthGrammar(n - 1, k)
        else:
            # The kth symbol is in the second half of the previous row
            return 1 - self.kthGrammar(n - 1, k - mid)

# class Solution:
#     def kthGrammar(self, N, K):
#         if K == 1: return 0
#         if K & 1: return self.kthGrammar(N - 1, K // 2 + 1)
#         return self.kthGrammar(N - 1, K // 2) ^ 1


# #nrows
# def genjagged_arr(n):
#     jagged_arr = [[0]]
#     for i in range(1, n):
#         prevrow = jagged_arr[i-1]
#         new_row = []
#         for elmnt in prevrow:
#             if elmnt == 0:
#                 new_row.extend([0, 1])
#             elif elmnt == 1:
#                 new_row.extend([1, 0])
#         jagged_arr.append(new_row)
#     return jagged_arr

# # jagged_arr = genjagged_arr(n)
# # for row in jagged_arr:
# #     print(' '.join(str(elmnt) for elmnt in row))
