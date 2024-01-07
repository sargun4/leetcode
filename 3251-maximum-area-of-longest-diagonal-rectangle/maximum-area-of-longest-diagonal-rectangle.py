from math import sqrt
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        # dimensions = [[9,3],[8,6]]
        n=len(dimensions)
        diags=[]
        for i in range(n):
            l=dimensions[i][0]
            w=dimensions[i][1]
            diag=sqrt(l*l+w*w)
            diags.append([l,w,diag])

        maxlen = diags[0][2]
        maxarea = diags[0][0] * diags[0][1]
        for i in range(1, n):
            if diags[i][2] > maxlen or (diags[i][2] == maxlen and diags[i][0] * diags[i][1] > maxarea):
                maxlen = diags[i][2]
                maxarea = diags[i][0] * diags[i][1]
        return(maxarea)
                