#User function Template for python3

class Solution:
    def searchWord(self, grid, word):
        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < m

        def search_direction(x, y, dx, dy, word):
            for char in word:
                if not is_valid(x, y) or grid[x][y] != char:
                    return False
                x, y = x + dx, y + dy
            return True

        n, m = len(grid), len(grid[0])
        result_set = set()

        for i in range(n):
            for j in range(m):
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
                    if search_direction(i, j, dx, dy, word):
                        result_set.add((i, j))

        return sorted(result_set)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, m = input().split()
		n = int(n); m = int(m);
		grid = []
		for _ in range(n):
			cur  = input()
			temp = []
			for __ in cur:
				temp.append(__)
			grid.append(temp)
		word = input()
		obj = Solution()
		ans = obj.searchWord(grid, word)
		for _ in ans:
			for __ in _:
				print(__, end = " ")
			print()
		if len(ans)==0:
		    print(-1)

# } Driver Code Ends