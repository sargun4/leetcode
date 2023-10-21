
class Solution:
    mod=10**9+7
    def findCatalan(self, n : int) -> int:
        dp=[None]*(n+1)
        dp[0]=1
        for i in range(1,n+1):
            dp[i]=0
            for j in range(1,i+1):
                dp[i]=(dp[i]+dp[j-1]*dp[i-j])%self.mod
        return dp[n]



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.findCatalan(n)
        
        print(res)
        

# } Driver Code Ends