class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle=[]
        n=rowIndex+1
        for i in range(n):
            row=[1]*(i+1)
            for j in range(1,i):
                row[j]=triangle[i-1][j]+triangle[i-1][j-1]
            triangle.append(row)
        return triangle[n-1] 