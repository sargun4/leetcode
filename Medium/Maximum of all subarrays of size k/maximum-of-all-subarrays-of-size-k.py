
from collections import deque

class Solution:
    
    # Function to find maximum of each subarray of size k.
    def max_of_subarrays(self, arr, n, k):
        result = []
        dq = deque()

        # Process the first window separately
        for i in range(k):
            while dq and arr[i] >= arr[dq[-1]]:
                dq.pop()
            dq.append(i)

        # Process the remaining windows
        for i in range(k, n):
            result.append(arr[dq[0]])

            # Remove elements outside the current window
            while dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements from the back
            while dq and arr[i] >= arr[dq[-1]]:
                dq.pop()

            dq.append(i)

        result.append(arr[dq[0]])  # Append the maximum of the last window
        return result

# class Solution:
#     def max_of_subarrays(self,arr,n,k):
#         if(n==k):
#             return max(arr)
#         max_list=[]
#         for i in range(n):
#             for j in range(i+1,n):
#                 if(k==j-i+1 and j<n):
#                     l=arr[i:j+1]
#                     # print(l)
#                     x=max(l)
#                     # print(x)
#                     max_list.append(x)
#         return max_list

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys
from collections import deque

#Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,k = map(int,input().strip().split())
        arr = list(map(int,input().strip().split()))
        ob=Solution()
        res = ob.max_of_subarrays(arr,n,k)
        for i in range (len (res)):
            print (res[i], end = " ")
        print()
# } Driver Code Ends