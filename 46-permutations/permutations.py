from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]
        if(len(nums)==1):
            return [nums[:]]
        for i in range(len(nums)):
            n=nums.pop(0)
            perms=self.permute(nums)
            for perm in perms:
                perm.append(n)
            res.extend(perms)
            nums.append(n)
        return res;
# class Solution:
#     def permute(self, l: List[int]) -> List[List[int]]:
#         def dfs(path, used, res):
#             if len(path) == len(l):
#                 res.append(path[:]) # note [:] make a deep copy since otherwise we'd be append the same list over and over
#                 return

#             for i, letter in enumerate(l):
#                 # skip used letters
#                 if used[i]:
#                     continue
#                 # add letter to permutation, mark letter as used
#                 path.append(letter)
#                 used[i] = True
#                 dfs(path, used, res)
#                 # remove letter from permutation, mark letter as unused
#                 path.pop()
#                 used[i] = False
            
#         res = []
#         dfs([], [False] * len(l), res)
#         return res