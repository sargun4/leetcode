class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res=[] #list of list
        part=[]
        def dfs(i):
            if i>=len(s):
                res.append(part.copy())
                return
            for j in range(i, len(s)):
                if self.isPalindrome(s,i,j):
                    part.append(s[i:j+1])
                    dfs(j+1)
                    part.pop()
        dfs(0)
        return res
    def isPalindrome(self,s,start,end):
        while start<end:
            if s[start]!=s[end]:
                return False
            start+=1
            end-=1
        return True
            
        