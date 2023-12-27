#User function Template for python3

class Solution:
    def antiDiagonalPattern(self,matrix):
        n = len(matrix)
        l = []
        
        # Create a list of pairs [diagonal_sum, [i, j]]
        for i in range(n):
            for j in range(n):
                diagonal_sum = i + j
                l.append([diagonal_sum, [i, j]])
        
        # print("Original list:", l)
        
        # Group elements based on their first elements
        grouped_dict = {}
        for pair in l:
            key = pair[0]
            value = pair[1]
            if key in grouped_dict:
                grouped_dict[key].append(value)
            else:
                grouped_dict[key] = [value]
        
        # Convert the dictionary items to a list
        grouped_list = list(grouped_dict.items())
        
        # print("Grouped list:", grouped_list)
        
        arr = []
        for i in range(len(grouped_list)):
            indices = grouped_list[i][1]
            elements = [matrix[idx[0]][idx[1]] for idx in indices]
            arr.append(elements)
        
        # print("Resulting array:", arr)
        
        ans=[]
        for i in arr:
            for j in i:
                ans.append(j)
        return (ans)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input()) 
        inp=list(map(int,input().split()))
        matrix=[]
        k = 0
        for i in range(n):
            row = []
            for j in range(n):
                row.append(inp[k])
                k += 1
            matrix.append(row)
        ob = Solution()
        ans = ob.antiDiagonalPattern(matrix)
        for i in ans:
            print(i,end=" ")
        print()


# } Driver Code Ends