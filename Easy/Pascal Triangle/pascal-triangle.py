mod=10**9+7
class Solution:
    def nthRowOfPascalTriangle(self, N):
        triangle = []
        for i in range(N + 1):
            row = [1] * (i + 1)
            for j in range(1, i):
                row[j] = (triangle[i - 1][j - 1] + triangle[i - 1][j]) % mod
            triangle.append(row)
        # print(triangle)
        for i in range(len(triangle)):
            if i == N - 1:
                return list(map(int, triangle[i]))
 
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

	tc=int(input())
	while tc > 0:
	    n=int(input())
	    ob = Solution()
	    ans=ob.nthRowOfPascalTriangle(n)
	    for x in ans:
	        print(x, end=" ")
	    print()
	    tc=tc-1
# } Driver Code Ends