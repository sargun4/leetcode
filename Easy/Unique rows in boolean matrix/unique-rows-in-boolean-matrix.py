#User function Template for python3

from typing import List

class Solution:
    def uniqueRow(self, row : int, col : int, M : List[List[int]]) -> List[List[int]]:
        row=len(M)
        l=[]
        for i in range(row):
            l.append(M[i])
            
        # print(l)
        arr=[]
        for i in range(row):
            if l[i] not in arr:
                arr.append(l[i])
            else:
                pass
        
        return (arr)
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():
    testcase = int(input())
    while(testcase):
        s = input().split()
        row = int(s[0])
        col = int(s[1])
        matrix = [[None for _ in range(col)]for _ in range(row)]
        s = input().split()
        for i in range(row):
            for j in range(col):
                matrix[i][j] = int(s[i*col+j])
        
        ob = Solution()
        a = ob.uniqueRow(row, col, matrix)
        
        for row in a:
            for value in row:
                print(value,end = " ")
            print("$",end = "")
        print()
        testcase -= 1

if __name__ == "__main__":
    main()
# } Driver Code Ends