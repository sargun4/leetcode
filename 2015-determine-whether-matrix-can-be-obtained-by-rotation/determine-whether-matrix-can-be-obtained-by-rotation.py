class Solution:
    def rotate(self, matrix: List[List[int]]):
        #rev each row
        l = 0
        r = len(matrix)-1
        while l < r:
            matrix[l], matrix[r] = matrix[r], matrix[l]
            l += 1
            r -= 1
        #transpose
        n=len(matrix)
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        return(matrix)
    def findRotation(self, mat: List[List[int]], target: List[List[int]])-> bool:
        for i in range(4):
            rotated_mat=self.rotate(mat)
            if(rotated_mat==target):
                return True
        return False