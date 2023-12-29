
import math
class Solution:
    def maxSubArraySum(self,arr,N): 
        max_sum = -math.inf
        curr_sum = 0
        for i in range(0,N):
            curr_sum += arr[i]
            if curr_sum > max_sum:
                max_sum = curr_sum
            if curr_sum < 0:
                curr_sum = 0
        return max_sum

# def maxSubArraySum(self,arr,n):
#     dp=[[0,0] for i in range(n)]
#     dp[0][1]=dp[0][0]=arr[0]
        
#     for i in range(1,n):
#         dp[i][0]=max(dp[i-1][0],arr[i],arr[i]+dp[i-1][1])
#         dp[i][1]=max(arr[i],arr[i]+dp[i-1][1])
#     return dp[n-1][0]
    
    
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends