class Solution:#O(n*2^n)
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        subset=[]
        def dfs(i): #i-index of nums list
            if i >=len(nums):
                res.append(subset.copy())
                return
            #decision to include nums[i]
            subset.append(nums[i])
            dfs(i+1)
            #decision not to include nums[i], backtracking
            subset.pop()
            dfs(i+1)
        dfs(0) #index 0 
        return res
    
