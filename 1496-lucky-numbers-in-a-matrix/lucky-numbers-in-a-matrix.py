import copy
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        l=[]
        for i in range(len(matrix)):
            minelmnt=min(matrix[i])
            col=(matrix[i]).index(minelmnt)
            l.append([col,minelmnt])
            # for j in range(len(matrix[0])):
        # print(l)
        # a=[]
        a = copy.deepcopy(l) #to store original lsit l
        # print(a)
        for i in range(len(matrix)):
            for k in range(len(matrix)):
                if(matrix[k][(l[i][0])]>l[i][1]): #mat[i][colidx], l[i][1]->minelmnt for each row
                    l[i][1]=matrix[k][(l[i][0])]
                else:
                    pass
        # print(l)
        # print(a)
        for i in range(len(matrix)):
            if(l[i][1]==a[i][1]):
                return [a[i][1]]

