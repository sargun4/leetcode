class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        # variables = [[39,3,1000,1000]]
        # target = 17

        n=len(variables)
        good_arr_indices=[]
        for i in range(n):
            # variables[i]=[ai, bi, ci, mi]
            #   0 <= i < variables.length
            # ((aibi % 10)ci) % mi == target
            if(0<=i<n):
                a,b,c,m=variables[i]
                if ((a**b%10)**c)%m==target:
                    good_arr_indices.append(i)
        return (good_arr_indices)
                