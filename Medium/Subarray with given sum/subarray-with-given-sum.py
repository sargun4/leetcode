class Solution:
    def subArraySum(self, A, n, s): 
        current_sum = A[0]
        start = 0
    
        for end in range(1, n + 1):
            # Remove elements from the beginning until the sum is less than the s
            while current_sum > s and start < end - 1:
                current_sum -= A[start]
                start += 1
    
            # Check if the current window has the s
            if current_sum == s:
                return [start + 1, end]
    
            # Add the next element to the window
            if end < n:
                current_sum += A[end]

        return [-1]
            
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends